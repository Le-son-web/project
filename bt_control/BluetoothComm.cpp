// #include "BluetoothSocketComm.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>

// Constants for frame structure
#define FRAME_START_BYTE 0xAA
#define FRAME_END_BYTE 0x55
#define FRAME_HEADER_SIZE 4  // Start byte + Command + Length + CRC
#define MAX_FRAME_SIZE 1024
#define ACK_TIMEOUT 3000     // 3 seconds timeout for acknowledgment
#define MAX_RETRIES 3

BluetoothSocketCommunicate::BluetoothSocketCommunicate(QWidget *parent) : QWidget(parent),
    m_receiveBuffer(),
    m_sendQueue(),
    m_currentSendingFrame(nullptr),
    m_currentSendSize(0),
    m_retryCount(0),
    m_isWaitingForAck(false)
{
    // Initialize Bluetooth socket
    p_BluetoothSocket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);

    // Initialize local Bluetooth device
    m_localDevice = new QBluetoothLocalDevice(this);

    // Connect signals and slots for socket
    connect(p_BluetoothSocket, &QBluetoothSocket::stateChanged,
            this, &BluetoothSocketCommunicate::socketStateChanged);
    connect(p_BluetoothSocket, QOverload<QBluetoothSocket::SocketError>::of(&QBluetoothSocket::error),
            this, &BluetoothSocketCommunicate::displayError);

    // Initialize acknowledge timer
    m_ackTimer = new QTimer(this);
    connect(m_ackTimer, &QTimer::timeout, this, &BluetoothSocketCommunicate::handleAckTimeout);

    // Initialize send queue processor timer
    m_queueTimer = new QTimer(this);
    connect(m_queueTimer, &QTimer::timeout, this, &BluetoothSocketCommunicate::processSendQueue);
    m_queueTimer->start(50); // Check queue every 50ms
}

BluetoothSocketCommunicate::~BluetoothSocketCommunicate()
{
    if (p_BluetoothSocket->isOpen())
        p_BluetoothSocket->close();

    delete p_BluetoothSocket;
    delete m_localDevice;
    delete m_ackTimer;
    delete m_queueTimer;

    // Clean up any pending send frames
    clearSendQueue();
}

void BluetoothSocketCommunicate::clearSendQueue()
{
    while (!m_sendQueue.isEmpty()) {
        FrameData* frame = m_sendQueue.dequeue();
        delete[] frame->data;
        delete frame;
    }

    if (m_currentSendingFrame) {
        delete[] m_currentSendingFrame->data;
        delete m_currentSendingFrame;
        m_currentSendingFrame = nullptr;
    }
}

void BluetoothSocketCommunicate::setConnectionAddress(QString address)
{
    conn_Address = address;
}

bool BluetoothSocketCommunicate::IsOpen()
{
    return (p_BluetoothSocket->state() == QBluetoothSocket::ConnectedState);
}

