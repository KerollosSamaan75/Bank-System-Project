/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onConnectedServer",
    "",
    "onDisconnectedServer",
    "onErrorOccurredServer",
    "QAbstractSocket::SocketError",
    "socketError",
    "onStateChangedServer",
    "QAbstractSocket::SocketState",
    "socketState",
    "onReadyReadServer",
    "Data",
    "onUserSendRequest",
    "on_pBConnect_clicked",
    "on_pBLogin_clicked",
    "on_pB_AddAccount_clicked",
    "on_pBCreateAccount_clicked",
    "on_pBAddAccoutBack_clicked",
    "on_pB_AdminGetAccountNumber_clicked",
    "on_pB_DeleteAccount_clicked",
    "on_pB_AdminGetAccountBalance_clicked",
    "on_pB_AdminViewTransactionHistory_clicked",
    "on_pBAdminViewTransactionBack_clicked",
    "on_pBAdminViewTransactionView_clicked",
    "on_pB_ViewBankDatabase_clicked",
    "on_pB_ViewBankDatabaseBack_clicked",
    "on_pB_UpdateClientAccount_clicked",
    "on_pB_ClientUpdateAccountBack_clicked",
    "on_pB_Update_clicked",
    "on_pB_ClientGetAccountNumber_clicked",
    "on_pB_ClientViewAccountBalance_clicked",
    "on_pb_ViewMyHistoryBack_clicked",
    "on_pB_ViewMyHistory_clicked",
    "on_pb_ViewMyHistoryView_clicked",
    "on_pB_MakeTransaction_clicked",
    "on_pB_ClientTransferMoney_clicked",
    "on_showPasswordCheckBox_stateChanged",
    "arg1",
    "on_pBAdminLogout_clicked",
    "on_pBClientLogout_clicked",
    "on_pB_AdminConnectAgain_clicked",
    "on_pB_AddAccountConnectAgain_clicked",
    "on_pB_ClientConnectAgain_clicked",
    "on_pB_ViewTransactionHistoryConnectAgain_clicked",
    "on_pB_ViewBankDataBaseConnectAgain_clicked",
    "on_pB_UpdateAccountConnectAgain_clicked",
    "on_pB_ViewClientTransactionHistoryConnectAgain_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  248,    2, 0x0a,    1 /* Public */,
       3,    0,  249,    2, 0x0a,    2 /* Public */,
       4,    1,  250,    2, 0x0a,    3 /* Public */,
       7,    1,  253,    2, 0x0a,    5 /* Public */,
      10,    1,  256,    2, 0x0a,    7 /* Public */,
      12,    1,  259,    2, 0x0a,    9 /* Public */,
      13,    0,  262,    2, 0x08,   11 /* Private */,
      14,    0,  263,    2, 0x08,   12 /* Private */,
      15,    0,  264,    2, 0x08,   13 /* Private */,
      16,    0,  265,    2, 0x08,   14 /* Private */,
      17,    0,  266,    2, 0x08,   15 /* Private */,
      18,    0,  267,    2, 0x08,   16 /* Private */,
      19,    0,  268,    2, 0x08,   17 /* Private */,
      20,    0,  269,    2, 0x08,   18 /* Private */,
      21,    0,  270,    2, 0x08,   19 /* Private */,
      22,    0,  271,    2, 0x08,   20 /* Private */,
      23,    0,  272,    2, 0x08,   21 /* Private */,
      24,    0,  273,    2, 0x08,   22 /* Private */,
      25,    0,  274,    2, 0x08,   23 /* Private */,
      26,    0,  275,    2, 0x08,   24 /* Private */,
      27,    0,  276,    2, 0x08,   25 /* Private */,
      28,    0,  277,    2, 0x08,   26 /* Private */,
      29,    0,  278,    2, 0x08,   27 /* Private */,
      30,    0,  279,    2, 0x08,   28 /* Private */,
      31,    0,  280,    2, 0x08,   29 /* Private */,
      32,    0,  281,    2, 0x08,   30 /* Private */,
      33,    0,  282,    2, 0x08,   31 /* Private */,
      34,    0,  283,    2, 0x08,   32 /* Private */,
      35,    0,  284,    2, 0x08,   33 /* Private */,
      36,    1,  285,    2, 0x08,   34 /* Private */,
      38,    0,  288,    2, 0x08,   36 /* Private */,
      39,    0,  289,    2, 0x08,   37 /* Private */,
      40,    0,  290,    2, 0x08,   38 /* Private */,
      41,    0,  291,    2, 0x08,   39 /* Private */,
      42,    0,  292,    2, 0x08,   40 /* Private */,
      43,    0,  293,    2, 0x08,   41 /* Private */,
      44,    0,  294,    2, 0x08,   42 /* Private */,
      45,    0,  295,    2, 0x08,   43 /* Private */,
      46,    0,  296,    2, 0x08,   44 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onConnectedServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnectedServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onErrorOccurredServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'onStateChangedServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'onReadyReadServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onUserSendRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pBConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBLogin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_AddAccount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBCreateAccount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBAddAccoutBack_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_AdminGetAccountNumber_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_DeleteAccount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_AdminGetAccountBalance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_AdminViewTransactionHistory_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBAdminViewTransactionBack_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBAdminViewTransactionView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ViewBankDatabase_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ViewBankDatabaseBack_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_UpdateClientAccount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ClientUpdateAccountBack_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_Update_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ClientGetAccountNumber_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ClientViewAccountBalance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_ViewMyHistoryBack_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ViewMyHistory_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_ViewMyHistoryView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_MakeTransaction_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ClientTransferMoney_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_showPasswordCheckBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pBAdminLogout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pBClientLogout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_AdminConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_AddAccountConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ClientConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ViewTransactionHistoryConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ViewBankDataBaseConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_UpdateAccountConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pB_ViewClientTransactionHistoryConnectAgain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onConnectedServer(); break;
        case 1: _t->onDisconnectedServer(); break;
        case 2: _t->onErrorOccurredServer((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 3: _t->onStateChangedServer((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 4: _t->onReadyReadServer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->onUserSendRequest((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_pBConnect_clicked(); break;
        case 7: _t->on_pBLogin_clicked(); break;
        case 8: _t->on_pB_AddAccount_clicked(); break;
        case 9: _t->on_pBCreateAccount_clicked(); break;
        case 10: _t->on_pBAddAccoutBack_clicked(); break;
        case 11: _t->on_pB_AdminGetAccountNumber_clicked(); break;
        case 12: _t->on_pB_DeleteAccount_clicked(); break;
        case 13: _t->on_pB_AdminGetAccountBalance_clicked(); break;
        case 14: _t->on_pB_AdminViewTransactionHistory_clicked(); break;
        case 15: _t->on_pBAdminViewTransactionBack_clicked(); break;
        case 16: _t->on_pBAdminViewTransactionView_clicked(); break;
        case 17: _t->on_pB_ViewBankDatabase_clicked(); break;
        case 18: _t->on_pB_ViewBankDatabaseBack_clicked(); break;
        case 19: _t->on_pB_UpdateClientAccount_clicked(); break;
        case 20: _t->on_pB_ClientUpdateAccountBack_clicked(); break;
        case 21: _t->on_pB_Update_clicked(); break;
        case 22: _t->on_pB_ClientGetAccountNumber_clicked(); break;
        case 23: _t->on_pB_ClientViewAccountBalance_clicked(); break;
        case 24: _t->on_pb_ViewMyHistoryBack_clicked(); break;
        case 25: _t->on_pB_ViewMyHistory_clicked(); break;
        case 26: _t->on_pb_ViewMyHistoryView_clicked(); break;
        case 27: _t->on_pB_MakeTransaction_clicked(); break;
        case 28: _t->on_pB_ClientTransferMoney_clicked(); break;
        case 29: _t->on_showPasswordCheckBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_pBAdminLogout_clicked(); break;
        case 31: _t->on_pBClientLogout_clicked(); break;
        case 32: _t->on_pB_AdminConnectAgain_clicked(); break;
        case 33: _t->on_pB_AddAccountConnectAgain_clicked(); break;
        case 34: _t->on_pB_ClientConnectAgain_clicked(); break;
        case 35: _t->on_pB_ViewTransactionHistoryConnectAgain_clicked(); break;
        case 36: _t->on_pB_ViewBankDataBaseConnectAgain_clicked(); break;
        case 37: _t->on_pB_UpdateAccountConnectAgain_clicked(); break;
        case 38: _t->on_pB_ViewClientTransactionHistoryConnectAgain_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}
QT_WARNING_POP
