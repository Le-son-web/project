/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnOn;
    QPushButton *btnOff;
    QPushButton *btnDisconnect;
    QLabel *labelStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnOn = new QPushButton(centralwidget);
        btnOn->setObjectName("btnOn");
        btnOn->setGeometry(QRect(90, 180, 161, 71));
        btnOff = new QPushButton(centralwidget);
        btnOff->setObjectName("btnOff");
        btnOff->setGeometry(QRect(450, 180, 161, 71));
        btnDisconnect = new QPushButton(centralwidget);
        btnDisconnect->setObjectName("btnDisconnect");
        btnDisconnect->setGeometry(QRect(260, 350, 181, 101));
        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(300, 320, 101, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnOn->setText(QCoreApplication::translate("MainWindow", "On", nullptr));
        btnOff->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
