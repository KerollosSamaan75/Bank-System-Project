#ifndef ADDCLIENTHANDLER_H
#define ADDCLIENTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The AddClientHandler class handles requests to add a new client to the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the client addition.

class AddClientHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    AddClientHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status string.
    // It processes the request to add a new client and updates the status accordingly.
    void execute(const QStringList &RequestParts, QString &status) override;

private:
    // Reference to the BankDataBase object where the new client will be added.
    BankDataBase &dataBase;
};

#endif // ADDCLIENTHANDLER_H
#ifndef BANKDATABASE_H
#define BANKDATABASE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QString>
#include <QRandomGenerator>
#include <QVector>
#include "Logger.h"

// The BankDataBase class manages the data related to clients and transactions in the bank system.
// It provides functionalities to initialize, retrieve, and manipulate database records.

class BankDataBase : public QObject
{
    Q_OBJECT
public:
    // Constructor to initialize the BankDataBase object with an optional parent.
    explicit BankDataBase(QObject *parent = nullptr);

private:
    // Private members to store the database records and file paths.
    QVector<QJsonObject> mainDatabaseRecords;        // Vector holding data from the main database file.
    QVector<QJsonObject> transactionDatabaseRecords; // Vector holding data from the transaction database file.
    QString mainDatabaseFilePath;                    // Path to the main database file.
    QString transactionFilePath;                     // Path to the transaction database file.
    Logger logger;                                   // Logger for logging messages and errors.

public:
    // Initialization methods
    void initializeMainDatabase();                  // Initialize main database from file.
    void initializeTransactionDatabase();           // Initialize transaction database from file.

    // Getters
    QVector<QJsonObject> getMainDatabase();         // Retrieve data from the main database file.
    QVector<QJsonObject> getTransactionDatabase();  // Retrieve data from the transaction database file.

    // Database operations
    bool addClient(const QString &username, const QString &password, const QString &fullName, const QString &age,
                   const QString &email, const QString &balance); // Add new client data.
    bool deleteClient(const QString &accountNumber);             // Delete a client from the database.
    bool updateClient(const QString &accountNumber, const QString &username, const QString &password,
                      const QString &fullName, const QString &age, const QString &email); // Update client information.
    bool saveMainDatabaseToFile();                               // Save the main database to the file.
    bool saveTransactionDatabaseToFile();                        // Save the transaction database to the file.
    bool setUserLoginState(const QString& username, const QString& state); // Set the login state of a user.

    // Transaction operations
    bool transferMoney(const QString &sourceAccountNumber, const QString &targetAccountNumber,
                       const QString &amountStr);                // Transfer money between accounts.
    bool withdrawMoney(const QString &accountNumber, const QString &amount); // Withdraw money from an account.
    bool depositMoney(const QString &accountNumber, const QString &amount);  // Deposit money into an account.

    // Utility methods
    QString generateAccountNumber();                             // Generate a unique account number.
    QString getEmailByAccountNumber(const QString &accountNumber); // Get email by account number.

};

#endif // BANKDATABASE_H
#ifndef DELETEACCOUNTHANDLER_H
#define DELETEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The DeleteAccountHandler class handles requests to delete an account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the account deletion.

class DeleteAccountHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    DeleteAccountHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to delete an account and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object where the account will be deleted.
    BankDataBase &dataBase;
};

#endif // DELETEACCOUNTHANDLER_H
#ifndef GETACCOUNTBALANCEHANDLER_H
#define GETACCOUNTBALANCEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetAccountBalanceHandler class handles requests to retrieve the balance of an account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the balance retrieval.

class GetAccountBalanceHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetAccountBalanceHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the account balance and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the account balance will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETACCOUNTBALANCEHANDLER_H
#ifndef GETACCOUNTNUMBERHANDLER_H
#define GETACCOUNTNUMBERHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetAccountNumberHandler class handles requests to retrieve the account number associated with a specific client from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the account number retrieval.

class GetAccountNumberHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetAccountNumberHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the account number and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the account number will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETACCOUNTNUMBERHANDLER_H
#ifndef GETBANKDATABASEHANDLER_H
#define GETBANKDATABASEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetBankDataBaseHandler class handles requests to retrieve the entire bank database.
// It inherits from RequestHandler and overrides the execute method to perform the database retrieval.

class GetBankDataBaseHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetBankDataBaseHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the entire bank database and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the entire database will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETBANKDATABASEHANDLER_H
#ifndef GETTRANSACTIONHISTORYHANDLER_H
#define GETTRANSACTIONHISTORYHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetTransactionHistoryHandler class handles requests to retrieve the transaction history for a specific account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the transaction history retrieval.

class GetTransactionHistoryHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetTransactionHistoryHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the transaction history for a specific account and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the transaction history will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETTRANSACTIONHISTORYHANDLER_H
#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

// The Logger class provides functionality to log messages.
// It allows other classes and components to log messages to a specified output.
class Logger
{
public:
    // Constructor: Initializes the Logger instance.
    Logger();

    // Destructor: Cleans up resources used by the Logger instance.
    ~Logger();

    // logMessage method logs a message to the logger.
    // Parameters:
    // - message: The message to be logged, provided as a QString.
    void logMessage(const QString &message);
};

#endif // LOGGER_H
#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The LoginHandler class handles requests to authenticate and log in a user.
// It inherits from RequestHandler and overrides the execute method to perform the login operation.

class LoginHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    LoginHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to authenticate and log in a user and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for user authentication and login.
    BankDataBase &dataBase;
};

#endif // LOGINHANDLER_H
#ifndef MAKETRANSACTIONHANDLER_H
#define MAKETRANSACTIONHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"
#include "SendEmail.h"

// The MakeTransactionHandler class handles requests to make transactions (e.g., money transfers) in the bank system.
// It inherits from RequestHandler and overrides the execute method to perform the transaction operation.

class MakeTransactionHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    MakeTransactionHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to make a transaction and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for performing transaction operations.
    BankDataBase &dataBase;

    // Email utility object to send transaction notification emails.
    SendEmail email;

    // Private method to send an email notification about the transaction.
    // Parameters:
    // - sourceAccountNumber: The account number from which the transaction originates.
    // - amountStr: The amount of money involved in the transaction as a QString.
    void sendEmail(const QString &sourceAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSACTIONHANDLER_H
#ifndef MAKETRANSFERHANDLER_H
#define MAKETRANSFERHANDLER_H

#include "RequestHandler.h"
#include "SendEmail.h"
#include "BankDataBase.h"

// The MakeTransferHandler class handles requests to transfer money between accounts in the bank system.
// It inherits from RequestHandler and overrides the execute method to perform the transfer operation.

class MakeTransferHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    MakeTransferHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to transfer money between accounts and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for performing transfer operations.
    BankDataBase &dataBase;

    // Email utility object to send transaction notification emails.
    SendEmail email;

    // Private method to send an email notification about the transfer.
    // Parameters:
    // - sourceAccountNumber: The account number from which the transfer originates.
    // - targetAccountNumber: The account number to which the transfer is made.
    // - amountStr: The amount of money involved in the transfer as a QString.
    void sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSFERUPS_HANDLER_H
#ifndef QAESENCRYPTION_H
#define QAESENCRYPTION_H

#ifdef QtAES_EXPORTS
#include "qtaes_export.h"
#else
#define QTAESSHARED_EXPORT
#endif

#include <QObject>
#include <QByteArray>

#ifdef __linux__
#ifndef __LP64__
#define do_rdtsc _do_rdtsc
#endif
#endif

class QTAESSHARED_EXPORT QAESEncryption : public QObject
{
    Q_OBJECT
public:
    enum Aes {
        AES_128,
        AES_192,
        AES_256
    };

    enum Mode {
        ECB,
        CBC,
        CFB,
        OFB
    };

    enum Padding {
      ZERO,
      PKCS7,
      ISO
    };

    /*!
     * \brief static method call to encrypt data given by rawText
     * \param level:    AES::Aes level
     * \param mode:     AES::Mode mode
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \param padding:  AES::Padding standard
     * \return encrypted cipher
     */
    static QByteArray Crypt(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &rawText, const QByteArray &key,
                            const QByteArray &iv = QByteArray(), QAESEncryption::Padding padding = QAESEncryption::ISO);
    /*!
     * \brief static method call to decrypt data given by rawText
     * \param level:    AES::Aes level
     * \param mode:     AES::Mode mode
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \param padding:  AES::Padding standard
     * \return decrypted cipher with padding
     */
    static QByteArray Decrypt(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &rawText, const QByteArray &key,
                              const QByteArray &iv = QByteArray(), QAESEncryption::Padding padding = QAESEncryption::ISO);
    /*!
     * \brief static method call to expand the user key to fit the encrypting/decrypting algorithm
     * \param level:            AES::Aes level
     * \param mode:             AES::Mode mode
     * \param key:              user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param expKey:           output expanded key
     * \param isEncryptionKey:    always 'true' || only 'false' when DECRYPTING in CBC or EBC mode with aesni (check if supported)
     * \return AES-ready key
     */
    static QByteArray ExpandKey(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &key, bool isEncryptionKey);

    /*!
     * \brief static method call to remove padding from decrypted cipher given by rawText
     * \param rawText:  inputText
     * \param padding:  AES::Padding standard
     * \return decrypted cipher with padding removed
     */
    static QByteArray RemovePadding(const QByteArray &rawText, QAESEncryption::Padding padding = QAESEncryption::ISO);

    QAESEncryption(QAESEncryption::Aes level, QAESEncryption::Mode mode,
                   QAESEncryption::Padding padding = QAESEncryption::ISO);



    /*!
     * \brief object method call to encrypt data given by rawText
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \return encrypted cipher
     */
    QByteArray encode(const QByteArray &rawText, const QByteArray &key, const QByteArray &iv = QByteArray());

    /*!
     * \brief object method call to decrypt data given by rawText
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \param padding:  AES::Padding standard
     * \return decrypted cipher with padding
     */
    QByteArray decode(const QByteArray &rawText, const QByteArray &key, const QByteArray &iv = QByteArray());

    /*!
     * \brief object method call to expand the user key to fit the encrypting/decrypting algorithm
     * \param key:              user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param isEncryptionKey:    always 'true' || only 'false' when DECRYPTING in CBC or EBC mode with aesni (check if supported)
     * \return AES-ready key
     */
    QByteArray expandKey(const QByteArray &key, bool isEncryptionKey);

    /*!
     * \brief object method call to remove padding from decrypted cipher given by rawText
     * \param rawText:  inputText
     * \return decrypted cipher with padding removed
     */
    QByteArray removePadding(const QByteArray &rawText);

    QByteArray printArray(uchar *arr, int size);
Q_SIGNALS:

public Q_SLOTS:

private:
    int m_nb;
    int m_blocklen;
    int m_level;
    int m_mode;
    int m_nk;
    int m_keyLen;
    int m_nr;
    int m_expandedKey;
    int m_padding;
    bool m_aesNIAvailable;
    QByteArray* m_state;

    struct AES256{
        int nk = 8;
        int keylen = 32;
        int nr = 14;
        int expandedKey = 240;
        int userKeySize = 256;
    };

    struct AES192{
        int nk = 6;
        int keylen = 24;
        int nr = 12;
        int expandedKey = 209;
        int userKeySize = 192;
    };

    struct AES128{
        int nk = 4;
        int keylen = 16;
        int nr = 10;
        int expandedKey = 176;
        int userKeySize = 128;
    };

    quint8 getSBoxValue(quint8 num){return sbox[num];}
    quint8 getSBoxInvert(quint8 num){return rsbox[num];}

    void addRoundKey(const quint8 round, const QByteArray &expKey);
    void subBytes();
    void shiftRows();
    void mixColumns();
    void invMixColumns();
    void invSubBytes();
    void invShiftRows();
    QByteArray getPadding(int currSize, int alignment);
    QByteArray cipher(const QByteArray &expKey, const QByteArray &in);
    QByteArray invCipher(const QByteArray &expKey, const QByteArray &in);
    QByteArray byteXor(const QByteArray &a, const QByteArray &b);

    const quint8 sbox[256] = {
      //0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
      0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
      0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
      0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
      0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
      0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
      0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
      0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
      0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
      0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
      0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
      0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
      0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
      0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
      0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
      0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
      0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

    const quint8 rsbox[256] = {
      0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
      0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
      0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
      0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
      0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
      0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
      0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
      0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
      0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
      0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
      0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
      0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
      0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
      0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
      0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
      0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

    // The round constant word array, Rcon[i], contains the values given by
    // x to th e power (i-1) being powers of x (x is denoted as {02}) in the field GF(2^8)
    // Only the first 14 elements are needed
    const quint8 Rcon[14] = {
        0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab};
};

#endif // QAESENCRYPTION_H
#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QStringList>
#include <QString>

// The RequestHandler class is an abstract base class for handling requests.
// Subclasses must override the execute method to define specific request handling logic.

class RequestHandler {
public:
    // Virtual destructor ensures proper cleanup of derived classes.
    virtual ~RequestHandler() = default;

    // Pure virtual function to execute a request.
    // Parameters:
    // - RequestParts: A QStringList containing parsed parts of the request.
    // - statusMessage: A QString reference to update with the execution status or response.
    virtual void execute(const QStringList &RequestParts, QString &statusMessage) = 0;
};

#endif // REQUESTHANDLER_H
#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QString>
#include <QProcess>
#include <QDebug>
#include "Logger.h"

// The SendEmail class provides functionality to send email notifications.
// It uses QProcess to invoke the email sending command-line tool and logs operations using the Logger.

class SendEmail
{
public:
    // Constructor: Initializes an instance of SendEmail.
    SendEmail();

    // send method sends an email with specified parameters.
    // Parameters:
    // - to: The recipient email address.
    // - subject: The subject of the email.
    // - body: The body content of the email.
    void send(const QString &to, const QString &subject, const QString &body);

private:
    QString to;         // The recipient email address.
    QString subject;    // The subject of the email.
    QString body;       // The body content of the email.
    Logger logger;      // Logger instance for logging email sending operations.
};

#endif // SENDEMAIL_H
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTextStream>
#include <QDebug>
#include <ServerHandler.h>
#include "Logger.h"

// The Server class inherits QTcpServer and handles incoming client connections.
// It starts a TCP server and manages incoming connections by spawning ServerHandler instances.

class Server : public QTcpServer
{
    Q_OBJECT
public:
    // Constructor: Initializes an instance of Server.
    explicit Server(QObject *parent = nullptr);

    // StartServer method starts the TCP server.
    void StartServer();

signals:

protected:
    // Override of QTcpServer's incomingConnection method.
    // Handles incoming client connections by spawning ServerHandler instances.
    void incomingConnection(qintptr handle) override;

private:
    qint32 Port;     // Port number on which the server listens for incoming connections.
    Logger logger;   // Logger instance for logging server operations.
};

#endif // SERVER_H
#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QMap>
#include "BankDataBase.h"
#include "Logger.h"
#include "RequestHandler.h"
#include "LoginHandler.h"
#include "AddClientHandler.h"
#include "DeleteAccountHandler.h"
#include "GetAccountBalanceHandler.h"
#include "GetAccountNumberHandler.h"
#include "GetTransactionHistoryHandler.h"
#include "MakeTransactionHandler.h"
#include "MakeTransferHandler.h"
#include "UpdateAccountHandler.h"
#include "GetBankDataBaseHandler.h"
#include "qaesencryption.h"

// The ServerHandler class manages individual client connections in a multithreaded TCP server application.
// It handles client requests, delegates them to appropriate handlers, and manages server-side operations.

class ServerHandler : public QThread
{
    Q_OBJECT
public:
    // Constructor: Initializes an instance of ServerHandler.
    // Parameters:
    // - ID: Unique identifier for the client connection.
    // - parent: Optional parent object.
    explicit ServerHandler(qint32 ID, QObject *parent = nullptr);

public slots:
    // Slot: Triggered when data is ready to be read from the socket.
    void onReadyRead();

    // Slot: Triggered when the client disconnects from the server.
    void onDisconnected();

protected:
    // Override of QThread's run method.
    // Manages the main execution logic of the server handler.
    void run() override;

private:
    qint32 userID;                           // Unique identifier for the client connection.
    QTcpSocket *Socket;                      // Socket for communication with the client.
    BankDataBase dataBase;                   // Database instance for managing client data.
    QString statusMessage;                   // Status message to communicate with clients.
    QString loginUser;                       // Logged-in user's username.
    bool loginStatus;                        // Flag indicating login status.
    Logger logger;                           // Logger instance for logging server operations.
    QMap<QString, RequestHandler*> requestHandlerMap; // Map of request handlers for different types of requests.

    // Initializes request handlers for various client requests.
    void setupRequestHandles();

    // Processes a client request.
    // Parameters:
    // - Request: The request received from the client.
    void Operation(QString Request);

    // Sends a response message to the client.
    // Parameters:
    // - Message: The message to send as a response.
    void sendResponse(const QString &Message);

    // Decrypts incoming encrypted data from the client.
    // Parameters:
    // - encryptedData: Encrypted data received from the client.
    // Returns:
    // Decrypted data as QByteArray.
    QByteArray decryptRequest(const QByteArray &encryptedData);
};

#endif // SERVERHANDLER_H
#ifndef UPDATEACCOUNTHANDLER_H
#define UPDATEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// UpdateAccountHandler class handles requests to update client account information.
// It interacts with BankDataBase to perform updates and manages the response status.

class UpdateAccountHandler : public RequestHandler
{
public:
    // Constructor: Initializes an instance of UpdateAccountHandler.
    // Parameters:
    // - db: Reference to the BankDataBase instance for database operations.
    UpdateAccountHandler(BankDataBase &db);

    // Override of execute method from RequestHandler.
    // Processes the request to update client account information.
    // Parameters:
    // - RequestParts: Parts of the request parsed into a QStringList.
    // - statusMessage: Reference to a QString to update with the execution status or response.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase; // Reference to the BankDataBase instance for database operations.
};

#endif // UPDATEACCOUNTHANDLER_H
#include "AddClientHandler.h"

// Constructor: Initializes an instance of AddClientHandler.
// Parameters:
// - db: Reference to the BankDataBase instance for database operations.
AddClientHandler::AddClientHandler(BankDataBase &db) : dataBase(db) {}

// Override of execute method from RequestHandler.
// Processes the request to add a new client to the database.
// Parameters:
// - RequestParts: Parts of the request parsed into a QStringList.
// - statusMessage: Reference to a QString to update with the execution status or response.
void AddClientHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 7 elements (full name, username, password, age, email, balance)
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields: full name, username, password, age, email, and balance.";
        return;
    }

    // Extract request parameters
    const QString fullName = RequestParts[1];
    const QString userName = RequestParts[2];
    const QString password = RequestParts[3];
    const QString ageStr = RequestParts[4];
    const QString email = RequestParts[5];
    const QString balanceStr = RequestParts[6];

    // Check if username already exists in the database
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == userName)
        {
            statusMessage = "This username is already taken. Please choose a different username.";
            return;
        }
    }

    // Attempt to add the new client to the database
    if (dataBase.addClient(userName, password, fullName, ageStr, email, balanceStr))
    {
        statusMessage = QString("Congratulations! New user '%1' has been added. Welcome aboard").arg(userName);
    }
    else
    {
        statusMessage = QString("Sadly, new user '%1' couldn't be added to the database. Please try again.").arg(userName);
    }
}
#include "BankDataBase.h"

