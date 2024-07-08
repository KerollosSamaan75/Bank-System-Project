QT = core
QT += network
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AddClientCommand.cpp \
        BankDataBase.cpp \
        DeleteAccountCommand.cpp \
        GetAccountBalanceCommand.cpp \
        GetAccountNumberCommand.cpp \
        GetBankDataBaseCommand.cpp \
        GetTransactionHistoryCommand.cpp \
        Logger.cpp \
        LoginCommand.cpp \
        MakeTransactionCommand.cpp \
        MakeTransferCommand.cpp \
        Server.cpp \
        ServerHandler.cpp \
        UpdateAccountCommand.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AddClientCommand.h \
    BankDataBase.h \
    Command.h \
    DeleteAccountCommand.h \
    GetAccountBalanceCommand.h \
    GetAccountNumberCommand.h \
    GetBankDataBaseCommand.h \
    GetTransactionHistoryCommand.h \
    Logger.h \
    LoginCommand.h \
    MakeTransactionCommand.h \
    MakeTransferCommand.h \
    Server.h \
    ServerHandler.h \
    UpdateAccountCommand.h
