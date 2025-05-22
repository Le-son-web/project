#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bt(new BluetoothComm(this))
{
    ui->setupUi(this);
    connect(bt, &BluetoothComm::SignalBTConnected, this, &MainWindow::updateStatus);
    connect(bt, &BluetoothComm::ReceiveDataError, this, &MainWindow::handleError);
}

MainWindow::~MainWindow() {
    delete ui;
    delete bt;
}

void MainWindow::on_btnConnect_clicked() {
    bt->setConnectionDetail(QString("RaspberryPi"));  // Replace with your device name
    bt->connectToHost();
}

void MainWindow::on_btnOn_clicked() {
    char data = '1';
    bt->SendCmd(0x01, 1, &data);
}

void MainWindow::on_btnOff_clicked() {
    char data = '0';
    bt->SendCmd(0x01, 1, &data);
}

void MainWindow::on_btnDisconnect_clicked() {
    bt->disconnectFromHost();
    ui->labelStatus->setText("Disconnected");
}

void MainWindow::updateStatus(QString deviceId) {
    ui->labelStatus->setText("Connected to " + deviceId);
}

void MainWindow::handleError(QString errorMsg) {
    ui->labelStatus->setText("Error: " + errorMsg);
}