BankDataBase::BankDataBase(QObject *parent)
    : QObject{parent},
    mainDatabaseFilePath{"mainDataBase.json"},
    transactionFilePath{"transactionDataBase.json"}
{}

void BankDataBase::initializeMainDatabase()
{
    QFile file(mainDatabaseFilePath); // Open QFile for main database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        logger.logMessage("Error: Cannot open main database file");
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        logger.logMessage("Error: Failed to parse JSON from main database file");
        return;
    }

    if (!jsonDoc.isArray())
    {
        logger.logMessage("Error: Main database file does not contain a JSON array");
        return;
    }

    mainDatabaseRecords.clear(); // Clear existing data in vector

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray for iteration

    // Iterate through JSON array and populate mainDatabaseRecords vector
    for (const auto& jsonValue : jsonArray)
    {
        if (jsonValue.isObject())
        {
            QJsonObject jsonObj = jsonValue.toObject(); // Extract object from array
            mainDatabaseRecords.push_back(jsonObj); // Append object to mainDatabaseRecords vector
        }
        else
        {
            logger.logMessage("Warning: Found non-object element in main database JSON array");
        }
    }
    logger.logMessage("Main database initialized with " + QString::number(mainDatabaseRecords.size()) + " records");
}




void BankDataBase::initializeTransactionDatabase()
{
    QFile file(transactionFilePath); // Open QFile for transaction database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        logger.logMessage("Error: Cannot open transaction database file");
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        logger.logMessage("Error: Failed to parse JSON from transaction database file");
        return;
    }

    if (!jsonDoc.isArray())
    {
        logger.logMessage("Error: Transaction database file does not contain a JSON array");
        return;
    }

    transactionDatabaseRecords.clear(); // Clear existing data in vector

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray for iteration

    // Iterate through JSON array and populate transactionRecords vector
    for (const auto& jsonValue : jsonArray)
    {
        if (jsonValue.isObject())
        {
            QJsonObject jsonObj = jsonValue.toObject(); // Extract object from array
            transactionDatabaseRecords.push_back(jsonObj); // Append object to transactionRecords vector
        }
        else
        {
            logger.logMessage("Warning: Found non-object element in transaction database JSON array");
        }
    }
    logger.logMessage("Transaction database initialized with " + QString::number(transactionDatabaseRecords.size()) + " records");
}


// Getter for retrieving data from the main database file
QVector<QJsonObject> BankDataBase::getMainDatabase()
{
    initializeMainDatabase(); // Ensure data is up-to-date
    return mainDatabaseRecords;
}

// Getter for retrieving data from the transaction database file
QVector<QJsonObject> BankDataBase::getTransactionDatabase()
{
    initializeTransactionDatabase(); // Ensure data is up-to-date
    return transactionDatabaseRecords;
}

bool BankDataBase::addClient(const QString &username, const QString &password, const QString &fullName,
                             const QString &age, const QString &email, const QString &balance )
{
    QString AccountNumber = generateAccountNumber(); // Generate a unique account number

    // Create a new client object
    QJsonObject newClient;
    newClient["Username"] = username;
    newClient["Password"] = password;
    newClient["FullName"] = fullName;
    newClient["Age"] = age;
    newClient["Email"] = email;
    newClient["Authority"] = "Client"; // Assuming new clients are added as regular users
    newClient["AccountNumber"] = AccountNumber;
    newClient["Balance"] = balance; // Initial balance is set to 0
    newClient["Login"] = "0";

    // Append the new client to the main database records
    mainDatabaseRecords.push_back(newClient);
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after adding new client.");
        return false;
    }

    QJsonObject newClientTrans;
    newClientTrans["AccountNumber"] = AccountNumber;
    newClientTrans["Transactions"] = QJsonArray();
    transactionDatabaseRecords.push_back(newClientTrans);

    // Save the updated transaction database to file
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after adding new client.");
        return false;
    }
    logger.logMessage("Client added successfully.");
    return true; // Return true indicating client addition succeeded
}


bool BankDataBase::saveMainDatabaseToFile()
{
    QJsonArray jsonArray; // Create a JSON array to hold database records

    // Convert each QJsonObject in mainDatabaseRecords to QJsonArray
    for (const auto& record : mainDatabaseRecords)
    {
        jsonArray.append(record);
    }

    // Convert QJsonArray to QJsonDocument
    QJsonDocument jsonDoc(jsonArray);

    // Convert QJsonDocument to QByteArray
    QByteArray jsonData = jsonDoc.toJson();

    // Write QByteArray to file
    QFile file(mainDatabaseFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream out(&file);
        out << jsonData;
        file.close();
        logger.logMessage("Main database file saved successfully.");
        return true; // Return true indicating success
    }
    else
    {
        logger.logMessage("Failed to save main database file.");
        return false; // Return false indicating failure
    }
}

bool BankDataBase::saveTransactionDatabaseToFile()
{
    // Create a JSON array to hold transaction records
    QJsonArray jsonArray;

    // Convert each QJsonObject in transactionDatabaseRecords to QJsonArray
    for (const auto& record : transactionDatabaseRecords)
    {
        jsonArray.append(record);
    }

    // Convert QJsonArray to QJsonDocument
    QJsonDocument jsonDoc(jsonArray);

    // Convert QJsonDocument to QByteArray
    QByteArray jsonData = jsonDoc.toJson();

    // Write QByteArray to file
    QFile file(transactionFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream out(&file);
        out << jsonData;
        file.close();
        logger.logMessage("Transaction database file saved successfully.");
        return true;
    }
    else
    {
        logger.logMessage("Failed to save transaction database file.");
        return false;
    }
}

bool BankDataBase::setUserLoginState(const QString& username, const QString& state)
{
    // Find the user in the main database records
    for (auto& record : mainDatabaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            record["Login"] = state; // Update the login state

            // Save the updated main database records
            if (!saveMainDatabaseToFile())
            {
                logger.logMessage("Failed to save main database after updating login state for user: " + username);
                return false;
            }

            logger.logMessage("Login state updated successfully for user: " + username);
            return true;
        }
    }
    // Log and return false if the user was not found
    logger.logMessage("User not found for updating login state: " + username);
    return false;
}



bool BankDataBase::deleteClient(const QString &accountNumber)
{
    // Initialize the main database
    initializeMainDatabase();

    bool mainDatabaseDeleted = false;
    bool transactionDatabaseDeleted = false;

    // Step 1: Remove from Main Database
    for (int i = 0; i < mainDatabaseRecords.size(); ++i)
    {
        if (mainDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            logger.logMessage("Deleting client from main database with AccountNumber: " + accountNumber);
            mainDatabaseRecords.remove(i);
            mainDatabaseDeleted = true;
            break;
        }
    }
    if(mainDatabaseDeleted == false)
    {
        logger.logMessage("This account number not found in main database");
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveMainDatabaseToFile())
        {
            logger.logMessage("Failed to save main database after deleting client.");
            return false;
        }
    }


    // Step 2: Remove from Transaction Database
    for (int i = 0; i < transactionDatabaseRecords.size(); ++i)
    {
        if (transactionDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            logger.logMessage("Deleting client from transaction database with AccountNumber: " + accountNumber);
            transactionDatabaseRecords.remove(i);
            transactionDatabaseDeleted = true;
            break;
        }
    }
    if(transactionDatabaseDeleted == false)
    {
        logger.logMessage("This account number not found in transaction database");
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveTransactionDatabaseToFile())
        {
            logger.logMessage("Failed to save transaction database after deleting client.");
            return false;
        }
    }

    // Return true if both deletions were successful
    return mainDatabaseDeleted && transactionDatabaseDeleted;
}



bool BankDataBase::updateClient(const QString &accountNumber, const QString &username, const QString &password
                                , const QString &fullName,const QString &ageStr, const QString &email)
{
    // Load the main database records
    initializeMainDatabase();
    bool userFound = false;

    // Loop through each record in the database to find the matching user
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            userFound = true;

            // Update only non-empty fields
            if (!username.isEmpty())
            {
                logger.logMessage("Updating username for account number: " + accountNumber);
                record["Username"] = username;
            }
            if (!password.isEmpty())
            {
                logger.logMessage("Updating password for account number: " + accountNumber);
                record["Password"] = password;
            }
            if (!fullName.isEmpty())
            {
                logger.logMessage("Updating full name for account number: " + accountNumber);
                record["FullName"] = fullName;
            }
            bool ok;
            int age = ageStr.toInt(&ok);
            if (ok && age != 0)
            {
                logger.logMessage("Updating age for account number: " + accountNumber);
                record["Age"] = ageStr;
            }
            if (!email.isEmpty())
            {
                logger.logMessage("Updating email for account number: " + accountNumber);
                record["Email"] = email;
            }
            break;
        }
    }

    // Check if the user was found and updated
    if (userFound)
    {
        // Save the updated database to file
        if (saveMainDatabaseToFile())
        {
            logger.logMessage("Account information updated successfully for account number: " + accountNumber);
            return true; // Update successful
        }
        else
        {
            logger.logMessage("Failed to save updated account information for account number: " + accountNumber);
            return false; // Failed to save updated information
        }
    }
    else
    {
        logger.logMessage("Account not found. Update failed for account number: " + accountNumber);
        return false; // Account not found
    }
}



// Update transaction data
bool BankDataBase::transferMoney(const QString &sourceAccountNumber, const QString &targetAccountNumber,
                                 const QString &amountStr)
{
    // Validate the amounts
    bool AmountValid;
    int Amount = amountStr.toInt(&AmountValid);

    if (!AmountValid || Amount <= 0)
    {
        logger.logMessage("Invalid transfer amount from the source account.");
        return false;
    }

    // Check if source and target account numbers are different
    if (sourceAccountNumber == targetAccountNumber)
    {
        logger.logMessage("Source and target account numbers must be different.");
        return false;
    }

    // Find the source and target accounts and update the balances
    bool sourceAccountFound = false;
    bool targetAccountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            QString  currentSourceBalanceStr = record["Balance"].toString();
            int currentSourceBalance = currentSourceBalanceStr.toInt();
            if (currentSourceBalance < Amount)
            {
                logger.logMessage("Insufficient balance in the source account.");
                return false;
            }
            int newSourceBalance = currentSourceBalance - Amount;
            record["Balance"] = QString::number(newSourceBalance);
            sourceAccountFound = true;
        }

        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QString currentTargetBalanceStr = record["Balance"].toString();
            int currentTargetBalance = currentTargetBalanceStr.toInt();
            int newTargetBalance = currentTargetBalance + Amount;
            record["Balance"] = QString::number(newTargetBalance);
            targetAccountFound = true;
        }
    }

    if (!sourceAccountFound)
    {
        logger.logMessage("Source account not found.");
        return false;
    }

    if (!targetAccountFound)
    {
        logger.logMessage("Target account not found.");
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after transfer.");
        return false;
    }

    // Update the transaction record for the source account
    QJsonObject sourceTransaction;
    sourceTransaction["amount"] = "-" + QString::number(Amount);
    sourceTransaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(sourceTransaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    // Update the transaction record for the target account
    QJsonObject targetTransaction;
    targetTransaction["amount"] = "+" + QString::number(Amount);
    targetTransaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(targetTransaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after transfer.");
        return false;
    }

    logger.logMessage("Transfer successful.");
    return true;
}



bool BankDataBase::withdrawMoney(const QString &accountNumber, const QString &amount)
{
    // Validate the amount
    bool isNumber;
    int withdrawAmount = amount.toInt(&isNumber);
    if (!isNumber || withdrawAmount <= 0)
    {
        logger.logMessage("Invalid withdraw amount.");
        return false;
    }

    // Find the account and update the balance
    bool accountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString str = record["Balance"].toString();
            int currentBalance = str.toInt();
            if (withdrawAmount > currentBalance)
            {
                logger.logMessage("Insufficient balance.");
                return false;
            }
            int newBalance = currentBalance - withdrawAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            logger.logMessage("Withdrawal amount of " + QString::number(withdrawAmount) + " for account number: " + accountNumber);
            break;
        }
    }

    if (!accountFound)
    {
        logger.logMessage("Account not found for withdrawal: " + accountNumber);
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after withdrawal for account number: " + accountNumber);
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "-" + QString::number(withdrawAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            logger.logMessage("Updated transaction record for withdrawal for account number: " + accountNumber);
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after withdrawal for account number: " + accountNumber);
        return false;
    }

    logger.logMessage("Withdrawal successful for account number: " + accountNumber);
    return true;
}


bool BankDataBase::depositMoney(const QString &accountNumber, const QString &amount)
{
    // Validate the amount
    bool isNumber;
    int depositAmount = amount.toInt(&isNumber);
    if (!isNumber || depositAmount <= 0)
    {
        logger.logMessage("Invalid deposit amount for account number: " + accountNumber);
        return false;
    }

    // Find the account and update the balance
    bool accountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString str = record["Balance"].toString();
            int currentBalance = str.toInt();
            int newBalance = currentBalance + depositAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            logger.logMessage("Deposited amount of " + QString::number(depositAmount) + " for account number: " + accountNumber);
            break;
        }
    }

    if (!accountFound)
    {
        logger.logMessage("Account not found for deposit: " + accountNumber);
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after deposit for account number: " + accountNumber);
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "+" + QString::number(depositAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            logger.logMessage("Updated transaction record for deposit for account number: " + accountNumber);
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after deposit for account number: " + accountNumber);
        return false;
    }

    logger.logMessage("Deposit successful for account number: " + accountNumber);
    return true;
}

