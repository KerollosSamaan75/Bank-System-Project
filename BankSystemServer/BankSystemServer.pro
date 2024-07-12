QT = core
QT += network
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AddClientHandler.cpp \
        BankDataBase.cpp \
        DeleteAccountHandler.cpp \
        GetAccountBalanceHandler.cpp \
        GetAccountNumberHandler.cpp \
        GetBankDataBaseHandler.cpp \
        GetTransactionHistoryHandler.cpp \
        Logger.cpp \
        LoginHandler.cpp \
        MakeTransactionHandler.cpp \
        MakeTransferHandler.cpp \
        SendEmail.cpp \
        Server.cpp \
        ServerHandler.cpp \
        UpdateAccountHandler.cpp \
        qaesencryption.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AddClientHandler.h \
    BankDataBase.h \
    DeleteAccountHandler.h \
    GetAccountBalanceHandler.h \
    GetAccountNumberHandler.h \
    GetBankDataBaseHandler.h \
    GetTransactionHistoryHandler.h \
    Logger.h \
    LoginHandler.h \
    MakeTransactionHandler.h \
    MakeTransferHandler.h \
    RequestHandler.h \
    SendEmail.h \
    Server.h \
    ServerHandler.h \
    UpdateAccountHandler.h \
    qaesencryption.h \
    aesni/aesni-key-exp.h \
    aesni/aesni-enc-ecb.h \
    aesni/aesni-enc-cbc.h
