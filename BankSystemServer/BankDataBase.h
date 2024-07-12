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

class BankDataBase : public QObject
{
    Q_OBJECT
public:
    explicit BankDataBase(QObject *parent = nullptr);

private:
    QVector<QJsonObject> mainDatabaseRecords;        // Vector holding data from the main database file
    QVector<QJsonObject> transactionDatabaseRecords; // Vector holding data from the transaction database file
    QString mainDatabaseFilePath;                    // Path to the main database file
    QString transactionFilePath;                     // Path to the transaction database file
    Logger logger;

public:
    // Initialization
    void initializeMainDatabase();                  // Initialize main database from file
    void initializeTransactionDatabase();           // Initialize transaction database from file

    // Getters
    QVector<QJsonObject> getMainDatabase();         // Retrieve data from the main database file
    QVector<QJsonObject> getTransactionDatabase();  // Retrieve data from the transaction database file

    // Database operations
    bool addClient(const QString &username, const QString &password, const QString &fullName, const QString &age,
                   const QString &email, const QString &balance); // Add new client data
    bool deleteClient(const QString &accountNumber);             // Delete a Client from the database
    bool updateClient(const QString &accountNumber, const QString &username, const QString &password,
                      const QString &fullName, const QString &age, const QString &email); // Update client information
    bool saveMainDatabaseToFile();
    bool saveTransactionDatabaseToFile();
    bool setUserLoginState(const QString& username, const QString& state);

    // Transaction operations
    bool transferMoney(const QString &sourceAccountNumber, const QString &targetAccountNumber,
                       const QString &amountStr);
    bool withdrawMoney(const QString &accountNumber, const QString &amount); // Withdraw money
    bool depositMoney(const QString &accountNumber, const QString &amount);  // Deposit money

    // Utility
    QString generateAccountNumber(); // Generate a unique account number
    QString getEmailByAccountNumber(const QString &accountNumber); // Get email by account number

};

#endif // BANKDATABASE_H