QString BankDataBase::generateAccountNumber()
{
    // Get the current timestamp
    qint64 timestamp = QDateTime::currentSecsSinceEpoch();

    // Generate a random number between 1000 and 9999
    int randomNum = QRandomGenerator::global()->bounded(1000, 10000);

    // Combine the timestamp and the random number to create the account number
    QString accountNumber = QString::number(timestamp).right(5) + QString::number(randomNum);

    // Log the generated account number
    logger.logMessage(QString("Generated account number: %1").arg(accountNumber));

    return accountNumber;
}


QString BankDataBase::getEmailByAccountNumber(const QString &accountNumber)
{
    for (const auto &record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString email = record["Email"].toString();
            logger.logMessage(QString("Email found for account %1: %2").arg(accountNumber, email));
            return email;
        }
    }
    logger.logMessage(QString("Email not found for account: %1").arg(accountNumber));
    return "";
}





#include "DeleteAccountHandler.h"

// Include the header file for DeleteAccountHandler class

DeleteAccountHandler::DeleteAccountHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for DeleteAccountHandler class, initializing with a reference to BankDataBase instance

void DeleteAccountHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the account number.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }
    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    // Extract the account number from RequestParts and store it in QString accountNumber

    // Attempt to delete the client from the database
    bool success = dataBase.deleteClient(accountNumber);
    // Call deleteClient method on dataBase (BankDataBase instance) with accountNumber as parameter, store success status

    if (success)
    {
        statusMessage = QString("Client account with account number %1 has been successfully deleted.").arg(accountNumber);
        // If deletion is successful, set statusMessage to indicate successful deletion with the account number
    }
    else
    {
        statusMessage = QString("Failed to delete client account with account number %1. The account may not exist.").arg(accountNumber);
        // If deletion fails, set statusMessage to indicate failure with the account number
    }
}
#include "GetAccountBalanceHandler.h"

// Include the header file for GetAccountBalanceHandler class

GetAccountBalanceHandler::GetAccountBalanceHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetAccountBalanceHandler class, initializing with a reference to BankDataBase instance

void GetAccountBalanceHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the username or account number.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming the identifier (account number) is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

    // Flag to check if client is found
    bool clientFound = false;
    QString balance;
    QString userName;

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            balance = record["Balance"].toString();
            userName = record["Username"].toString();
            clientFound = true;
            break;
        }
    }

    if (clientFound)
    {
        statusMessage = QString("The account balance for %1 is %2.").arg(userName, balance);
        // If client is found, set statusMessage to indicate the account balance for the user
    }
    else
    {
        statusMessage = QString("Client with account number %1 not found.").arg(accountNumber);
        // If client is not found, set statusMessage to indicate client not found with the account number
    }
}
#include "GetAccountNumberHandler.h"

// Include the header file for GetAccountNumberHandler class

GetAccountNumberHandler::GetAccountNumberHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetAccountNumberHandler class, initializing with a reference to BankDataBase instance

void GetAccountNumberHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide username or identifier.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }

    QString username = RequestParts[1]; // Assuming username is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

    // Search for the username in databaseRecords
    QString accountNumber;
    bool userFound = false;
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            accountNumber = record["AccountNumber"].toString(); // Adjust this based on your actual JSON structure
            userFound = true;
            break;
        }
    }

    // Check if the username was found
    if(userFound)
    {
        // Send the account number as a response
        statusMessage = QString("Account number for %1 is: %2").arg(username).arg(accountNumber);
        // If username is found, set statusMessage to indicate the account number associated with the username
    }
    else
    {
        // Send an error message if the username was not found
        statusMessage = QString("Account number for %1 not found.").arg(username);
        // If username is not found, set statusMessage to indicate that the account number was not found
    }
}
#include "GetBankDataBaseHandler.h"

// Include the header file for GetBankDataBaseHandler class

GetBankDataBaseHandler::GetBankDataBaseHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetBankDataBaseHandler class, initializing with a reference to BankDataBase instance

void GetBankDataBaseHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure the request is valid
    if (RequestParts.isEmpty() || RequestParts[0] != "GetBankDataBase")
    {
        statusMessage = "Invalid request. Expected 'GetBankDataBase'.";
        // If RequestParts is empty or the first element is not "GetBankDataBase", set statusMessage to indicate invalid request
        return;
    }

    // Get the bank database records
    QVector<QJsonObject> bankRecords = dataBase.getMainDatabase();
    // Retrieve the main database records from the BankDataBase instance

    // Prepare the response
    QJsonArray bankRecordsArray;
    for (const auto& record : bankRecords)
    {
        bankRecordsArray.append(record);
        // Append each record from bankRecords to bankRecordsArray
    }

    QJsonDocument doc(bankRecordsArray);
    // Create a JSON document from the bankRecordsArray

    statusMessage = "ViewBankDataBase:" + QString(doc.toJson(QJsonDocument::Compact));
    // Set statusMessage to indicate the response, including the JSON document converted to a compact JSON string
}
#include "GetTransactionHistoryHandler.h"

// Include the header file for GetTransactionHistoryHandler class

GetTransactionHistoryHandler::GetTransactionHistoryHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetTransactionHistoryHandler class, initializing with a reference to BankDataBase instance

void GetTransactionHistoryHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and history count.";
        // If RequestParts has less than 3 elements, set statusMessage to indicate invalid request
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    bool isNumber;
    int historyCount = RequestParts[2].toInt(&isNumber);
    // Convert the third element of RequestParts to an integer for history count validation

    // Validate the history count
    if (!isNumber || historyCount <= 0 || historyCount > 20)
    {
        statusMessage = "Invalid history count. Please provide a number between 1 and 20.";
        // If historyCount is not a valid number or out of range, set statusMessage to indicate invalid history count
        return;
    }

    // Get the transaction database records
    QVector<QJsonObject> transactionRecords = dataBase.getTransactionDatabase();
    // Retrieve the transaction database records from the BankDataBase instance

    // Find the account transactions
    QJsonObject accountTransactions;
    bool accountFound = false;
    for (const auto& record : transactionRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            accountTransactions = record;
            accountFound = true;
            break;
        }
    }

    // Check if the account was found
    if (!accountFound)
    {
        statusMessage = "Account not found.";
        // If accountNumber not found in transaction records, set statusMessage to indicate account not found
        return;
    }

    // Get the transactions array
    QJsonArray transactionsArray = accountTransactions["Transactions"].toArray();
    // Retrieve the transactions array from accountTransactions

    // Prepare the response with recent transactions
    QJsonArray recentTransactions;
    int transactionsCount = transactionsArray.size();
    for (int i = transactionsCount - historyCount; i < transactionsCount; ++i)
    {
        if (i >= 0)
        {
            recentTransactions.append(transactionsArray[i]);
            // Append recent transactions from transactionsArray based on historyCount
        }
    }

    // Create JSON response object
    QJsonObject response;
    response["AccountNumber"] = accountNumber;
    response["RecentTransactions"] = recentTransactions;

    // Convert response object to JSON document and set statusMessage
    QJsonDocument doc(response);
    statusMessage = "TransactionHistory:" + QString(doc.toJson(QJsonDocument::Compact));
    // Set statusMessage to indicate the response, including the JSON document converted to a compact JSON string
}
// Logger.cpp
#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

Logger::Logger() {} // Constructor for Logger class
Logger::~Logger() {} // Destructor for Logger class

void Logger::logMessage(const QString &message)
{
    QFile file("Serverlog.log");  // Specify the log file path
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file); // QTextStream object for writing to the file
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " - " << message << "\n";
        // Write current date and time, along with the log message, to the file
        file.close(); // Close the file after writing
    }
    else
    {
        qDebug() << "Error: Serverlog.txt Cannot open or not found" << Qt::endl;
        // Output debug message if the log file cannot be opened
    }
}
// LoginCommand.cpp
#include "LoginHandler.h"

// Constructor for LoginHandler, initializing with a reference to BankDataBase
LoginHandler::LoginHandler(BankDataBase &db) : dataBase(db) {}

// Execute function implementation, handling login requests
void LoginHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 3 elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide username and password.";
        return;
    }

    const QString userName = RequestParts[1]; // Extract username from RequestParts
    const QString passWord = RequestParts[2]; // Extract password from RequestParts
    bool isUserValid = false; // Flag to track if user is valid
    QString userAuthority; // Variable to store user authority level
    QString userAccountNumber; // Variable to store user account number
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Retrieve main database records

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        // Check if username and password match
        if (record["Username"].toString() == userName && record["Password"].toString() == passWord)
        {
            // Check if the user is not already logged in
            if (record["Login"].toString() == "0")
            {
                isUserValid = true; // Mark user as valid
                userAuthority = record["Authority"].toString(); // Capture user authority
                userAccountNumber = record["AccountNumber"].toString(); // Capture user account number
                break; // Exit loop as user is found
            }
            else
            {
                statusMessage = "Login failed. This account is already logged in.";
                return; // Exit function as login is not possible
            }
        }
    }

    // Process based on whether user is valid or not
    if (isUserValid)
    {
        // Change the 'log' state in the database
        if (dataBase.setUserLoginState(userName, "1"))
        {
            // Prepare success message with user authority, username, and account number
            QString successMessage = QString("%1:%2:%3").arg(userAuthority, userName, userAccountNumber);
            statusMessage = successMessage; // Set status message to success message
        }
        else
        {
            statusMessage = "Login failed. Could not update the login state."; // Error updating login state
        }
    }
    else
    {
        statusMessage = "Login failed. Incorrect username or password."; // Username or password incorrect
    }
}
#include <QCoreApplication> // Include the Qt core application header

#include "Server.h" // Include your Server class header file

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // Create a Qt application instance

    Server MyServer; // Create an instance of your Server class

    MyServer.StartServer(); // Call the StartServer method of your Server instance to start the server

    return a.exec(); // Start the Qt event loop and run the application
}
#include "MakeTransactionHandler.h" // Include the header file for MakeTransactionHandler

MakeTransactionHandler::MakeTransactionHandler(BankDataBase &db) : dataBase(db) {} // Constructor initialization for MakeTransactionHandler

void MakeTransactionHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and transaction amount."; // Check if enough parameters are provided
        return;
    }

    QString accountNumber = RequestParts[1]; // Extract account number from RequestParts
    QString amount = RequestParts[2]; // Extract transaction amount from RequestParts

    // Validate the amount
    bool isNumber;
    int transactionAmount = amount.toInt(&isNumber); // Convert amount to integer
    if (!isNumber)
    {
        statusMessage = "Invalid transaction amount."; // Handle invalid amount
        return;
    }

    bool success = false;
    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1); // Remove the negative sign for withdrawal
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount); // Withdraw money from the account
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount); // Deposit money into the account
    }
    else
    {
        statusMessage = "Transaction amount cannot be zero."; // Zero transaction amount not allowed
        return;
    }

    if (success)
    {
        statusMessage = "Transaction successful."; // Update status message for successful transaction
        sendEmail(accountNumber, amount); // Send transaction notification email
    }
    else
    {
        statusMessage = "Transaction failed. Insufficient balance."; // Handle failed transaction due to insufficient balance
    }
}

void MakeTransactionHandler::sendEmail(const QString &accountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString body;

    if (amountStr.startsWith('-'))
    {
        body = QString("Dear User, You have withdrawn %1 L.E from your account. Best regards, IMT Bank").arg(amountStr.mid(1)); // Remove the negative sign for withdrawal email notification
    }
    else
    {
        body = QString("Dear User, You have deposited %1 L.E into your account. Best regards, IMT Bank").arg(amountStr); // Deposit email notification
    }

    QString emailAddr = dataBase.getEmailByAccountNumber(accountNumber); // Get email address associated with the account

    // Send the email
    email.send(emailAddr, subject, body); // Call function to send email notification
}
#include "MakeTransferHandler.h" // Include the header file for MakeTransferHandler

MakeTransferHandler::MakeTransferHandler(BankDataBase &db) : dataBase(db) {} // Constructor initialization for MakeTransferHandler

void MakeTransferHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() != 4)
    {
        statusMessage = "Invalid request."; // Check if the request contains exactly 4 parts
    }

    QString sourceAccountNumber = RequestParts[1]; // Extract source account number from RequestParts
    QString targetAccountNumber = RequestParts[2]; // Extract target account number from RequestParts
    QString amountStr = RequestParts[3]; // Extract transfer amount from RequestParts

    // Validate that the account numbers are digits only
    QRegularExpression accountNumberRegex("^\\d+$");
    if (!accountNumberRegex.match(sourceAccountNumber).hasMatch() || !accountNumberRegex.match(targetAccountNumber).hasMatch())
    {
        statusMessage = "Invalid account number format."; // Validate account number format
        return;
    }

    // Validate the amount
    bool isNumber;
    int amount = amountStr.toInt(&isNumber); // Convert amount to integer
    if (!isNumber || amount <= 0)
    {
        statusMessage = "Invalid transfer amount."; // Handle invalid transfer amount
        return;
    }

    // Ensure source and target account numbers are not the same
    if (sourceAccountNumber == targetAccountNumber)
    {
        statusMessage = "Source and target account numbers cannot be the same."; // Prevent transfer between same accounts
        return;
    }

    bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber, amountStr); // Perform money transfer

    if (success)
    {
        statusMessage = QString("TransferResult:Transfer successful."); // Update status message for successful transfer
        sendEmail(sourceAccountNumber, targetAccountNumber, amountStr); // Send email notifications
    }
    else
    {
        statusMessage = QString("TransferResult:Transfer failure. Insufficient balance."); // Handle transfer failure
    }
}

void MakeTransferHandler::sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString sourceBody = QString("Dear User, You have transferred %1 L.E to account %2. Best regards, IMT Bank").arg(amountStr).arg(targetAccountNumber); // Email body for source account
    QString targetBody = QString("Dear User, You have received %1 L.E from account %2. Best regards, IMT Bank").arg(amountStr).arg(sourceAccountNumber); // Email body for target account

    // Retrieve email addresses from the database
    QString sourceEmail = dataBase.getEmailByAccountNumber(sourceAccountNumber); // Get source account email
    QString targetEmail = dataBase.getEmailByAccountNumber(targetAccountNumber); // Get target account email

    // Send emails
    email.send(sourceEmail, subject, sourceBody); // Send email to source account holder
    email.send(targetEmail, subject, targetBody); // Send email to target account holder
}
#ifndef ADDCLIENTHANDLER_H
#define ADDCLIENTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The AddClientHandler class handles requests to add a new client to the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the client addition.

class AddClientHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    AddClientHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status string.
    // It processes the request to add a new client and updates the status accordingly.
    void execute(const QStringList &RequestParts, QString &status) override;

private:
    // Reference to the BankDataBase object where the new client will be added.
    BankDataBase &dataBase;
};

#endif // ADDCLIENTHANDLER_H
#ifndef BANKDATABASE_H
#define BANKDATABASE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QString>
#include <QRandomGenerator>
#include <QVector>
#include "Logger.h"

// The BankDataBase class manages the data related to clients and transactions in the bank system.
// It provides functionalities to initialize, retrieve, and manipulate database records.

class BankDataBase : public QObject
{
    Q_OBJECT
public:
    // Constructor to initialize the BankDataBase object with an optional parent.
    explicit BankDataBase(QObject *parent = nullptr);

private:
    // Private members to store the database records and file paths.
    QVector<QJsonObject> mainDatabaseRecords;        // Vector holding data from the main database file.
    QVector<QJsonObject> transactionDatabaseRecords; // Vector holding data from the transaction database file.
    QString mainDatabaseFilePath;                    // Path to the main database file.
    QString transactionFilePath;                     // Path to the transaction database file.
    Logger logger;                                   // Logger for logging messages and errors.

public:
    // Initialization methods
    void initializeMainDatabase();                  // Initialize main database from file.
    void initializeTransactionDatabase();           // Initialize transaction database from file.

