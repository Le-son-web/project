#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BluetoothComm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConnect_clicked();
    void on_btnOn_clicked();
    void on_btnOff_clicked();
    void on_btnDisconnect_clicked();
    void updateStatus(QString deviceId);
    void handleError(QString errorMsg);

private:
    Ui::MainWindow *ui;
    BluetoothComm *bt;
};

#endif // MAINWINDOW_H
