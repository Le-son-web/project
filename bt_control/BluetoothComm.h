#ifndef BLUETOOTHSOCKETCOMM_H
#define BLUETOOTHSOCKETCOMM_H

#include <QWidget>
#include <QBluetoothSocket>
#include <QBluetoothLocalDevice>
#include <QByteArray>
#include <QQueue>
#include <QTimer>

// Frame data structure for send queue
struct FrameData {
    unsigned char* data;
    unsigned char length;
    unsigned char command;
    bool requiresAck;
};

class BluetoothSocketCommunicate : public QWidget
{
    Q_OBJECT

public:
    explicit BluetoothSocketCommunicate(QWidget *parent = nullptr);
    ~BluetoothSocketCommunicate();

    // Connection functions
    void setConnectionAddress(QString address);
    bool IsOpen();
    void connectToController();
    void disconnectFromController();

    // Data transmission functions
    void SendFrame(unsigned char* puBuffer, unsigned char hLen); // Legacy method
    void SendFrameWithCommand(unsigned char command, unsigned char* payload,
                              unsigned char length, bool requireAck = true);

private:
    QBluetoothSocket* p_BluetoothSocket;
    QBluetoothLocalDevice* m_localDevice;
    QString conn_Address;

    // Buffer management
    QByteArray m_receiveBuffer;
    QQueue<FrameData*> m_sendQueue;
    FrameData* m_currentSendingFrame;
    unsigned char m_currentSendSize;

    // Acknowledgment management
    QTimer* m_ackTimer;
    QTimer* m_queueTimer;
    int m_retryCount;
    bool m_isWaitingForAck;

    // Helper functions
    void enableConnection(bool bState);
    void processReceivedData();
    void sendAcknowledgment(unsigned char originalCmd);
    void handleAcknowledgment(const QByteArray &payload);
    void actualSendFrame(unsigned char* data, unsigned char size);
    unsigned char CalcCRC(unsigned char uCode, unsigned char uSize, unsigned char* buffer);
    void clearSendQueue();

signals:
    void ReceivedData(const QByteArray &data);
    void ReceiveDataError(QString errorMessage);
    void DataSent(bool success);
    void SignalBTConnected(QString deviceId);
private slots:
    void dataReceived();
    void socketStateChanged(QBluetoothSocket::SocketState state);
    void displayError(QBluetoothSocket::SocketError error);
    void handleAckTimeout();
    void processSendQueue();
};

#endif // BLUETOOTHSOCKETCOMM_H