    // Getters
    QVector<QJsonObject> getMainDatabase();         // Retrieve data from the main database file.
    QVector<QJsonObject> getTransactionDatabase();  // Retrieve data from the transaction database file.

    // Database operations
    bool addClient(const QString &username, const QString &password, const QString &fullName, const QString &age,
                   const QString &email, const QString &balance); // Add new client data.
    bool deleteClient(const QString &accountNumber);             // Delete a client from the database.
    bool updateClient(const QString &accountNumber, const QString &username, const QString &password,
                      const QString &fullName, const QString &age, const QString &email); // Update client information.
    bool saveMainDatabaseToFile();                               // Save the main database to the file.
    bool saveTransactionDatabaseToFile();                        // Save the transaction database to the file.
    bool setUserLoginState(const QString& username, const QString& state); // Set the login state of a user.

    // Transaction operations
    bool transferMoney(const QString &sourceAccountNumber, const QString &targetAccountNumber,
                       const QString &amountStr);                // Transfer money between accounts.
    bool withdrawMoney(const QString &accountNumber, const QString &amount); // Withdraw money from an account.
    bool depositMoney(const QString &accountNumber, const QString &amount);  // Deposit money into an account.

    // Utility methods
    QString generateAccountNumber();                             // Generate a unique account number.
    QString getEmailByAccountNumber(const QString &accountNumber); // Get email by account number.

};

#endif // BANKDATABASE_H
#ifndef DELETEACCOUNTHANDLER_H
#define DELETEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The DeleteAccountHandler class handles requests to delete an account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the account deletion.

class DeleteAccountHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    DeleteAccountHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to delete an account and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object where the account will be deleted.
    BankDataBase &dataBase;
};

#endif // DELETEACCOUNTHANDLER_H
#ifndef GETACCOUNTBALANCEHANDLER_H
#define GETACCOUNTBALANCEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetAccountBalanceHandler class handles requests to retrieve the balance of an account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the balance retrieval.

class GetAccountBalanceHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetAccountBalanceHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the account balance and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the account balance will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETACCOUNTBALANCEHANDLER_H
#ifndef GETACCOUNTNUMBERHANDLER_H
#define GETACCOUNTNUMBERHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetAccountNumberHandler class handles requests to retrieve the account number associated with a specific client from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the account number retrieval.

class GetAccountNumberHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetAccountNumberHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the account number and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the account number will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETACCOUNTNUMBERHANDLER_H
#ifndef GETBANKDATABASEHANDLER_H
#define GETBANKDATABASEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetBankDataBaseHandler class handles requests to retrieve the entire bank database.
// It inherits from RequestHandler and overrides the execute method to perform the database retrieval.

class GetBankDataBaseHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetBankDataBaseHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the entire bank database and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the entire database will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETBANKDATABASEHANDLER_H
#ifndef GETTRANSACTIONHISTORYHANDLER_H
#define GETTRANSACTIONHISTORYHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetTransactionHistoryHandler class handles requests to retrieve the transaction history for a specific account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the transaction history retrieval.

class GetTransactionHistoryHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetTransactionHistoryHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the transaction history for a specific account and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the transaction history will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETTRANSACTIONHISTORYHANDLER_H
#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

// The Logger class provides functionality to log messages.
// It allows other classes and components to log messages to a specified output.
class Logger
{
public:
    // Constructor: Initializes the Logger instance.
    Logger();

    // Destructor: Cleans up resources used by the Logger instance.
    ~Logger();

    // logMessage method logs a message to the logger.
    // Parameters:
    // - message: The message to be logged, provided as a QString.
    void logMessage(const QString &message);
};

#endif // LOGGER_H
#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The LoginHandler class handles requests to authenticate and log in a user.
// It inherits from RequestHandler and overrides the execute method to perform the login operation.

class LoginHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    LoginHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to authenticate and log in a user and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for user authentication and login.
    BankDataBase &dataBase;
};

#endif // LOGINHANDLER_H
#ifndef MAKETRANSACTIONHANDLER_H
#define MAKETRANSACTIONHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"
#include "SendEmail.h"

// The MakeTransactionHandler class handles requests to make transactions (e.g., money transfers) in the bank system.
// It inherits from RequestHandler and overrides the execute method to perform the transaction operation.

class MakeTransactionHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    MakeTransactionHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to make a transaction and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for performing transaction operations.
    BankDataBase &dataBase;

    // Email utility object to send transaction notification emails.
    SendEmail email;

    // Private method to send an email notification about the transaction.
    // Parameters:
    // - sourceAccountNumber: The account number from which the transaction originates.
    // - amountStr: The amount of money involved in the transaction as a QString.
    void sendEmail(const QString &sourceAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSACTIONHANDLER_H
#ifndef MAKETRANSFERHANDLER_H
#define MAKETRANSFERHANDLER_H

#include "RequestHandler.h"
#include "SendEmail.h"
#include "BankDataBase.h"

// The MakeTransferHandler class handles requests to transfer money between accounts in the bank system.
// It inherits from RequestHandler and overrides the execute method to perform the transfer operation.

class MakeTransferHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    MakeTransferHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to transfer money between accounts and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for performing transfer operations.
    BankDataBase &dataBase;

    // Email utility object to send transaction notification emails.
    SendEmail email;

    // Private method to send an email notification about the transfer.
    // Parameters:
    // - sourceAccountNumber: The account number from which the transfer originates.
    // - targetAccountNumber: The account number to which the transfer is made.
    // - amountStr: The amount of money involved in the transfer as a QString.
    void sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSFERUPS_HANDLER_H
#ifndef QAESENCRYPTION_H
#define QAESENCRYPTION_H

#ifdef QtAES_EXPORTS
#include "qtaes_export.h"
#else
#define QTAESSHARED_EXPORT
#endif

#include <QObject>
#include <QByteArray>

#ifdef __linux__
#ifndef __LP64__
#define do_rdtsc _do_rdtsc
#endif
#endif

class QTAESSHARED_EXPORT QAESEncryption : public QObject
{
    Q_OBJECT
public:
    enum Aes {
        AES_128,
        AES_192,
        AES_256
    };

    enum Mode {
        ECB,
        CBC,
        CFB,
        OFB
    };

    enum Padding {
      ZERO,
      PKCS7,
      ISO
    };

    /*!
     * \brief static method call to encrypt data given by rawText
     * \param level:    AES::Aes level
     * \param mode:     AES::Mode mode
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \param padding:  AES::Padding standard
     * \return encrypted cipher
     */
    static QByteArray Crypt(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &rawText, const QByteArray &key,
                            const QByteArray &iv = QByteArray(), QAESEncryption::Padding padding = QAESEncryption::ISO);
    /*!
     * \brief static method call to decrypt data given by rawText
     * \param level:    AES::Aes level
     * \param mode:     AES::Mode mode
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \param padding:  AES::Padding standard
     * \return decrypted cipher with padding
     */
    static QByteArray Decrypt(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &rawText, const QByteArray &key,
                              const QByteArray &iv = QByteArray(), QAESEncryption::Padding padding = QAESEncryption::ISO);
    /*!
     * \brief static method call to expand the user key to fit the encrypting/decrypting algorithm
     * \param level:            AES::Aes level
     * \param mode:             AES::Mode mode
     * \param key:              user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param expKey:           output expanded key
     * \param isEncryptionKey:    always 'true' || only 'false' when DECRYPTING in CBC or EBC mode with aesni (check if supported)
     * \return AES-ready key
     */
    static QByteArray ExpandKey(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &key, bool isEncryptionKey);

    /*!
     * \brief static method call to remove padding from decrypted cipher given by rawText
     * \param rawText:  inputText
     * \param padding:  AES::Padding standard
     * \return decrypted cipher with padding removed
     */
    static QByteArray RemovePadding(const QByteArray &rawText, QAESEncryption::Padding padding = QAESEncryption::ISO);

    QAESEncryption(QAESEncryption::Aes level, QAESEncryption::Mode mode,
                   QAESEncryption::Padding padding = QAESEncryption::ISO);



    /*!
     * \brief object method call to encrypt data given by rawText
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \return encrypted cipher
     */
    QByteArray encode(const QByteArray &rawText, const QByteArray &key, const QByteArray &iv = QByteArray());

    /*!
     * \brief object method call to decrypt data given by rawText
     * \param rawText:  input text
     * \param key:      user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param iv:       initialisation-vector (iv.size is 128 bits (16 Bytes))
     * \param padding:  AES::Padding standard
     * \return decrypted cipher with padding
     */
    QByteArray decode(const QByteArray &rawText, const QByteArray &key, const QByteArray &iv = QByteArray());

    /*!
     * \brief object method call to expand the user key to fit the encrypting/decrypting algorithm
     * \param key:              user-key (key.size either 128, 192, 256 bits depending on AES::Aes)
     * \param isEncryptionKey:    always 'true' || only 'false' when DECRYPTING in CBC or EBC mode with aesni (check if supported)
     * \return AES-ready key
     */
    QByteArray expandKey(const QByteArray &key, bool isEncryptionKey);

    /*!
     * \brief object method call to remove padding from decrypted cipher given by rawText
     * \param rawText:  inputText
     * \return decrypted cipher with padding removed
     */
    QByteArray removePadding(const QByteArray &rawText);

    QByteArray printArray(uchar *arr, int size);
Q_SIGNALS:

public Q_SLOTS:

private:
    int m_nb;
    int m_blocklen;
    int m_level;
    int m_mode;
    int m_nk;
    int m_keyLen;
    int m_nr;
    int m_expandedKey;
    int m_padding;
    bool m_aesNIAvailable;
    QByteArray* m_state;

    struct AES256{
        int nk = 8;
        int keylen = 32;
        int nr = 14;
        int expandedKey = 240;
        int userKeySize = 256;
    };

    struct AES192{
        int nk = 6;
        int keylen = 24;
        int nr = 12;
        int expandedKey = 209;
        int userKeySize = 192;
    };

    struct AES128{
        int nk = 4;
        int keylen = 16;
        int nr = 10;
        int expandedKey = 176;
        int userKeySize = 128;
    };

    quint8 getSBoxValue(quint8 num){return sbox[num];}
    quint8 getSBoxInvert(quint8 num){return rsbox[num];}

    void addRoundKey(const quint8 round, const QByteArray &expKey);
    void subBytes();
    void shiftRows();
    void mixColumns();
    void invMixColumns();
    void invSubBytes();
    void invShiftRows();
    QByteArray getPadding(int currSize, int alignment);
    QByteArray cipher(const QByteArray &expKey, const QByteArray &in);
    QByteArray invCipher(const QByteArray &expKey, const QByteArray &in);
    QByteArray byteXor(const QByteArray &a, const QByteArray &b);

    const quint8 sbox[256] = {
      //0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
      0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
      0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
      0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
      0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
      0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
      0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
      0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
      0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
      0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
      0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
      0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
      0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
      0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
      0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
      0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
      0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

    const quint8 rsbox[256] = {
      0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
      0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
      0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
      0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
      0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
      0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
      0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
      0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
      0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
      0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
      0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
      0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
      0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
      0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
      0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
      0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };

    // The round constant word array, Rcon[i], contains the values given by
    // x to th e power (i-1) being powers of x (x is denoted as {02}) in the field GF(2^8)
    // Only the first 14 elements are needed
    const quint8 Rcon[14] = {
        0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab};
};

#endif // QAESENCRYPTION_H
#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QStringList>
#include <QString>

// The RequestHandler class is an abstract base class for handling requests.
// Subclasses must override the execute method to define specific request handling logic.

class RequestHandler {
public:
    // Virtual destructor ensures proper cleanup of derived classes.
    virtual ~RequestHandler() = default;

    // Pure virtual function to execute a request.
    // Parameters:
    // - RequestParts: A QStringList containing parsed parts of the request.
    // - statusMessage: A QString reference to update with the execution status or response.
    virtual void execute(const QStringList &RequestParts, QString &statusMessage) = 0;
};

#endif // REQUESTHANDLER_H
#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QString>
#include <QProcess>
#include <QDebug>
#include "Logger.h"

// The SendEmail class provides functionality to send email notifications.
// It uses QProcess to invoke the email sending command-line tool and logs operations using the Logger.

class SendEmail
{
public:
    // Constructor: Initializes an instance of SendEmail.
    SendEmail();

    // send method sends an email with specified parameters.
    // Parameters:
    // - to: The recipient email address.
    // - subject: The subject of the email.
    // - body: The body content of the email.
    void send(const QString &to, const QString &subject, const QString &body);

private:
    QString to;         // The recipient email address.
    QString subject;    // The subject of the email.
    QString body;       // The body content of the email.
    Logger logger;      // Logger instance for logging email sending operations.
};

#endif // SENDEMAIL_H
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTextStream>
#include <QDebug>
#include <ServerHandler.h>
#include "Logger.h"

// The Server class inherits QTcpServer and handles incoming client connections.
// It starts a TCP server and manages incoming connections by spawning ServerHandler instances.

class Server : public QTcpServer
{
    Q_OBJECT
public:
    // Constructor: Initializes an instance of Server.
    explicit Server(QObject *parent = nullptr);

    // StartServer method starts the TCP server.
    void StartServer();

signals:

protected:
    // Override of QTcpServer's incomingConnection method.
    // Handles incoming client connections by spawning ServerHandler instances.
    void incomingConnection(qintptr handle) override;

private:
    qint32 Port;     // Port number on which the server listens for incoming connections.
    Logger logger;   // Logger instance for logging server operations.
};

#endif // SERVER_H
#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QMap>
#include "BankDataBase.h"
#include "Logger.h"
#include "RequestHandler.h"
#include "LoginHandler.h"
#include "AddClientHandler.h"
#include "DeleteAccountHandler.h"
#include "GetAccountBalanceHandler.h"
#include "GetAccountNumberHandler.h"
#include "GetTransactionHistoryHandler.h"
#include "MakeTransactionHandler.h"
#include "MakeTransferHandler.h"
#include "UpdateAccountHandler.h"
#include "GetBankDataBaseHandler.h"
#include "qaesencryption.h"

// The ServerHandler class manages individual client connections in a multithreaded TCP server application.
// It handles client requests, delegates them to appropriate handlers, and manages server-side operations.

class ServerHandler : public QThread
{
    Q_OBJECT
public:
    // Constructor: Initializes an instance of ServerHandler.
    // Parameters:
    // - ID: Unique identifier for the client connection.
    // - parent: Optional parent object.
    explicit ServerHandler(qint32 ID, QObject *parent = nullptr);

public slots:
    // Slot: Triggered when data is ready to be read from the socket.
    void onReadyRead();

    // Slot: Triggered when the client disconnects from the server.
    void onDisconnected();

protected:
    // Override of QThread's run method.
    // Manages the main execution logic of the server handler.
    void run() override;

private:
    qint32 userID;                           // Unique identifier for the client connection.
    QTcpSocket *Socket;                      // Socket for communication with the client.
    BankDataBase dataBase;                   // Database instance for managing client data.
    QString statusMessage;                   // Status message to communicate with clients.
    QString loginUser;                       // Logged-in user's username.
    bool loginStatus;                        // Flag indicating login status.
    Logger logger;                           // Logger instance for logging server operations.
    QMap<QString, RequestHandler*> requestHandlerMap; // Map of request handlers for different types of requests.

    // Initializes request handlers for various client requests.
    void setupRequestHandles();

    // Processes a client request.
    // Parameters:
    // - Request: The request received from the client.
    void Operation(QString Request);

    // Sends a response message to the client.
    // Parameters:
    // - Message: The message to send as a response.
    void sendResponse(const QString &Message);

    // Decrypts incoming encrypted data from the client.
    // Parameters:
    // - encryptedData: Encrypted data received from the client.
    // Returns:
    // Decrypted data as QByteArray.
    QByteArray decryptRequest(const QByteArray &encryptedData);
};

#endif // SERVERHANDLER_H
#ifndef UPDATEACCOUNTHANDLER_H
#define UPDATEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// UpdateAccountHandler class handles requests to update client account information.
// It interacts with BankDataBase to perform updates and manages the response status.

class UpdateAccountHandler : public RequestHandler
{
public:
    // Constructor: Initializes an instance of UpdateAccountHandler.
    // Parameters:
    // - db: Reference to the BankDataBase instance for database operations.
    UpdateAccountHandler(BankDataBase &db);

    // Override of execute method from RequestHandler.
    // Processes the request to update client account information.
    // Parameters:
    // - RequestParts: Parts of the request parsed into a QStringList.
    // - statusMessage: Reference to a QString to update with the execution status or response.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase; // Reference to the BankDataBase instance for database operations.
};

#endif // UPDATEACCOUNTHANDLER_H
#include "AddClientHandler.h"

// Constructor: Initializes an instance of AddClientHandler.
// Parameters:
// - db: Reference to the BankDataBase instance for database operations.
AddClientHandler::AddClientHandler(BankDataBase &db) : dataBase(db) {}

// Override of execute method from RequestHandler.
// Processes the request to add a new client to the database.
// Parameters:
// - RequestParts: Parts of the request parsed into a QStringList.
// - statusMessage: Reference to a QString to update with the execution status or response.
void AddClientHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 7 elements (full name, username, password, age, email, balance)
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields: full name, username, password, age, email, and balance.";
        return;
    }

    // Extract request parameters
    const QString fullName = RequestParts[1];
    const QString userName = RequestParts[2];
    const QString password = RequestParts[3];
    const QString ageStr = RequestParts[4];
    const QString email = RequestParts[5];
    const QString balanceStr = RequestParts[6];

    // Check if username already exists in the database
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == userName)
        {
            statusMessage = "This username is already taken. Please choose a different username.";
            return;
        }
    }

    // Attempt to add the new client to the database
    if (dataBase.addClient(userName, password, fullName, ageStr, email, balanceStr))
    {
        statusMessage = QString("Congratulations! New user '%1' has been added. Welcome aboard").arg(userName);
    }
    else
    {
        statusMessage = QString("Sadly, new user '%1' couldn't be added to the database. Please try again.").arg(userName);
    }
}
#include "BankDataBase.h"

