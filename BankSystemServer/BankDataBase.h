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