void BluetoothSocketCommunicate::enableConnection(bool bState)
{
    if (bState)
    {
        connect(p_BluetoothSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
        m_queueTimer->start(50);
    }
    else
    {
        disconnect(p_BluetoothSocket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
        m_queueTimer->stop();
        m_ackTimer->stop();
        clearSendQueue();
    }
}

void BluetoothSocketCommunicate::connectToController()
{
    if (!p_BluetoothSocket->isOpen()) {
        // Check if Bluetooth is available and enabled
        if (m_localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff) {
            QMessageBox::warning(this, "Bluetooth Error", "Bluetooth is turned off. Please turn it on.");
            return;
        }

        // Connect using MAC address
        p_BluetoothSocket->connectToService(QBluetoothAddress(conn_Address), QBluetoothUuid::SerialPort);

        if (p_BluetoothSocket->waitForConnected(5000)) {
            QMessageBox::information(this, "Connect Status", "Connected successfully");
        }
        else {
            QMessageBox::warning(this, "Connection Error", "Connection timeout");
        }
    }
}

void BluetoothSocketCommunicate::disconnectFromController()
{
    m_ackTimer->stop();
    m_queueTimer->stop();
    clearSendQueue();
    p_BluetoothSocket->disconnectFromService();
    p_BluetoothSocket->close();
}

void BluetoothSocketCommunicate::socketStateChanged(QBluetoothSocket::SocketState state)
{
    switch (state) {
    case QBluetoothSocket::ConnectedState:
        qDebug() << "Socket connected";
        enableConnection(true);
        emit SignalBTconnected(conn_Address);
        break;
    case QBluetoothSocket::UnconnectedState:
        qDebug() << "Socket disconnected";
        enableConnection(false);
        break;
    default:
        break;
    }
}

void BluetoothSocketCommunicate::displayError(QBluetoothSocket::SocketError error)
{
    QString errorMessage;

    switch (error) {
    case QBluetoothSocket::ConnectionRefusedError:
        errorMessage = "Connection refused by device";
        break;
    case QBluetoothSocket::RemoteHostClosedError:
        errorMessage = "Remote device closed the connection";
        break;
    case QBluetoothSocket::HostNotFoundError:
        errorMessage = "Device not found";
        break;
    case QBluetoothSocket::ServiceNotFoundError:
        errorMessage = "Service not found on device";
        break;
    default:
        errorMessage = "Unknown Bluetooth error";
        break;
    }

    QMessageBox::warning(this, "Connection Error", errorMessage);
}

void BluetoothSocketCommunicate::dataReceived()
{
    try {
        // Append newly received data to our buffer
        QByteArray newData = p_BluetoothSocket->readAll();
        m_receiveBuffer.append(newData);

        // Process buffer to extract complete frames
        processReceivedData();
    }
    catch (std::exception &e) {
        emit ReceiveDataError(e.what());
    }
}

void BluetoothSocketCommunicate::processReceivedData()
{
    // Continue processing while we might have a complete frame
    while (m_receiveBuffer.size() >= FRAME_HEADER_SIZE) {
        // Look for start byte
        int startPos = m_receiveBuffer.indexOf(FRAME_START_BYTE);
        if (startPos == -1) {
            // No start byte found, clear buffer and return
            m_receiveBuffer.clear();
            return;
        }

        // If start byte is not at beginning, remove preceding garbage
        if (startPos > 0) {
            m_receiveBuffer.remove(0, startPos);
        }

        // Now buffer starts with start byte, check if we have enough data to read the header
        if (m_receiveBuffer.size() < FRAME_HEADER_SIZE) {
            // Not enough data for header, wait for more
            return;
        }

        // Read header information
        unsigned char cmd = m_receiveBuffer.at(1);
        unsigned char length = m_receiveBuffer.at(2);

        // Check if we have the full frame
        int expectedFrameSize = FRAME_HEADER_SIZE + length + 1; // +1 for end byte
        if (m_receiveBuffer.size() < expectedFrameSize) {
            // Not enough data for the complete frame, wait for more
            return;
        }

        // We have a complete frame, check CRC
        unsigned char receivedCRC = m_receiveBuffer.at(3);
        unsigned char calculatedCRC = CalcCRC(cmd, length,
                                              reinterpret_cast<unsigned char*>(m_receiveBuffer.data() + FRAME_HEADER_SIZE));

        // Check end byte
        unsigned char endByte = m_receiveBuffer.at(expectedFrameSize - 1);

        if (receivedCRC == calculatedCRC && endByte == FRAME_END_BYTE) {
            // Valid frame, extract payload
            QByteArray payload = m_receiveBuffer.mid(FRAME_HEADER_SIZE, length);

            // Handle acknowledgments
            if (cmd == 0x01) { // ACK command
                handleAcknowledgment(payload);
            } else {
                // Process regular data frame
                emit ReceivedData(payload);

                // Send acknowledgment
                sendAcknowledgment(cmd);
            }
        } else {
            qDebug() << "Frame validation failed: CRC or end byte incorrect";
        }

        // Remove processed frame from buffer
        m_receiveBuffer.remove(0, expectedFrameSize);
    }
}

void BluetoothSocketCommunicate::sendAcknowledgment(unsigned char originalCmd)
{
    // Prepare and send an ACK frame
    unsigned char ackData[1] = {originalCmd};
    SendFrameWithCommand(0x01, ackData, 1, false); // ACK doesn't need acknowledgment
}

void BluetoothSocketCommunicate::handleAcknowledgment(const QByteArray &payload)
{
    // Process received acknowledgment
    if (m_isWaitingForAck && m_currentSendingFrame) {
        unsigned char ackCmd = payload.at(0);

        // Check if this ACK is for the current frame
        if (ackCmd == m_currentSendingFrame->command) {
            // ACK received for current frame
            m_ackTimer->stop();
            m_isWaitingForAck = false;

            // Clean up current frame
            delete[] m_currentSendingFrame->data;
            delete m_currentSendingFrame;
            m_currentSendingFrame = nullptr;

            // Reset retry count for next frame
            m_retryCount = 0;

            // Emit signal that data was acknowledged
            emit DataSent(true);
        }
    }
}

void BluetoothSocketCommunicate::handleAckTimeout()
{
    if (m_isWaitingForAck && m_currentSendingFrame) {
        if (m_retryCount < MAX_RETRIES) {
            // Retry sending the frame
            m_retryCount++;
            qDebug() << "Retrying send, attempt" << m_retryCount;

            // Send the frame again
            actualSendFrame(m_currentSendingFrame->data, m_currentSendSize);

            // Restart the ACK timer
            m_ackTimer->start(ACK_TIMEOUT);
        } else {
            // Max retries reached, consider transmission failed
            qDebug() << "Send failed after maximum retries";
            m_isWaitingForAck = false;

            // Clean up current frame
            delete[] m_currentSendingFrame->data;
            delete m_currentSendingFrame;
            m_currentSendingFrame = nullptr;

            // Reset retry count
            m_retryCount = 0;

            // Emit signal that send failed
            emit DataSent(false);
        }
    }
}

void BluetoothSocketCommunicate::processSendQueue()
{
    // If not waiting for an ACK and there are frames to send
    if (!m_isWaitingForAck && !m_sendQueue.isEmpty()) {
        // Get the next frame from the queue
        m_currentSendingFrame = m_sendQueue.dequeue();

        // Send the frame
        m_currentSendSize = FRAME_HEADER_SIZE + m_currentSendingFrame->length + 1; // +1 for end byte
        actualSendFrame(m_currentSendingFrame->data, m_currentSendSize);

        // If this frame requires acknowledgment
        if (m_currentSendingFrame->requiresAck) {
            // Set up acknowledgment waiting
            m_isWaitingForAck = true;
            m_retryCount = 0;
            m_ackTimer->start(ACK_TIMEOUT);
        } else {
            // No acknowledgment needed, clean up immediately
            delete[] m_currentSendingFrame->data;
            delete m_currentSendingFrame;
            m_currentSendingFrame = nullptr;
            emit DataSent(true);
        }
    }
}

void BluetoothSocketCommunicate::actualSendFrame(unsigned char* data, unsigned char size)
{
    if (p_BluetoothSocket->isWritable()) {
        qint64 bytesWritten = p_BluetoothSocket->write((const char*)data, size);

        if (bytesWritten != size) {
            qDebug() << "Warning: Not all bytes were written to the socket";
        }
    } else {
        qDebug() << "Error: Socket is not writable";
        emit DataSent(false);
    }
}

unsigned char BluetoothSocketCommunicate::CalcCRC(unsigned char uCode, unsigned char uSize, unsigned char* buffer)
{
    unsigned char uCRC = 0;
    unsigned short uSum = 0;
    uSum += uSize;
    uSum += uCode;  // Include command in CRC calculation
    for (unsigned char uNo = 0; uNo < uSize; uNo++)
        uSum += buffer[uNo];
    uCRC = (unsigned char)(uSum & 0xFF); // Low Byte of nSum
    uCRC += (unsigned char)(uSum >> 8);  // High Byte of nSum
    return uCRC;
}

void BluetoothSocketCommunicate::SendFrame(unsigned char* puBuffer, unsigned char hLen)
{
    // For backward compatibility, assume command 0x00 and requireAck=true
    SendFrameWithCommand(0x00, puBuffer, hLen, true);
}

void BluetoothSocketCommunicate::SendFrameWithCommand(unsigned char command, unsigned char* payload,
                                                      unsigned char length, bool requireAck)
{
    if (!IsOpen()) {
        emit DataSent(false);
        return;
    }

    // Prepare complete frame: [START][CMD][LEN][CRC][PAYLOAD][END]
    unsigned char totalSize = FRAME_HEADER_SIZE + length + 1; // +1 for end byte
    unsigned char* frameData = new unsigned char[totalSize];

    // Fill header
    frameData[0] = FRAME_START_BYTE;
    frameData[1] = command;
    frameData[2] = length;
    frameData[3] = CalcCRC(command, length, payload);

    // Copy payload
    memcpy(frameData + FRAME_HEADER_SIZE, payload, length);

    // Add end byte
    frameData[totalSize - 1] = FRAME_END_BYTE;

    // Create and queue the frame
    FrameData* frame = new FrameData;
    frame->data = frameData;
    frame->length = length;
    frame->command = command;
    frame->requiresAck = requireAck;

    m_sendQueue.enqueue(frame);

    // Queue processor will handle the actual sending
}