BankDataBase::BankDataBase(QObject *parent)
    : QObject{parent},
    mainDatabaseFilePath{"mainDataBase.json"},
    transactionFilePath{"transactionDataBase.json"}
{}

void BankDataBase::initializeMainDatabase()
{
    QFile file(mainDatabaseFilePath); // Open QFile for main database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        logger.logMessage("Error: Cannot open main database file");
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        logger.logMessage("Error: Failed to parse JSON from main database file");
        return;
    }

    if (!jsonDoc.isArray())
    {
        logger.logMessage("Error: Main database file does not contain a JSON array");
        return;
    }

    mainDatabaseRecords.clear(); // Clear existing data in vector

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray for iteration

    // Iterate through JSON array and populate mainDatabaseRecords vector
    for (const auto& jsonValue : jsonArray)
    {
        if (jsonValue.isObject())
        {
            QJsonObject jsonObj = jsonValue.toObject(); // Extract object from array
            mainDatabaseRecords.push_back(jsonObj); // Append object to mainDatabaseRecords vector
        }
        else
        {
            logger.logMessage("Warning: Found non-object element in main database JSON array");
        }
    }
    logger.logMessage("Main database initialized with " + QString::number(mainDatabaseRecords.size()) + " records");
}




void BankDataBase::initializeTransactionDatabase()
{
    QFile file(transactionFilePath); // Open QFile for transaction database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        logger.logMessage("Error: Cannot open transaction database file");
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        logger.logMessage("Error: Failed to parse JSON from transaction database file");
        return;
    }

    if (!jsonDoc.isArray())
    {
        logger.logMessage("Error: Transaction database file does not contain a JSON array");
        return;
    }

    transactionDatabaseRecords.clear(); // Clear existing data in vector

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray for iteration

    // Iterate through JSON array and populate transactionRecords vector
    for (const auto& jsonValue : jsonArray)
    {
        if (jsonValue.isObject())
        {
            QJsonObject jsonObj = jsonValue.toObject(); // Extract object from array
            transactionDatabaseRecords.push_back(jsonObj); // Append object to transactionRecords vector
        }
        else
        {
            logger.logMessage("Warning: Found non-object element in transaction database JSON array");
        }
    }
    logger.logMessage("Transaction database initialized with " + QString::number(transactionDatabaseRecords.size()) + " records");
}


// Getter for retrieving data from the main database file
QVector<QJsonObject> BankDataBase::getMainDatabase()
{
    initializeMainDatabase(); // Ensure data is up-to-date
    return mainDatabaseRecords;
}

// Getter for retrieving data from the transaction database file
QVector<QJsonObject> BankDataBase::getTransactionDatabase()
{
    initializeTransactionDatabase(); // Ensure data is up-to-date
    return transactionDatabaseRecords;
}

bool BankDataBase::addClient(const QString &username, const QString &password, const QString &fullName,
                             const QString &age, const QString &email, const QString &balance )
{
    QString AccountNumber = generateAccountNumber(); // Generate a unique account number

    // Create a new client object
    QJsonObject newClient;
    newClient["Username"] = username;
    newClient["Password"] = password;
    newClient["FullName"] = fullName;
    newClient["Age"] = age;
    newClient["Email"] = email;
    newClient["Authority"] = "Client"; // Assuming new clients are added as regular users
    newClient["AccountNumber"] = AccountNumber;
    newClient["Balance"] = balance; // Initial balance is set to 0
    newClient["Login"] = "0";

    // Append the new client to the main database records
    mainDatabaseRecords.push_back(newClient);
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after adding new client.");
        return false;
    }

    QJsonObject newClientTrans;
    newClientTrans["AccountNumber"] = AccountNumber;
    newClientTrans["Transactions"] = QJsonArray();
    transactionDatabaseRecords.push_back(newClientTrans);

    // Save the updated transaction database to file
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after adding new client.");
        return false;
    }
    logger.logMessage("Client added successfully.");
    return true; // Return true indicating client addition succeeded
}


bool BankDataBase::saveMainDatabaseToFile()
{
    QJsonArray jsonArray; // Create a JSON array to hold database records

    // Convert each QJsonObject in mainDatabaseRecords to QJsonArray
    for (const auto& record : mainDatabaseRecords)
    {
        jsonArray.append(record);
    }

    // Convert QJsonArray to QJsonDocument
    QJsonDocument jsonDoc(jsonArray);

    // Convert QJsonDocument to QByteArray
    QByteArray jsonData = jsonDoc.toJson();

    // Write QByteArray to file
    QFile file(mainDatabaseFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream out(&file);
        out << jsonData;
        file.close();
        logger.logMessage("Main database file saved successfully.");
        return true; // Return true indicating success
    }
    else
    {
        logger.logMessage("Failed to save main database file.");
        return false; // Return false indicating failure
    }
}

bool BankDataBase::saveTransactionDatabaseToFile()
{
    // Create a JSON array to hold transaction records
    QJsonArray jsonArray;

    // Convert each QJsonObject in transactionDatabaseRecords to QJsonArray
    for (const auto& record : transactionDatabaseRecords)
    {
        jsonArray.append(record);
    }

    // Convert QJsonArray to QJsonDocument
    QJsonDocument jsonDoc(jsonArray);

    // Convert QJsonDocument to QByteArray
    QByteArray jsonData = jsonDoc.toJson();

    // Write QByteArray to file
    QFile file(transactionFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream out(&file);
        out << jsonData;
        file.close();
        logger.logMessage("Transaction database file saved successfully.");
        return true;
    }
    else
    {
        logger.logMessage("Failed to save transaction database file.");
        return false;
    }
}

bool BankDataBase::setUserLoginState(const QString& username, const QString& state)
{
    // Find the user in the main database records
    for (auto& record : mainDatabaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            record["Login"] = state; // Update the login state

            // Save the updated main database records
            if (!saveMainDatabaseToFile())
            {
                logger.logMessage("Failed to save main database after updating login state for user: " + username);
                return false;
            }

            logger.logMessage("Login state updated successfully for user: " + username);
            return true;
        }
    }
    // Log and return false if the user was not found
    logger.logMessage("User not found for updating login state: " + username);
    return false;
}



bool BankDataBase::deleteClient(const QString &accountNumber)
{
    // Initialize the main database
    initializeMainDatabase();

    bool mainDatabaseDeleted = false;
    bool transactionDatabaseDeleted = false;

    // Step 1: Remove from Main Database
    for (int i = 0; i < mainDatabaseRecords.size(); ++i)
    {
        if (mainDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            logger.logMessage("Deleting client from main database with AccountNumber: " + accountNumber);
            mainDatabaseRecords.remove(i);
            mainDatabaseDeleted = true;
            break;
        }
    }
    if(mainDatabaseDeleted == false)
    {
        logger.logMessage("This account number not found in main database");
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveMainDatabaseToFile())
        {
            logger.logMessage("Failed to save main database after deleting client.");
            return false;
        }
    }


    // Step 2: Remove from Transaction Database
    for (int i = 0; i < transactionDatabaseRecords.size(); ++i)
    {
        if (transactionDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            logger.logMessage("Deleting client from transaction database with AccountNumber: " + accountNumber);
            transactionDatabaseRecords.remove(i);
            transactionDatabaseDeleted = true;
            break;
        }
    }
    if(transactionDatabaseDeleted == false)
    {
        logger.logMessage("This account number not found in transaction database");
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveTransactionDatabaseToFile())
        {
            logger.logMessage("Failed to save transaction database after deleting client.");
            return false;
        }
    }

    // Return true if both deletions were successful
    return mainDatabaseDeleted && transactionDatabaseDeleted;
}



bool BankDataBase::updateClient(const QString &accountNumber, const QString &username, const QString &password
                                , const QString &fullName,const QString &ageStr, const QString &email)
{
    // Load the main database records
    initializeMainDatabase();
    bool userFound = false;

    // Loop through each record in the database to find the matching user
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            userFound = true;

            // Update only non-empty fields
            if (!username.isEmpty())
            {
                logger.logMessage("Updating username for account number: " + accountNumber);
                record["Username"] = username;
            }
            if (!password.isEmpty())
            {
                logger.logMessage("Updating password for account number: " + accountNumber);
                record["Password"] = password;
            }
            if (!fullName.isEmpty())
            {
                logger.logMessage("Updating full name for account number: " + accountNumber);
                record["FullName"] = fullName;
            }
            bool ok;
            int age = ageStr.toInt(&ok);
            if (ok && age != 0)
            {
                logger.logMessage("Updating age for account number: " + accountNumber);
                record["Age"] = ageStr;
            }
            if (!email.isEmpty())
            {
                logger.logMessage("Updating email for account number: " + accountNumber);
                record["Email"] = email;
            }
            break;
        }
    }

    // Check if the user was found and updated
    if (userFound)
    {
        // Save the updated database to file
        if (saveMainDatabaseToFile())
        {
            logger.logMessage("Account information updated successfully for account number: " + accountNumber);
            return true; // Update successful
        }
        else
        {
            logger.logMessage("Failed to save updated account information for account number: " + accountNumber);
            return false; // Failed to save updated information
        }
    }
    else
    {
        logger.logMessage("Account not found. Update failed for account number: " + accountNumber);
        return false; // Account not found
    }
}



// Update transaction data
bool BankDataBase::transferMoney(const QString &sourceAccountNumber, const QString &targetAccountNumber,
                                 const QString &amountStr)
{
    // Validate the amounts
    bool AmountValid;
    int Amount = amountStr.toInt(&AmountValid);

    if (!AmountValid || Amount <= 0)
    {
        logger.logMessage("Invalid transfer amount from the source account.");
        return false;
    }

    // Check if source and target account numbers are different
    if (sourceAccountNumber == targetAccountNumber)
    {
        logger.logMessage("Source and target account numbers must be different.");
        return false;
    }

    // Find the source and target accounts and update the balances
    bool sourceAccountFound = false;
    bool targetAccountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            QString  currentSourceBalanceStr = record["Balance"].toString();
            int currentSourceBalance = currentSourceBalanceStr.toInt();
            if (currentSourceBalance < Amount)
            {
                logger.logMessage("Insufficient balance in the source account.");
                return false;
            }
            int newSourceBalance = currentSourceBalance - Amount;
            record["Balance"] = QString::number(newSourceBalance);
            sourceAccountFound = true;
        }

        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QString currentTargetBalanceStr = record["Balance"].toString();
            int currentTargetBalance = currentTargetBalanceStr.toInt();
            int newTargetBalance = currentTargetBalance + Amount;
            record["Balance"] = QString::number(newTargetBalance);
            targetAccountFound = true;
        }
    }

    if (!sourceAccountFound)
    {
        logger.logMessage("Source account not found.");
        return false;
    }

    if (!targetAccountFound)
    {
        logger.logMessage("Target account not found.");
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after transfer.");
        return false;
    }

    // Update the transaction record for the source account
    QJsonObject sourceTransaction;
    sourceTransaction["amount"] = "-" + QString::number(Amount);
    sourceTransaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(sourceTransaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    // Update the transaction record for the target account
    QJsonObject targetTransaction;
    targetTransaction["amount"] = "+" + QString::number(Amount);
    targetTransaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(targetTransaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after transfer.");
        return false;
    }

    logger.logMessage("Transfer successful.");
    return true;
}



bool BankDataBase::withdrawMoney(const QString &accountNumber, const QString &amount)
{
    // Validate the amount
    bool isNumber;
    int withdrawAmount = amount.toInt(&isNumber);
    if (!isNumber || withdrawAmount <= 0)
    {
        logger.logMessage("Invalid withdraw amount.");
        return false;
    }

    // Find the account and update the balance
    bool accountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString str = record["Balance"].toString();
            int currentBalance = str.toInt();
            if (withdrawAmount > currentBalance)
            {
                logger.logMessage("Insufficient balance.");
                return false;
            }
            int newBalance = currentBalance - withdrawAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            logger.logMessage("Withdrawal amount of " + QString::number(withdrawAmount) + " for account number: " + accountNumber);
            break;
        }
    }

    if (!accountFound)
    {
        logger.logMessage("Account not found for withdrawal: " + accountNumber);
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after withdrawal for account number: " + accountNumber);
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "-" + QString::number(withdrawAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            logger.logMessage("Updated transaction record for withdrawal for account number: " + accountNumber);
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after withdrawal for account number: " + accountNumber);
        return false;
    }

    logger.logMessage("Withdrawal successful for account number: " + accountNumber);
    return true;
}


bool BankDataBase::depositMoney(const QString &accountNumber, const QString &amount)
{
    // Validate the amount
    bool isNumber;
    int depositAmount = amount.toInt(&isNumber);
    if (!isNumber || depositAmount <= 0)
    {
        logger.logMessage("Invalid deposit amount for account number: " + accountNumber);
        return false;
    }

    // Find the account and update the balance
    bool accountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString str = record["Balance"].toString();
            int currentBalance = str.toInt();
            int newBalance = currentBalance + depositAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            logger.logMessage("Deposited amount of " + QString::number(depositAmount) + " for account number: " + accountNumber);
            break;
        }
    }

    if (!accountFound)
    {
        logger.logMessage("Account not found for deposit: " + accountNumber);
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after deposit for account number: " + accountNumber);
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "+" + QString::number(depositAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            logger.logMessage("Updated transaction record for deposit for account number: " + accountNumber);
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after deposit for account number: " + accountNumber);
        return false;
    }

    logger.logMessage("Deposit successful for account number: " + accountNumber);
    return true;
}

QString BankDataBase::generateAccountNumber()
{
    // Get the current timestamp
    qint64 timestamp = QDateTime::currentSecsSinceEpoch();

    // Generate a random number between 1000 and 9999
    int randomNum = QRandomGenerator::global()->bounded(1000, 10000);

    // Combine the timestamp and the random number to create the account number
    QString accountNumber = QString::number(timestamp).right(5) + QString::number(randomNum);

    // Log the generated account number
    logger.logMessage(QString("Generated account number: %1").arg(accountNumber));

    return accountNumber;
}


QString BankDataBase::getEmailByAccountNumber(const QString &accountNumber)
{
    for (const auto &record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString email = record["Email"].toString();
            logger.logMessage(QString("Email found for account %1: %2").arg(accountNumber, email));
            return email;
        }
    }
    logger.logMessage(QString("Email not found for account: %1").arg(accountNumber));
    return "";
}





#include "DeleteAccountHandler.h"

