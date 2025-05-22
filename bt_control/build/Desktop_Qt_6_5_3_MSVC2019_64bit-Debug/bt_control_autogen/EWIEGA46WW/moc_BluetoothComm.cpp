/****************************************************************************
** Meta object code from reading C++ file 'BluetoothComm.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../BluetoothComm.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BluetoothComm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS = QtMocHelpers::stringData(
    "BluetoothSocketCommunicate",
    "ReceivedData",
    "",
    "data",
    "ReceiveDataError",
    "errorMessage",
    "DataSent",
    "success",
    "SignalBTConnected",
    "deviceId",
    "dataReceived",
    "socketStateChanged",
    "QBluetoothSocket::SocketState",
    "state",
    "displayError",
    "QBluetoothSocket::SocketError",
    "error",
    "handleAckTimeout",
    "processSendQueue"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[27];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[17];
    char stringdata5[13];
    char stringdata6[9];
    char stringdata7[8];
    char stringdata8[18];
    char stringdata9[9];
    char stringdata10[13];
    char stringdata11[19];
    char stringdata12[30];
    char stringdata13[6];
    char stringdata14[13];
    char stringdata15[30];
    char stringdata16[6];
    char stringdata17[17];
    char stringdata18[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS_t qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 26),  // "BluetoothSocketCommunicate"
        QT_MOC_LITERAL(27, 12),  // "ReceivedData"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 4),  // "data"
        QT_MOC_LITERAL(46, 16),  // "ReceiveDataError"
        QT_MOC_LITERAL(63, 12),  // "errorMessage"
        QT_MOC_LITERAL(76, 8),  // "DataSent"
        QT_MOC_LITERAL(85, 7),  // "success"
        QT_MOC_LITERAL(93, 17),  // "SignalBTConnected"
        QT_MOC_LITERAL(111, 8),  // "deviceId"
        QT_MOC_LITERAL(120, 12),  // "dataReceived"
        QT_MOC_LITERAL(133, 18),  // "socketStateChanged"
        QT_MOC_LITERAL(152, 29),  // "QBluetoothSocket::SocketState"
        QT_MOC_LITERAL(182, 5),  // "state"
        QT_MOC_LITERAL(188, 12),  // "displayError"
        QT_MOC_LITERAL(201, 29),  // "QBluetoothSocket::SocketError"
        QT_MOC_LITERAL(231, 5),  // "error"
        QT_MOC_LITERAL(237, 16),  // "handleAckTimeout"
        QT_MOC_LITERAL(254, 16)   // "processSendQueue"
    },
    "BluetoothSocketCommunicate",
    "ReceivedData",
    "",
    "data",
    "ReceiveDataError",
    "errorMessage",
    "DataSent",
    "success",
    "SignalBTConnected",
    "deviceId",
    "dataReceived",
    "socketStateChanged",
    "QBluetoothSocket::SocketState",
    "state",
    "displayError",
    "QBluetoothSocket::SocketError",
    "error",
    "handleAckTimeout",
    "processSendQueue"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBluetoothSocketCommunicateENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    1,   71,    2, 0x06,    3 /* Public */,
       6,    1,   74,    2, 0x06,    5 /* Public */,
       8,    1,   77,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   80,    2, 0x08,    9 /* Private */,
      11,    1,   81,    2, 0x08,   10 /* Private */,
      14,    1,   84,    2, 0x08,   12 /* Private */,
      17,    0,   87,    2, 0x08,   14 /* Private */,
      18,    0,   88,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BluetoothSocketCommunicate::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBluetoothSocketCommunicateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BluetoothSocketCommunicate, std::true_type>,
        // method 'ReceivedData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'ReceiveDataError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DataSent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SignalBTConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'socketStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QBluetoothSocket::SocketState, std::false_type>,
        // method 'displayError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QBluetoothSocket::SocketError, std::false_type>,
        // method 'handleAckTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processSendQueue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BluetoothSocketCommunicate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BluetoothSocketCommunicate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ReceivedData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->ReceiveDataError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->DataSent((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->SignalBTConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->dataReceived(); break;
        case 5: _t->socketStateChanged((*reinterpret_cast< std::add_pointer_t<QBluetoothSocket::SocketState>>(_a[1]))); break;
        case 6: _t->displayError((*reinterpret_cast< std::add_pointer_t<QBluetoothSocket::SocketError>>(_a[1]))); break;
        case 7: _t->handleAckTimeout(); break;
        case 8: _t->processSendQueue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BluetoothSocketCommunicate::*)(const QByteArray & );
            if (_t _q_method = &BluetoothSocketCommunicate::ReceivedData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BluetoothSocketCommunicate::*)(QString );
            if (_t _q_method = &BluetoothSocketCommunicate::ReceiveDataError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BluetoothSocketCommunicate::*)(bool );
            if (_t _q_method = &BluetoothSocketCommunicate::DataSent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BluetoothSocketCommunicate::*)(QString );
            if (_t _q_method = &BluetoothSocketCommunicate::SignalBTConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *BluetoothSocketCommunicate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BluetoothSocketCommunicate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBluetoothSocketCommunicateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BluetoothSocketCommunicate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void BluetoothSocketCommunicate::ReceivedData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothSocketCommunicate::ReceiveDataError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BluetoothSocketCommunicate::DataSent(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BluetoothSocketCommunicate::SignalBTConnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