// Include the header file for DeleteAccountHandler class

DeleteAccountHandler::DeleteAccountHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for DeleteAccountHandler class, initializing with a reference to BankDataBase instance

void DeleteAccountHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the account number.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }
    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    // Extract the account number from RequestParts and store it in QString accountNumber

    // Attempt to delete the client from the database
    bool success = dataBase.deleteClient(accountNumber);
    // Call deleteClient method on dataBase (BankDataBase instance) with accountNumber as parameter, store success status

    if (success)
    {
        statusMessage = QString("Client account with account number %1 has been successfully deleted.").arg(accountNumber);
        // If deletion is successful, set statusMessage to indicate successful deletion with the account number
    }
    else
    {
        statusMessage = QString("Failed to delete client account with account number %1. The account may not exist.").arg(accountNumber);
        // If deletion fails, set statusMessage to indicate failure with the account number
    }
}
#include "GetAccountBalanceHandler.h"

// Include the header file for GetAccountBalanceHandler class

GetAccountBalanceHandler::GetAccountBalanceHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetAccountBalanceHandler class, initializing with a reference to BankDataBase instance

void GetAccountBalanceHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the username or account number.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming the identifier (account number) is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

    // Flag to check if client is found
    bool clientFound = false;
    QString balance;
    QString userName;

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            balance = record["Balance"].toString();
            userName = record["Username"].toString();
            clientFound = true;
            break;
        }
    }

    if (clientFound)
    {
        statusMessage = QString("The account balance for %1 is %2.").arg(userName, balance);
        // If client is found, set statusMessage to indicate the account balance for the user
    }
    else
    {
        statusMessage = QString("Client with account number %1 not found.").arg(accountNumber);
        // If client is not found, set statusMessage to indicate client not found with the account number
    }
}
#include "GetAccountNumberHandler.h"

// Include the header file for GetAccountNumberHandler class

GetAccountNumberHandler::GetAccountNumberHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetAccountNumberHandler class, initializing with a reference to BankDataBase instance

void GetAccountNumberHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide username or identifier.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }

    QString username = RequestParts[1]; // Assuming username is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

    // Search for the username in databaseRecords
    QString accountNumber;
    bool userFound = false;
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            accountNumber = record["AccountNumber"].toString(); // Adjust this based on your actual JSON structure
            userFound = true;
            break;
        }
    }

    // Check if the username was found
    if(userFound)
    {
        // Send the account number as a response
        statusMessage = QString("Account number for %1 is: %2").arg(username).arg(accountNumber);
        // If username is found, set statusMessage to indicate the account number associated with the username
    }
    else
    {
        // Send an error message if the username was not found
        statusMessage = QString("Account number for %1 not found.").arg(username);
        // If username is not found, set statusMessage to indicate that the account number was not found
    }
}
#include "GetBankDataBaseHandler.h"

// Include the header file for GetBankDataBaseHandler class

GetBankDataBaseHandler::GetBankDataBaseHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetBankDataBaseHandler class, initializing with a reference to BankDataBase instance

void GetBankDataBaseHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure the request is valid
    if (RequestParts.isEmpty() || RequestParts[0] != "GetBankDataBase")
    {
        statusMessage = "Invalid request. Expected 'GetBankDataBase'.";
        // If RequestParts is empty or the first element is not "GetBankDataBase", set statusMessage to indicate invalid request
        return;
    }

    // Get the bank database records
    QVector<QJsonObject> bankRecords = dataBase.getMainDatabase();
    // Retrieve the main database records from the BankDataBase instance

    // Prepare the response
    QJsonArray bankRecordsArray;
    for (const auto& record : bankRecords)
    {
        bankRecordsArray.append(record);
        // Append each record from bankRecords to bankRecordsArray
    }

    QJsonDocument doc(bankRecordsArray);
    // Create a JSON document from the bankRecordsArray

    statusMessage = "ViewBankDataBase:" + QString(doc.toJson(QJsonDocument::Compact));
    // Set statusMessage to indicate the response, including the JSON document converted to a compact JSON string
}
#include "GetTransactionHistoryHandler.h"

// Include the header file for GetTransactionHistoryHandler class

GetTransactionHistoryHandler::GetTransactionHistoryHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetTransactionHistoryHandler class, initializing with a reference to BankDataBase instance

void GetTransactionHistoryHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and history count.";
        // If RequestParts has less than 3 elements, set statusMessage to indicate invalid request
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    bool isNumber;
    int historyCount = RequestParts[2].toInt(&isNumber);
    // Convert the third element of RequestParts to an integer for history count validation

    // Validate the history count
    if (!isNumber || historyCount <= 0 || historyCount > 20)
    {
        statusMessage = "Invalid history count. Please provide a number between 1 and 20.";
        // If historyCount is not a valid number or out of range, set statusMessage to indicate invalid history count
        return;
    }

    // Get the transaction database records
    QVector<QJsonObject> transactionRecords = dataBase.getTransactionDatabase();
    // Retrieve the transaction database records from the BankDataBase instance

    // Find the account transactions
    QJsonObject accountTransactions;
    bool accountFound = false;
    for (const auto& record : transactionRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            accountTransactions = record;
            accountFound = true;
            break;
        }
    }

    // Check if the account was found
    if (!accountFound)
    {
        statusMessage = "Account not found.";
        // If accountNumber not found in transaction records, set statusMessage to indicate account not found
        return;
    }

    // Get the transactions array
    QJsonArray transactionsArray = accountTransactions["Transactions"].toArray();
    // Retrieve the transactions array from accountTransactions

    // Prepare the response with recent transactions
    QJsonArray recentTransactions;
    int transactionsCount = transactionsArray.size();
    for (int i = transactionsCount - historyCount; i < transactionsCount; ++i)
    {
        if (i >= 0)
        {
            recentTransactions.append(transactionsArray[i]);
            // Append recent transactions from transactionsArray based on historyCount
        }
    }

    // Create JSON response object
    QJsonObject response;
    response["AccountNumber"] = accountNumber;
    response["RecentTransactions"] = recentTransactions;

    // Convert response object to JSON document and set statusMessage
    QJsonDocument doc(response);
    statusMessage = "TransactionHistory:" + QString(doc.toJson(QJsonDocument::Compact));
    // Set statusMessage to indicate the response, including the JSON document converted to a compact JSON string
}
// Logger.cpp
#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

Logger::Logger() {} // Constructor for Logger class
Logger::~Logger() {} // Destructor for Logger class

void Logger::logMessage(const QString &message)
{
    QFile file("Serverlog.log");  // Specify the log file path
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file); // QTextStream object for writing to the file
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " - " << message << "\n";
        // Write current date and time, along with the log message, to the file
        file.close(); // Close the file after writing
    }
    else
    {
        qDebug() << "Error: Serverlog.txt Cannot open or not found" << Qt::endl;
        // Output debug message if the log file cannot be opened
    }
}
// LoginCommand.cpp
#include "LoginHandler.h"

// Constructor for LoginHandler, initializing with a reference to BankDataBase
LoginHandler::LoginHandler(BankDataBase &db) : dataBase(db) {}

// Execute function implementation, handling login requests
void LoginHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 3 elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide username and password.";
        return;
    }

    const QString userName = RequestParts[1]; // Extract username from RequestParts
    const QString passWord = RequestParts[2]; // Extract password from RequestParts
    bool isUserValid = false; // Flag to track if user is valid
    QString userAuthority; // Variable to store user authority level
    QString userAccountNumber; // Variable to store user account number
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Retrieve main database records

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        // Check if username and password match
        if (record["Username"].toString() == userName && record["Password"].toString() == passWord)
        {
            // Check if the user is not already logged in
            if (record["Login"].toString() == "0")
            {
                isUserValid = true; // Mark user as valid
                userAuthority = record["Authority"].toString(); // Capture user authority
                userAccountNumber = record["AccountNumber"].toString(); // Capture user account number
                break; // Exit loop as user is found
            }
            else
            {
                statusMessage = "Login failed. This account is already logged in.";
                return; // Exit function as login is not possible
            }
        }
    }

    // Process based on whether user is valid or not
    if (isUserValid)
    {
        // Change the 'log' state in the database
        if (dataBase.setUserLoginState(userName, "1"))
        {
            // Prepare success message with user authority, username, and account number
            QString successMessage = QString("%1:%2:%3").arg(userAuthority, userName, userAccountNumber);
            statusMessage = successMessage; // Set status message to success message
        }
        else
        {
            statusMessage = "Login failed. Could not update the login state."; // Error updating login state
        }
    }
    else
    {
        statusMessage = "Login failed. Incorrect username or password."; // Username or password incorrect
    }
}
#include <QCoreApplication> // Include the Qt core application header

#include "Server.h" // Include your Server class header file

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // Create a Qt application instance

    Server MyServer; // Create an instance of your Server class

    MyServer.StartServer(); // Call the StartServer method of your Server instance to start the server

    return a.exec(); // Start the Qt event loop and run the application
}
#include "MakeTransactionHandler.h" // Include the header file for MakeTransactionHandler

MakeTransactionHandler::MakeTransactionHandler(BankDataBase &db) : dataBase(db) {} // Constructor initialization for MakeTransactionHandler

void MakeTransactionHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and transaction amount."; // Check if enough parameters are provided
        return;
    }

    QString accountNumber = RequestParts[1]; // Extract account number from RequestParts
    QString amount = RequestParts[2]; // Extract transaction amount from RequestParts

    // Validate the amount
    bool isNumber;
    int transactionAmount = amount.toInt(&isNumber); // Convert amount to integer
    if (!isNumber)
    {
        statusMessage = "Invalid transaction amount."; // Handle invalid amount
        return;
    }

    bool success = false;
    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1); // Remove the negative sign for withdrawal
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount); // Withdraw money from the account
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount); // Deposit money into the account
    }
    else
    {
        statusMessage = "Transaction amount cannot be zero."; // Zero transaction amount not allowed
        return;
    }

    if (success)
    {
        statusMessage = "Transaction successful."; // Update status message for successful transaction
        sendEmail(accountNumber, amount); // Send transaction notification email
    }
    else
    {
        statusMessage = "Transaction failed. Insufficient balance."; // Handle failed transaction due to insufficient balance
    }
}

void MakeTransactionHandler::sendEmail(const QString &accountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString body;

    if (amountStr.startsWith('-'))
    {
        body = QString("Dear User, You have withdrawn %1 L.E from your account. Best regards, IMT Bank").arg(amountStr.mid(1)); // Remove the negative sign for withdrawal email notification
    }
    else
    {
        body = QString("Dear User, You have deposited %1 L.E into your account. Best regards, IMT Bank").arg(amountStr); // Deposit email notification
    }

    QString emailAddr = dataBase.getEmailByAccountNumber(accountNumber); // Get email address associated with the account

    // Send the email
    email.send(emailAddr, subject, body); // Call function to send email notification
}
#include "MakeTransferHandler.h" // Include the header file for MakeTransferHandler

MakeTransferHandler::MakeTransferHandler(BankDataBase &db) : dataBase(db) {} // Constructor initialization for MakeTransferHandler

void MakeTransferHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() != 4)
    {
        statusMessage = "Invalid request."; // Check if the request contains exactly 4 parts
    }

    QString sourceAccountNumber = RequestParts[1]; // Extract source account number from RequestParts
    QString targetAccountNumber = RequestParts[2]; // Extract target account number from RequestParts
    QString amountStr = RequestParts[3]; // Extract transfer amount from RequestParts

    // Validate that the account numbers are digits only
    QRegularExpression accountNumberRegex("^\\d+$");
    if (!accountNumberRegex.match(sourceAccountNumber).hasMatch() || !accountNumberRegex.match(targetAccountNumber).hasMatch())
    {
        statusMessage = "Invalid account number format."; // Validate account number format
        return;
    }

    // Validate the amount
    bool isNumber;
    int amount = amountStr.toInt(&isNumber); // Convert amount to integer
    if (!isNumber || amount <= 0)
    {
        statusMessage = "Invalid transfer amount."; // Handle invalid transfer amount
        return;
    }

    // Ensure source and target account numbers are not the same
    if (sourceAccountNumber == targetAccountNumber)
    {
        statusMessage = "Source and target account numbers cannot be the same."; // Prevent transfer between same accounts
        return;
    }

    bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber, amountStr); // Perform money transfer

    if (success)
    {
        statusMessage = QString("TransferResult:Transfer successful."); // Update status message for successful transfer
        sendEmail(sourceAccountNumber, targetAccountNumber, amountStr); // Send email notifications
    }
    else
    {
        statusMessage = QString("TransferResult:Transfer failure. Insufficient balance."); // Handle transfer failure
    }
}

void MakeTransferHandler::sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString sourceBody = QString("Dear User, You have transferred %1 L.E to account %2. Best regards, IMT Bank").arg(amountStr).arg(targetAccountNumber); // Email body for source account
    QString targetBody = QString("Dear User, You have received %1 L.E from account %2. Best regards, IMT Bank").arg(amountStr).arg(sourceAccountNumber); // Email body for target account

    // Retrieve email addresses from the database
    QString sourceEmail = dataBase.getEmailByAccountNumber(sourceAccountNumber); // Get source account email
    QString targetEmail = dataBase.getEmailByAccountNumber(targetAccountNumber); // Get target account email

    // Send emails
    email.send(sourceEmail, subject, sourceBody); // Send email to source account holder
    email.send(targetEmail, subject, targetBody); // Send email to target account holder
}
#ifndef ADDCLIENTHANDLER_H
#define ADDCLIENTHANDL#include "qaesencryption.h"

#ifdef USE_INTEL_AES_IF_AVAILABLE
#include "aesni/aesni-key-exp.h"
#include "aesni/aesni-key-init.h"
#include "aesni/aesni-enc-ecb.h"
#include "aesni/aesni-enc-cbc.h"
#endif

/*
 * Static Functions
 * */
QByteArray QAESEncryption::Crypt(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &rawText,
                                 const QByteArray &key, const QByteArray &iv, QAESEncryption::Padding padding)
{
    return QAESEncryption(level, mode, padding).encode(rawText, key, iv);
}

QByteArray QAESEncryption::Decrypt(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &rawText,
                                   const QByteArray &key, const QByteArray &iv, QAESEncryption::Padding padding)
{
     return QAESEncryption(level, mode, padding).decode(rawText, key, iv);
}

QByteArray QAESEncryption::ExpandKey(QAESEncryption::Aes level, QAESEncryption::Mode mode, const QByteArray &key, bool isEncryptionKey)
{
     return QAESEncryption(level, mode).expandKey(key, isEncryptionKey);
}

QByteArray QAESEncryption::RemovePadding(const QByteArray &rawText, QAESEncryption::Padding padding)
{
    if (rawText.isEmpty())
        return rawText;

    QByteArray ret(rawText);
    switch (padding)
    {
    case Padding::ZERO:
        //Works only if the last byte of the decoded array is not zero
        while (ret.at(ret.length()-1) == 0x00)
            ret.remove(ret.length()-1, 1);
        break;
    case Padding::PKCS7:
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
        ret.remove(ret.length() - ret.back(), ret.back());
#else
        ret.remove(ret.length() - ret.at(ret.length() - 1), ret.at(ret.length() - 1));
#endif
        break;
    case Padding::ISO:
    {
        // Find the last byte which is not zero
        int marker_index = ret.length() - 1;
        for (; marker_index >= 0; --marker_index)
        {
            if (ret.at(marker_index) != 0x00)
            {
                break;
            }
        }

        // And check if it's the byte for marking padding
        if (ret.at(marker_index) == '\x80')
        {
            ret.truncate(marker_index);
        }
        break;
    }
    default:
        //do nothing
        break;
    }
    return ret;
}
/*
 * End Static function declarations
 * */

/*
 * Local Functions
 * */

namespace {

quint8 xTime(quint8 x)
{
    return ((x<<1) ^ (((x>>7) & 1) * 0x1b));
}

quint8 multiply(quint8 x, quint8 y)
{
    return (((y & 1) * x) ^ ((y>>1 & 1) * xTime(x)) ^ ((y>>2 & 1) * xTime(xTime(x))) ^ ((y>>3 & 1)
            * xTime(xTime(xTime(x)))) ^ ((y>>4 & 1) * xTime(xTime(xTime(xTime(x))))));
}

}

/*
 * End Local functions
 * */

QAESEncryption::QAESEncryption(Aes level, Mode mode,
                               Padding padding)
    : m_nb(4), m_blocklen(16), m_level(level), m_mode(mode), m_padding(padding)
    , m_aesNIAvailable(false), m_state(nullptr)
{
#ifdef USE_INTEL_AES_IF_AVAILABLE
    m_aesNIAvailable = check_aesni_support();
#endif

    switch (level)
    {
    case AES_128: {
        AES128 aes;
        m_nk = aes.nk;
        m_keyLen = aes.keylen;
        m_nr = aes.nr;
        m_expandedKey = aes.expandedKey;
        }
        break;
    case AES_192: {
        AES192 aes;
        m_nk = aes.nk;
        m_keyLen = aes.keylen;
        m_nr = aes.nr;
        m_expandedKey = aes.expandedKey;
        }
        break;
    case AES_256: {
        AES256 aes;
        m_nk = aes.nk;
        m_keyLen = aes.keylen;
        m_nr = aes.nr;
        m_expandedKey = aes.expandedKey;
        }
        break;
    default: {
        AES128 aes;
        m_nk = aes.nk;
        m_keyLen = aes.keylen;
        m_nr = aes.nr;
        m_expandedKey = aes.expandedKey;
        }
        break;
    }

}
QByteArray QAESEncryption::getPadding(int currSize, int alignment)
{
    int size = (alignment - currSize % alignment) % alignment;
    switch(m_padding)
    {
    case Padding::ZERO:
        return QByteArray(size, 0x00);
        break;
    case Padding::PKCS7:
        if (size == 0)
            size = alignment;
        return QByteArray(size, size);
        break;
    case Padding::ISO:
        if (size > 0)
            return QByteArray (size - 1, 0x00).prepend('\x80');
        break;
    default:
        return QByteArray(size, 0x00);
        break;
    }
    return QByteArray();
}

QByteArray QAESEncryption::expandKey(const QByteArray &key, bool isEncryptionKey)
{

#ifdef USE_INTEL_AES_IF_AVAILABLE
    if (m_aesNIAvailable){
          switch(m_level) {
          case AES_128: {
              AES128 aes128;
              AES_KEY aesKey;
              if(isEncryptionKey){
                  AES_set_encrypt_key((unsigned char*) key.constData(), aes128.userKeySize, &aesKey);
              }else{
                  AES_set_decrypt_key((unsigned char*) key.constData(), aes128.userKeySize, &aesKey);
              }

              QByteArray expKey;
              expKey.resize(aes128.expandedKey);
              memcpy(expKey.data(), (char*) aesKey.KEY, aes128.expandedKey);
              memset(aesKey.KEY, 0, 240);
              return expKey;
          }
              break;
          case AES_192: {
              AES192 aes192;
              AES_KEY aesKey;
              if(isEncryptionKey){
                  AES_set_encrypt_key((unsigned char*) key.constData(), aes192.userKeySize, &aesKey);
              }else{
                  AES_set_decrypt_key((unsigned char*) key.constData(), aes192.userKeySize, &aesKey);
              }

              QByteArray expKey;
              expKey.resize(aes192.expandedKey);
              memcpy(expKey.data(), (char*) aesKey.KEY, aes192.expandedKey);
              memset(aesKey.KEY, 0, 240);
              return expKey;
          }
              break;
          case AES_256: {
              AES256 aes256;
              AES_KEY aesKey;
              if(isEncryptionKey){
                  AES_set_encrypt_key((unsigned char*) key.constData(), aes256.userKeySize, &aesKey);
              }else{
                  AES_set_decrypt_key((unsigned char*) key.constData(), aes256.userKeySize, &aesKey);
              }

              QByteArray expKey;
              expKey.resize(aes256.expandedKey);
              memcpy(expKey.data(), (char*) aesKey.KEY, aes256.expandedKey);
              memset(aesKey.KEY, 0, 240);
              return expKey;
          }
              break;
          default:
              return QByteArray();
              break;
          }
      } else
#endif
  {

      int i, k;
      quint8 tempa[4]; // Used for the column/row operations
      QByteArray roundKey(key); // The first round key is the key itself.

      // All other round keys are found from the previous round keys.
      //i == Nk
      for(i = m_nk; i < m_nb * (m_nr + 1); i++)
      {
        tempa[0] = (quint8) roundKey.at((i-1) * 4 + 0);
        tempa[1] = (quint8) roundKey.at((i-1) * 4 + 1);
        tempa[2] = (quint8) roundKey.at((i-1) * 4 + 2);
        tempa[3] = (quint8) roundKey.at((i-1) * 4 + 3);

        if (i % m_nk == 0)
        {
            // This function shifts the 4 bytes in a word to the left once.
            // [a0,a1,a2,a3] becomes [a1,a2,a3,a0]

            // Function RotWord()
            k = tempa[0];
            tempa[0] = tempa[1];
            tempa[1] = tempa[2];
            tempa[2] = tempa[3];
            tempa[3] = k;

            // Function Subword()
            tempa[0] = getSBoxValue(tempa[0]);
            tempa[1] = getSBoxValue(tempa[1]);
            tempa[2] = getSBoxValue(tempa[2]);
            tempa[3] = getSBoxValue(tempa[3]);

            tempa[0] =  tempa[0] ^ Rcon[i/m_nk];
        }

        if (m_level == AES_256 && i % m_nk == 4)
        {
            // Function Subword()
            tempa[0] = getSBoxValue(tempa[0]);
            tempa[1] = getSBoxValue(tempa[1]);
            tempa[2] = getSBoxValue(tempa[2]);
            tempa[3] = getSBoxValue(tempa[3]);
        }
        roundKey.insert(i * 4 + 0, (quint8) roundKey.at((i - m_nk) * 4 + 0) ^ tempa[0]);
        roundKey.insert(i * 4 + 1, (quint8) roundKey.at((i - m_nk) * 4 + 1) ^ tempa[1]);
        roundKey.insert(i * 4 + 2, (quint8) roundKey.at((i - m_nk) * 4 + 2) ^ tempa[2]);
        roundKey.insert(i * 4 + 3, (quint8) roundKey.at((i - m_nk) * 4 + 3) ^ tempa[3]);
      }
      return roundKey;
  }
}

// This function adds the round key to state.
// The round key is added to the state by an XOR function.
void QAESEncryption::addRoundKey(const quint8 round, const QByteArray &expKey)
{
  QByteArray::iterator it = m_state->begin();
  for(int i=0; i < 16; ++i)
      it[i] = (quint8) it[i] ^ (quint8) expKey.at(round * m_nb * 4 + (i/4) * m_nb + (i%4));
}

// The SubBytes Function Substitutes the values in the
// state matrix with values in an S-box.
void QAESEncryption::subBytes()
{
  QByteArray::iterator it = m_state->begin();
  for(int i = 0; i < 16; i++)
    it[i] = getSBoxValue((quint8) it[i]);
}

// The ShiftRows() function shifts the rows in the state to the left.
// Each row is shifted with different offset.
// Offset = Row number. So the first row is not shifted.
void QAESEncryption::shiftRows()
{
    QByteArray::iterator it = m_state->begin();
    quint8 temp;
    //Keep in mind that QByteArray is column-driven!!

     //Shift 1 to left
    temp   = (quint8)it[1];
    it[1]  = (quint8)it[5];
    it[5]  = (quint8)it[9];
    it[9]  = (quint8)it[13];
    it[13] = (quint8)temp;

    //Shift 2 to left
    temp   = (quint8)it[2];
    it[2]  = (quint8)it[10];
    it[10] = (quint8)temp;
    temp   = (quint8)it[6];
    it[6]  = (quint8)it[14];
    it[14] = (quint8)temp;

    //Shift 3 to left
    temp   = (quint8)it[3];
    it[3]  = (quint8)it[15];
    it[15] = (quint8)it[11];
    it[11] = (quint8)it[7];
    it[7]  = (quint8)temp;
}

// MixColumns function mixes the columns of the state matrix
//optimized!!
void QAESEncryption::mixColumns()
{
  QByteArray::iterator it = m_state->begin();
  quint8 tmp, tm, t;

  for(int i = 0; i < 16; i += 4){
    t       = (quint8)it[i];
    tmp     =  (quint8)it[i] ^ (quint8)it[i+1] ^ (quint8)it[i+2] ^ (quint8)it[i+3] ;

    tm      = xTime( (quint8)it[i] ^ (quint8)it[i+1] );
    it[i]   = (quint8)it[i] ^ (quint8)tm ^ (quint8)tmp;

    tm      = xTime( (quint8)it[i+1] ^ (quint8)it[i+2]);
    it[i+1] = (quint8)it[i+1] ^ (quint8)tm ^ (quint8)tmp;

    tm      = xTime( (quint8)it[i+2] ^ (quint8)it[i+3]);
    it[i+2] =(quint8)it[i+2] ^ (quint8)tm ^ (quint8)tmp;

    tm      = xTime((quint8)it[i+3] ^ (quint8)t);
    it[i+3] =(quint8)it[i+3] ^ (quint8)tm ^ (quint8)tmp;
  }
}

// MixColumns function mixes the columns of the state matrix.
// The method used to multiply may be difficult to understand for the inexperienced.
// Please use the references to gain more information.
void QAESEncryption::invMixColumns()
{
  QByteArray::iterator it = m_state->begin();
  quint8 a,b,c,d;
  for(int i = 0; i < 16; i+=4){
    a = (quint8) it[i];
    b = (quint8) it[i+1];
    c = (quint8) it[i+2];
    d = (quint8) it[i+3];

    it[i]   = (quint8) (multiply(a, 0x0e) ^ multiply(b, 0x0b) ^ multiply(c, 0x0d) ^ multiply(d, 0x09));
    it[i+1] = (quint8) (multiply(a, 0x09) ^ multiply(b, 0x0e) ^ multiply(c, 0x0b) ^ multiply(d, 0x0d));
    it[i+2] = (quint8) (multiply(a, 0x0d) ^ multiply(b, 0x09) ^ multiply(c, 0x0e) ^ multiply(d, 0x0b));
    it[i+3] = (quint8) (multiply(a, 0x0b) ^ multiply(b, 0x0d) ^ multiply(c, 0x09) ^ multiply(d, 0x0e));
  }
}

// The SubBytes Function Substitutes the values in the
// state matrix with values in an S-box.
void QAESEncryption::invSubBytes()
{
    QByteArray::iterator it = m_state->begin();
    for(int i = 0; i < 16; ++i)
        it[i] = getSBoxInvert((quint8) it[i]);
}

void QAESEncryption::invShiftRows()
{
    QByteArray::iterator it = m_state->begin();
    uint8_t temp;

    //Keep in mind that QByteArray is column-driven!!

    //Shift 1 to right
    temp   = (quint8)it[13];
    it[13] = (quint8)it[9];
    it[9]  = (quint8)it[5];
    it[5]  = (quint8)it[1];
    it[1]  = (quint8)temp;

    //Shift 2
    temp   = (quint8)it[10];
    it[10] = (quint8)it[2];
    it[2]  = (quint8)temp;
    temp   = (quint8)it[14];
    it[14] = (quint8)it[6];
    it[6]  = (quint8)temp;

    //Shift 3
    temp   = (quint8)it[7];
    it[7]  = (quint8)it[11];
    it[11] = (quint8)it[15];
    it[15] = (quint8)it[3];
    it[3]  = (quint8)temp;
}

QByteArray QAESEncryption::byteXor(const QByteArray &a, const QByteArray &b)
{
  QByteArray::const_iterator it_a = a.begin();
  QByteArray::const_iterator it_b = b.begin();
  QByteArray ret;

  //for(int i = 0; i < m_blocklen; i++)
  for(int i = 0; i < std::min(a.size(), b.size()); i++)
      ret.insert(i,it_a[i] ^ it_b[i]);

  return ret;
}

// Cipher is the main function that encrypts the PlainText.
QByteArray QAESEncryption::cipher(const QByteArray &expKey, const QByteArray &in)
{

  //m_state is the input buffer...
  QByteArray output(in);
  m_state = &output;

  // Add the First round key to the state before starting the rounds.
  addRoundKey(0, expKey);

  // There will be Nr rounds.
  // The first Nr-1 rounds are identical.
  // These Nr-1 rounds are executed in the loop below.
  for(quint8 round = 1; round < m_nr; ++round){
    subBytes();
    shiftRows();
    mixColumns();
    addRoundKey(round, expKey);
  }

  // The last round is given below.
  // The MixColumns function is not here in the last round.
  subBytes();
  shiftRows();
  addRoundKey(m_nr, expKey);

  return output;
}

QByteArray QAESEncryption::invCipher(const QByteArray &expKey, const QByteArray &in)
{
    //m_state is the input buffer.... handle it!
    QByteArray output(in);
    m_state = &output;

    // Add the First round key to the state before starting the rounds.
    addRoundKey(m_nr, expKey);

    // There will be Nr rounds.
    // The first Nr-1 rounds are identical.
    // These Nr-1 rounds are executed in the loop below.
    for(quint8 round=m_nr-1; round>0 ; round--){
        invShiftRows();
        invSubBytes();
        addRoundKey(round, expKey);
        invMixColumns();
    }

    // The last round is given below.
    // The MixColumns function is not here in the last round.
    invShiftRows();
    invSubBytes();
    addRoundKey(0, expKey);

    return output;
}

QByteArray QAESEncryption::printArray(uchar* arr, int size)
{
    QByteArray print("");
    for(int i=0; i<size; i++)
        print.append(arr[i]);

    return print.toHex();
}

QByteArray QAESEncryption::encode(const QByteArray &rawText, const QByteArray &key, const QByteArray &iv)
{
    if ((m_mode >= CBC && (iv.isEmpty() || iv.size() != m_blocklen)) || key.size() != m_keyLen)
           return QByteArray();

        QByteArray expandedKey = expandKey(key, true);
        QByteArray alignedText(rawText);

        //Fill array with padding
        alignedText.append(getPadding(rawText.size(), m_blocklen));

    switch(m_mode)
    {
    case ECB: {
#ifdef USE_INTEL_AES_IF_AVAILABLE
        if (m_aesNIAvailable){
            char expKey[expandedKey.size()];
            memcpy(expKey, expandedKey.data(), expandedKey.size());

            QByteArray outText;
            outText.resize(alignedText.size());
            AES_ECB_encrypt((unsigned char*) alignedText.constData(),
                            (unsigned char*) outText.data(),
                            alignedText.size(),
                            expKey,
                            m_nr);
            return outText;
        }
#endif
        QByteArray ret;
        for(int i=0; i < alignedText.size(); i+= m_blocklen)
            ret.append(cipher(expandedKey, alignedText.mid(i, m_blocklen)));
        return ret;
    }
    break;
    case CBC: {
#ifdef USE_INTEL_AES_IF_AVAILABLE
        if (m_aesNIAvailable){
            quint8 ivec[iv.size()];
            memcpy(ivec, iv.data(), iv.size());
            char expKey[expandedKey.size()];
            memcpy(expKey, expandedKey.data(), expandedKey.size());

            QByteArray outText;
            outText.resize(alignedText.size());
            AES_CBC_encrypt((unsigned char*) alignedText.constData(),
                            (unsigned char*) outText.data(),
                            ivec,
                            alignedText.size(),
                            expKey,
                            m_nr);
            return outText;
        }
#endif
        QByteArray ret;
        QByteArray ivTemp(iv);
        for(int i=0; i < alignedText.size(); i+= m_blocklen) {
            alignedText.replace(i, m_blocklen, byteXor(alignedText.mid(i, m_blocklen),ivTemp));
            ret.append(cipher(expandedKey, alignedText.mid(i, m_blocklen)));
            ivTemp = ret.mid(i, m_blocklen);
        }
        return ret;
    }
    break;
    case CFB: {
        QByteArray ret;
        ret.append(byteXor(alignedText.left(m_blocklen), cipher(expandedKey, iv)));
        for(int i=0; i < alignedText.size(); i+= m_blocklen) {
            if (i+m_blocklen < alignedText.size())
                ret.append(byteXor(alignedText.mid(i+m_blocklen, m_blocklen),
                                   cipher(expandedKey, ret.mid(i, m_blocklen))));
        }
        return ret;
    }
    break;
    case OFB: {
    QByteArray ret;
        QByteArray ofbTemp;
        ofbTemp.append(cipher(expandedKey, iv));
        for (int i=m_blocklen; i < alignedText.size(); i += m_blocklen){
            ofbTemp.append(cipher(expandedKey, ofbTemp.right(m_blocklen)));
        }
        ret.append(byteXor(alignedText, ofbTemp));
        return ret;
    }
    break;
    default: break;
    }
    return QByteArray();
}

QByteArray QAESEncryption::decode(const QByteArray &rawText, const QByteArray &key, const QByteArray &iv)
{
    if ((m_mode >= CBC && (iv.isEmpty() || iv.size() != m_blocklen)) || key.size() != m_keyLen || rawText.size() % m_blocklen != 0)
           return QByteArray();

        QByteArray ret;
        QByteArray expandedKey;

    #ifdef USE_INTEL_AES_IF_AVAILABLE
        if(m_aesNIAvailable && m_mode <= CBC){
            expandedKey = expandKey(key, false);
        }else{
            expandedKey = expandKey(key, true);
        }
    #else
        expandedKey = expandKey(key, true);
    #endif
        //false or true here is very important
        //the expandedKeys aren't the same for !aes-ni! ENcryption and DEcryption (only CBC and EBC)
        //but if you are !NOT! using aes-ni then the expandedKeys for encryption and decryption are the SAME!!!


    switch(m_mode)
    {
    case ECB:
#ifdef USE_INTEL_AES_IF_AVAILABLE
        if (m_aesNIAvailable){
            char expKey[expandedKey.size()];                                //expandedKey
            memcpy(expKey, expandedKey.data(), expandedKey.size());
            ret.resize(rawText.size());

            AES_ECB_decrypt((unsigned char*) rawText.constData(),
                            (unsigned char*) ret.data(),
                            rawText.size(),
                            expKey,
                            m_nr);
            break;
        }
#endif
        for(int i=0; i < rawText.size(); i+= m_blocklen)
            ret.append(invCipher(expandedKey, rawText.mid(i, m_blocklen)));
        break;
    case CBC:
#ifdef USE_INTEL_AES_IF_AVAILABLE
        if (m_aesNIAvailable){
            quint8 ivec[iv.size()];                                         //IV
            memcpy(ivec, iv.constData(), iv.size());
            char expKey[expandedKey.size()];                                //expandedKey
            memcpy(expKey, expandedKey.data(), expandedKey.size());
            ret.resize(rawText.size());

            AES_CBC_decrypt((unsigned char*) rawText.constData(),
                            (unsigned char*) ret.data(),
                            ivec,
                            rawText.size(),
                            expKey,
                            m_nr);
            break;
        }
#endif
        {
            QByteArray ivTemp(iv);
            for(int i=0; i < rawText.size(); i+= m_blocklen){
                ret.append(invCipher(expandedKey, rawText.mid(i, m_blocklen)));
                ret.replace(i, m_blocklen, byteXor(ret.mid(i, m_blocklen),ivTemp));
                ivTemp = rawText.mid(i, m_blocklen);
            }
        }
        break;
    case CFB: {
            ret.append(byteXor(rawText.mid(0, m_blocklen), cipher(expandedKey, iv)));
            for(int i=0; i < rawText.size(); i+= m_blocklen){
                if (i+m_blocklen < rawText.size()) {
                    ret.append(byteXor(rawText.mid(i+m_blocklen, m_blocklen),
                                       cipher(expandedKey, rawText.mid(i, m_blocklen))));
                }
            }
        }
        break;
    case OFB: {
        QByteArray ofbTemp;
        ofbTemp.append(cipher(expandedKey, iv));
        for (int i=m_blocklen; i < rawText.size(); i += m_blocklen){
            ofbTemp.append(cipher(expandedKey, ofbTemp.right(m_blocklen)));
        }
        ret.append(byteXor(rawText, ofbTemp));
    }
        break;
    default:
        //do nothing
        break;
    }
    return ret;
}

QByteArray QAESEncryption::removePadding(const QByteArray &rawText)
{
    return RemovePadding(rawText, (Padding) m_padding);
}
#include "SendEmail.h" // Include the header file for SendEmail

SendEmail::SendEmail() {} // Constructor definition for SendEmail

void SendEmail::send(const QString &to, const QString &subject, const QString &body)
{
    // Check parameters for validity
    if (to.isEmpty() || subject.isEmpty() || body.isEmpty())
    {
        logger.logMessage("Error: Empty parameters detected. Cannot send email."); // Log an error if any parameter is empty
        return;
    }

    QProcess process; // Create a QProcess object to run external processes

    // Path to your batch script
    QString batchFilePath = "sendEmail.bat"; // Specify the path to the batch file for sending emails

    // Prepare arguments
    QStringList arguments;
    arguments << to << subject << body; // Prepare arguments for the batch script (recipient email, subject, body)

    // Start the batch script with arguments
    process.start(batchFilePath, arguments); // Start the batch script with specified arguments
    if (!process.waitForFinished())
    {
        logger.logMessage(QString("Failed to run batch script: %1").arg(process.errorString())); // Log an error if the batch script fails to execute
        return;
    }

    // Read and display the output or err
    QString error = process.readAllStandardError(); // Read standard error output from the process
    if (!error.isEmpty())
    {
        logger.logMessage(QString("Error sending email: %1").arg(error)); // Log an error if there is any error output from the process
    }
}
#include "Server.h" // Include the header file for Server

Server::Server(QObject *parent) : QTcpServer{parent} {} // Constructor definition for Server, inheriting QTcpServer

void Server::StartServer()
{
    Port = 1234; // Set the port number for the server
    this->listen(QHostAddress::Any, Port); // Start listening on any IP address on the specified port

    if (isListening())
    {
        QString logMessage = QString("Server is up and listening to port => %1").arg(Port); // Log message indicating server is listening
        logger.logMessage(logMessage); // Log the message using the logger object
        qDebug() << logMessage; // Output the message to qDebug for debugging
    }
    else
    {
        QString logMessage = QString("Server can't listen to port => %1").arg(Port); // Log message indicating server failed to start listening
        logger.logMessage(logMessage); // Log the message using the logger object
        qDebug() << logMessage; // Output the message to qDebug for debugging
    }
}

void Server::incomingConnection(qintptr handle)
{
    QString logMessage = QString("User:%1 connent to server").arg(handle); // Log message indicating incoming connection
    logger.logMessage(logMessage); // Log the message using the logger object
    qDebug() << logMessage; // Output the message to qDebug for debugging

    ServerHandler* serverhandler = new ServerHandler(handle); // Create a new ServerHandler object for handling the incoming connection
    connect(serverhandler, &QThread::finished, serverhandler, &QThread::deleteLater); // Connect signals to ensure proper cleanup of ServerHandler
    serverhandler->start(); // Start the ServerHandler thread to handle the incoming connection
}
#include "ServerHandler.h" // Include the header file for ServerHandler

ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent), userID(ID) // Constructor for ServerHandler, setting userID and parent object
{
    setupRequestHandles(); // Call function to set up request handlers
    loginStatus = false; // Initialize login status to false
}

void ServerHandler::setupRequestHandles()
{
    // Initialize request handlers for different commands
    requestHandlerMap["Login"] = new LoginHandler(dataBase);
    requestHandlerMap["AddAccount"] = new AddClientHandler(dataBase);
    requestHandlerMap["DeleteAccount"] = new DeleteAccountHandler(dataBase);
    requestHandlerMap["GetAccountBalance"] = new GetAccountBalanceHandler(dataBase);
    requestHandlerMap["GetAccountNumber"] = new GetAccountNumberHandler(dataBase);
    requestHandlerMap["GetTransactionHistory"] = new GetTransactionHistoryHandler(dataBase);
    requestHandlerMap["MakeTransaction"] = new MakeTransactionHandler(dataBase);
    requestHandlerMap["MakeTransfer"] = new MakeTransferHandler(dataBase);
    requestHandlerMap["UpdateAccount"] = new UpdateAccountHandler(dataBase);
    requestHandlerMap["GetBankDataBase"] = new GetBankDataBaseHandler(dataBase);
}

void ServerHandler::run()
{
    statusMessage = "User:" + QString::number(userID) + " is running on thread"; // Log thread start
    logger.logMessage(statusMessage); // Log the thread start message
    Socket = new QTcpSocket(); // Create a new QTcpSocket instance
    Socket->setSocketDescriptor(userID); // Set the socket descriptor for the socket
    connect(Socket, &QTcpSocket::readyRead, this, &ServerHandler::onReadyRead, Qt::DirectConnection); // Connect readyRead signal to onReadyRead slot
    connect(Socket, &QTcpSocket::disconnected, this, &ServerHandler::onDisconnected, Qt::DirectConnection); // Connect disconnected signal to onDisconnected slot
    dataBase.initializeMainDatabase(); // Initialize main database
    dataBase.initializeTransactionDatabase(); // Initialize transaction database
    exec(); // Start event loop for this thread
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll(); // Read all data from the socket
    logger.logMessage(QString("Server Received encrypted request From User:%1 Request => %2").arg(userID).arg(ByteArr.toHex())); // Log received encrypted request

    // Decrypt the received data
    QByteArray decryptedData = decryptRequest(ByteArr); // Decrypt the received data
    int padLength = decryptedData.at(decryptedData.length() - 1); // Get padding length
    decryptedData = decryptedData.left(decryptedData.length() - padLength); // Remove padding

    statusMessage = QString("Server Received request From User:%1 Request => %2").arg(userID).arg(QString(decryptedData)); // Log decrypted request
    logger.logMessage(statusMessage); // Log decrypted request

    // Extract the frame size and validate it
    int colonIndex = decryptedData.indexOf(':'); // Find colon separating frame size
    if (colonIndex == -1)
    {
        logger.logMessage("Invalid frame: No colon found."); // Log error if no colon found
        return;
    }

    bool ok;
    int frameSize = QString(decryptedData.left(colonIndex)).toInt(&ok); // Get frame size
    if (!ok || frameSize <= 0)
    {
        logger.logMessage("Invalid frame: Invalid frame size."); // Log error if invalid frame size
        return;
    }

    // Extract the JSON part of the frame and validate its size
    QByteArray jsonData = decryptedData.mid(colonIndex + 1); // Extract JSON data
    if (jsonData.size() != frameSize)
    {
        logger.logMessage("Invalid frame: Frame size does not match JSON data size."); // Log error if frame size does not match JSON data size
        return;
    }

    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData); // Parse JSON data
    if (jsonDoc.isNull() || !jsonDoc.isObject())
    {
        logger.logMessage("Invalid frame: Failed to parse JSON."); // Log error if failed to parse JSON
        return;
    }

    QJsonObject jsonObj = jsonDoc.object(); // Get JSON object
    QString requestsizeStr = jsonObj["RequestSize"].toString(); // Get request size from JSON
    int requestSize = requestsizeStr.toInt(&ok); // Convert request size to integer
    if (!ok || requestSize <= 0)
    {
        logger.logMessage(QString::number(requestSize)); // Log invalid request size
        logger.logMessage("Invalid frame: Invalid request size."); // Log error if invalid request size
        return;
    }

    QString requestData = jsonObj["RequestData"].toString(); // Get request data from JSON
    if (requestData.size() != requestSize)
    {
        logger.logMessage("Invalid frame: Request size does not match actual data size."); // Log error if request size does not match data size
        return;
    }

    // Log the valid request
    statusMessage = QString("Server processing request from User:%1 Request => %2").arg(userID).arg(requestData);
    logger.logMessage(statusMessage); // Log processing of request

    // Process the operation with the valid request data
    Operation(requestData); // Call Operation method with request data
}

QByteArray ServerHandler::decryptRequest(const QByteArray &encryptedData)
{
    QByteArray key = "1234567890123456"; // Encryption key
    QByteArray iv = "1234567890123456"; // Initialization vector
    // Decrypt the data
    QByteArray decryptedData = QAESEncryption::Decrypt(QAESEncryption::AES_128, QAESEncryption::CBC, encryptedData, key, iv, QAESEncryption::PKCS7);
    return decryptedData; // Return decrypted data
}

void ServerHandler::onDisconnected()
{
    if (Socket->isOpen()) // Check if socket is open
    {
        if (loginStatus) // Check if user is logged in
        {
            if (dataBase.setUserLoginState(loginUser, "0")) // Set user's login state to false in database
            {
                statusMessage = "User: " + QString::number(userID) + " logout form bank system"; // Log user logout
                logger.logMessage(statusMessage); // Log user logout
                loginStatus = false; // Update login status
            }
        }
        Socket->close(); // Close socket
        statusMessage = "User:" + QString::number(userID) + " has disconnected"; // Log user disconnection
        logger.logMessage(statusMessage); // Log user disconnection
    }
}

void ServerHandler::Operation(QString Request)
{
    QStringList List = Request.split(":"); // Split request into components
    if (List.isEmpty())
    {
        sendResponse("Invalid request."); // Send response for invalid request
        return;
    }

    QString HandlerKey = List[0]; // Get request handler key

    if (requestHandlerMap.contains(HandlerKey)) // Check if handler key exists in map
    {
        if (HandlerKey == "Login") // Handle special case for login
        {
            loginUser = List[1]; // Save username for login
        }
        requestHandlerMap[HandlerKey]->execute(List, statusMessage); // Execute request handler
        sendResponse(statusMessage); // Send response based on execution result
    }
    else
    {
        sendResponse("Unknown request."); // Send response for unknown request
    }
}

void ServerHandler::sendResponse(const QString &Message)
{
    if (Socket->isOpen()) // Check if socket is open
    {
        // Create a QJsonObject with the response size and data
        QJsonObject responseObj;
        responseObj["ResponseSize"] = QString::number(Message.size()); // Response size
        responseObj["ResponseData"] = Message; // Response data

        // Check and update login status based on response
        QStringList list = Message.split(":");
        if (list[0] == "Client" || list[0] == "Admin")
        {
            loginStatus = true; // Update login status for valid login attempts
        }

        // Convert the QJsonObject to a QByteArray
        QJsonDocument doc(responseObj); // Create JSON document from response object
        QByteArray jsonData = doc.toJson(QJsonDocument::Compact); // Convert JSON document to compact JSON

        // Get the size of the jsonData
        qint32 jsonSize = jsonData.size(); // Get size of JSON data

        // Convert jsonSize to a string and append a colon
        QByteArray header = QByteArray::number(jsonSize) + ":"; // Create header with JSON size

        // Construct the frame by concatenating header and jsonData
        QByteArray frame = header + jsonData; // Create frame by concatenating header and JSON data
        Socket->write(frame); // Write frame to socket
        QString logMessage = QString("My server Send Response to User:%1 Response => %2").arg(userID).arg(frame); // Log response sent
        logger.logMessage(logMessage); // Log response sent
    }
    else
    {
        QString logMessage = QString("My server Can't Send Response to User:%1 Because The Socket is Closed").arg(userID); // Log error if socket closed
        logger.logMessage(logMessage); // Log error if socket closed
        qDebug() << logMessage; // Output error to qDebug
    }
}
#include "UpdateAccountHandler.h" // Include the header file for UpdateAccountHandler

UpdateAccountHandler::UpdateAccountHandler(BankDataBase &db) : dataBase(db) {} // Constructor initializing the database reference

void UpdateAccountHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields."; // Inform about invalid request if fields are missing
        return;
    }

    QString fullName = RequestParts[1]; // Extract full name from request parts
    QString userName = RequestParts[2]; // Extract username from request parts
    QString passWord = RequestParts[3]; // Extract password from request parts
    QString age = RequestParts[4]; // Extract age from request parts
    QString email = RequestParts[5]; // Extract email from request parts
    QString accountNumber = RequestParts[6]; // Extract account number from request parts

    // Update the client account in the database
    bool success = dataBase.updateClient(accountNumber, userName, passWord, fullName, age, email); // Update client account in the database

    // Send appropriate response based on update result
    if (success)
    {
        statusMessage = "Account update successful."; // Set success message if account update is successful
    }
    else
    {
        statusMessage = "Account update failed. Please check the account number and try again."; // Set failure message if account update fails
    }
}
