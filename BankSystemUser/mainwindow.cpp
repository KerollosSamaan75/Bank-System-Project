#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&SystemUser,&User::Connected,this,&MainWindow::onConnectedDevice);
    connect(&SystemUser,&User::Disconnected,this,&MainWindow::onDisconnectedDevice);
    connect(&SystemUser,&User::ErrorOccurred,this,&MainWindow::onErrorOccurredDevice);
    connect(&SystemUser,&User::StateChanged,this,&MainWindow::onStateChangedDevice);
    connect(&SystemUser,&User::ReadyRead,this,&MainWindow::onReadyReadDevice);
    connect(&SystemUser,&User::UserWriteData,this,&MainWindow::onUserWriteData);


    ui->stackedWidget->setCurrentIndex(0);
    ui->frame->setEnabled(false);

    ui->usernameErrorLabel->setVisible(false);
    ui->passwordErrorLabel->setVisible(false);
    ui->lEUserName->setPlaceholderText("Enter your username");
    ui->lEPassword->setPlaceholderText("Enter your password");

    ui->NewUserPassWordErrorLabel->setVisible(false);
    ui->NewUserAgeErrorLabel->setVisible(false);
    ui->NewUserBalanceErrorLabel->setVisible(false);
    ui->NewUserFullNameErrorLabel->setVisible(false);
    ui->NewUserUserNameErrorLabel->setVisible(false);
    ui->NewUserEmailErrorLabel->setVisible(false);
    ui->NewUserFullName->setPlaceholderText("Enter your fullname");
    ui->NewUserUserName->setPlaceholderText("Enter your username");
    ui->NewUserPassWord->setPlaceholderText("Enter your password");
    ui->NewUserAge->setPlaceholderText("Enter your age");
    ui->NewUserEmail->setPlaceholderText("Enter your email");
    ui->NewUserBalance->setPlaceholderText("Enter your balance");
    ui->NewUserAge->setValidator(new QIntValidator(0, 150, this)); // Age between 0 and 150
    ui->NewUserBalance->setValidator(new QDoubleValidator(0, 1000000, 2, this)); // Balance up to 1,000,000 with 2 decimal places

    ui->AdminViewHistoryAccountNumberErrorLabel->setVisible(false);
    ui->AdminViewHistoryCountErrorLabel->setVisible(false);
    ui->lE_AdminViewHistoryAccountNumber->setPlaceholderText("Enter account number");
    ui->lE_AdminViewHistoryCount->setPlaceholderText("Enter history count");

    ui->UpdateAccountFullName->setPlaceholderText("Enter your fullname");
    ui->UpdateAccountUserName->setPlaceholderText("Enter your username");
    ui->UpdateAccountAge->setPlaceholderText("Enter your age");
    ui->UpdateAccountEmail->setPlaceholderText("Enter your email");
    ui->UpdateAccountPassword->setPlaceholderText("Enter your password");
    ui->UpdateAccountAge->setValidator(new QIntValidator(0, 150, this)); // Age between 0 and 150
    ui->UpdateEmailErrorLabel->setVisible(false);

    ui->lE_ClientViewHistoryCount->setPlaceholderText("Enter your history count");
    ui->ClientViewHistoryCountErrorLabel->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requestResponse(QString message)
{
    QStringList List= message.split(":");
    if(List[0] == "Client")
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->Userlabel->setText(List[0]+":"+List[1]);
        clientUserName =List[1];
        clientAccountNumber = List[2];
    }
    else if(List[0] =="Admin")
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->Adminlabel->setText(List[0]+":"+List[1]);

    }
    else if(List[0] =="ViewBankDataBase")
    {
        // Remove the prefix and parse the JSON data
        QString jsonData = message.mid(QString("ViewBankDataBase:").length());
        QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
        QJsonArray jsonArray = doc.array();

        // Clear the list widget
        ui->BankDataBaselistWidget->clear();

        // Iterate through the JSON array and add formatted strings to the list widget
        for (const QJsonValue& value : jsonArray)
        {
            QJsonObject obj = value.toObject();
            QString accountInfo = QString("Account Number: %1\nUsername: %2\nFull Name: %3\nAge: %4\nEmail: %5\nBalance: %6\nAuthority: %7\nLogin: %8\n")
                                      .arg(obj["AccountNumber"].toString("N/A"))
                                      .arg(obj["Username"].toString("N/A"))
                                      .arg(obj["FullName"].toString("N/A"))
                                      .arg(obj["Age"].toString("N/A"))
                                      .arg(obj["Email"].toString("N/A"))
                                      .arg(obj["Balance"].toString("N/A"))
                                      .arg(obj["Authority"].toString("N/A"))
                                      .arg(obj["Login"].toString("N/A"));
            ui->BankDataBaselistWidget->addItem(accountInfo);
        }
    }


    else if(List[0] =="TransactionHistory")
    {
        // Extract the JSON part from the response
        QString jsonString = message.mid(QString("TransactionHistory:").length());

        // Parse the JSON
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        if (jsonDoc.isNull() || !jsonDoc.isObject())
        {
            QMessageBox::warning(this, "Error", "Failed to parse JSON.");
            return;
        }

        QJsonObject jsonObject = jsonDoc.object();
        QString accountNumber = jsonObject["AccountNumber"].toString();
        QJsonArray transactions = jsonObject["RecentTransactions"].toArray();

        // Clear the list widget
        ui->AdTransactionHistorylistWidget->clear();

        // Display account number as a header
        ui->AdTransactionHistorylistWidget->addItem("Account Number: " + accountNumber);

        // Iterate through the transactions and add them to the list widget
        for (const QJsonValue& value : transactions)
        {
            QJsonObject transaction = value.toObject();
            QString amount = transaction["amount"].toString();
            QString date = transaction["date"].toString();
            QString formattedTransaction = QString("Date: %1, Amount: %2").arg(date).arg(amount);

            ui->AdTransactionHistorylistWidget->addItem(formattedTransaction);
            ui->ClientTransactionHistoryListWidget->addItem(formattedTransaction);
        }
    }
    else
    {
        QMessageBox::information(this, "Request response", message);
    }
}



void MainWindow::onConnectedDevice()
{
    ui->Console->addItem("User has connected to Server");
     QMessageBox::information(this, "Connection Successful", "You have successfully connected to the server\n"
                                    "now you can Login to the Bank System.");
    ui->Console->hide();
    ui->pBConnect->hide();
    ui->frame->setEnabled(true);
}

void MainWindow::onDisconnectedDevice()
{
    ui->Console->addItem("User has disconnected from Server");
    qDebug()<<"User has disconnected from Server"<<Qt::endl;
}

void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->Console->addItem(meta.valueToKey(socketError));
    if(socketError == 0)
    {
        QString message = "Unable to connect to the server.\n\n"
                          "Possible reasons:\n"
                          "1. The server might be down.\n"
                          "2. Network issues could be preventing the connection.\n"
                          "3. Incorrect server address or port.\n"
                          "4. Firewall or antivirus software might be blocking the connection.\n\n"
                          "Solutions:\n"
                          "1. Check the server status.\n"
                          "2. Verify your network connectivity.\n"
                          "3. Ensure the server address and port are correct.\n"
                          "4. Temporarily disable firewall or antivirus software to test the connection.\n\n"
                          "If the problem persists, please contact support.";
        QMessageBox::warning(this, "Connection Failed", message);
        ui->pBConnect->setText("Try to Connent again");
    }
}

void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->Console->addItem(meta.valueToKey(socketState));
    qDebug()<<meta.valueToKey(socketState)<<Qt::endl;
}

void MainWindow::onReadyReadDevice(QString Data)
{
    QString data = QString("User Recieved from server is ==> %1").arg(Data);
    qDebug()<<data<<Qt::endl;
    requestResponse(Data);
}

void MainWindow::onUserWriteData(QString Data)
{
    QString data = QString("User Write Data ==> %1").arg(Data);
    qDebug()<<data<<Qt::endl;
}

void MainWindow::on_pBConnect_clicked()
{
    SystemUser.ConnectToDevice("192.168.1.17",1234);
}


void MainWindow::on_pBLogin_clicked()
{
    bool valid = true;

    // Check if username is empty
    if (ui->lEUserName->text().isEmpty())
    {
        ui->usernameErrorLabel->setText("Username is required.");
        ui->usernameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->usernameErrorLabel->setVisible(false);
    }

    // Check if password is empty
    if (ui->lEPassword->text().isEmpty())
    {
        ui->passwordErrorLabel->setText("Password is required.");
        ui->passwordErrorLabel->setVisible(true);
        valid = false;
    } else
    {
        ui->passwordErrorLabel->setVisible(false);
    }

    if (valid)
    {
        QString userName =ui->lEUserName->text();
        QString passWord=ui->lEPassword->text();
        QString message = QString("Login:%1:%2").arg(userName).arg(passWord);
        SystemUser.WriteData(message);
    }
}



void MainWindow::on_pB_AddAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pBCreateAccount_clicked()
{
    bool valid = true;

    // Check if fullname is empty
    if (ui->NewUserFullName->text().isEmpty())
    {
        ui->NewUserFullNameErrorLabel->setText("Full name is required.");
        ui->NewUserFullNameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserFullNameErrorLabel->setVisible(false);
    }

    // Check if username is empty
    if (ui->NewUserUserName->text().isEmpty())
    {
        ui->NewUserUserNameErrorLabel->setText("Username is required.");
        ui->NewUserUserNameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserUserNameErrorLabel->setVisible(false);
    }

    // Check if password is empty
    if (ui->NewUserPassWord->text().isEmpty())
    {
        ui->NewUserPassWordErrorLabel->setText("Password is required.");
        ui->NewUserPassWordErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserPassWordErrorLabel->setVisible(false);
    }

    // Check if age is empty
    if (ui->NewUserAge->text().isEmpty())
    {
        ui->NewUserAgeErrorLabel->setText("Valid age is required.");
        ui->NewUserAgeErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserAgeErrorLabel->setVisible(false);
    }

    // Check if email is empty or not valid
    QRegularExpression emailRegex("^[\\w\\.]+@[\\w\\.]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = emailRegex.match(ui->NewUserEmail->text());
    if (ui->NewUserEmail->text().isEmpty() || !match.hasMatch())
    {
        ui->NewUserEmailErrorLabel->setText("Valid email is required.");
        ui->NewUserEmailErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserEmailErrorLabel->setVisible(false);
    }

    // Check if balance is empty
    if (ui->NewUserBalance->text().isEmpty())
    {
        ui->NewUserBalanceErrorLabel->setText("Valid balance is required.");
        ui->NewUserBalanceErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserBalanceErrorLabel->setVisible(false);
    }

    if (valid)
    {
        QString fullName = ui->NewUserFullName->text();
        QString userName = ui->NewUserUserName->text();
        QString passWord = ui->NewUserPassWord->text();
        int age = ui->NewUserAge->text().toInt();
        QString email = ui->NewUserEmail->text();
        double balance = ui->NewUserBalance->text().toDouble();

        QString message = QString("AddAccount:%1:%2:%3:%4:%5:%6").arg(fullName).arg(userName).arg(passWord).arg(age).arg(email).arg(balance);
        SystemUser.WriteData(message);
    }
}


void MainWindow::on_pBAddAccoutBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pB_AdminGetAccountNumber_clicked()
{
    bool ok;
    QString username = QInputDialog::getText(this, tr("Get account number"),
                                                  tr("Enter username:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || username.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Username is required");
        return;
    }
    QString message = QString("GetAccountNumber:%1").arg(username);
    SystemUser.WriteData(message);
}


void MainWindow::on_pB_DeleteAccount_clicked()
{
    bool ok;
    QString accountNumber = QInputDialog::getText(this, tr("Delete account"),
                                             tr("Enter account number:"), QLineEdit::Normal,
                                             "", &ok);
    if (!ok || accountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Account number is required");
        return;
    }
    QString message = QString("DeleteAccount:%1").arg(accountNumber);
    SystemUser.WriteData(message);
}


void MainWindow::on_pBAdminBack_clicked()
{
    ui->lEUserName->clear();
    ui->lEPassword->clear();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pB_AdminGetAccountBalance_clicked()
{
    bool ok;
    QString accountNumber = QInputDialog::getText(this, tr("Get account balance"),
                                                  tr("Enter account number:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || accountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Account number is required");
        return;
    }
    QString message = QString("GetAccountBalance:%1").arg(accountNumber);
    SystemUser.WriteData(message);
}


void MainWindow::on_pB_AdminViewTransactionHistory_clicked()
{
    ui->AdTransactionHistorylistWidget->clear();
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pBAdminViewTransactionBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pBAdminViewTransactionView_clicked()
{
    bool valid = true;

    // Check if account number is empty or not a valid number
    QRegularExpression digitRegex("^[0-9]+$");
    QString accountNumber = ui->lE_AdminViewHistoryAccountNumber->text();
    if (accountNumber.isEmpty() || !digitRegex.match(accountNumber).hasMatch())
    {
        ui->AdminViewHistoryAccountNumberErrorLabel->setText("Valid account number is required.");
        ui->AdminViewHistoryAccountNumberErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->AdminViewHistoryAccountNumberErrorLabel->setVisible(false);
    }

    // Check if history count is empty or not a valid number
    QString historyCountStr = ui->lE_AdminViewHistoryCount->text();
    bool isNumber;
    int historyCount = historyCountStr.toInt(&isNumber);
    if (historyCountStr.isEmpty() || !digitRegex.match(historyCountStr).hasMatch() || !isNumber || historyCount <= 0 || historyCount > 20)
    {
        ui->AdminViewHistoryCountErrorLabel->setText("Valid history count (1-20) is required.");
        ui->AdminViewHistoryCountErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->AdminViewHistoryCountErrorLabel->setVisible(false);
    }

    if (valid)
    {
        ui->AdTransactionHistorylistWidget->clear();
        QString message = QString("ViewTransactions:%1:%2").arg(accountNumber).arg(historyCountStr);
        SystemUser.WriteData(message);
    }
}


void MainWindow::on_pB_ViewBankDatabase_clicked()
{
    SystemUser.WriteData("ViewBankDatabase:");
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_pB_ViewBankDatabaseBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pB_UpdateClientAccount_clicked()
{
    bool ok;
    QString number = QInputDialog::getText(this, tr("Account number"),
                                                  tr("Enter account number you want to update it"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || number.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Account number is required");
        return;
    }
    Ad_accountNumber = number;
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pB_ClientUpdateAccountBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pB_Update_clicked()
{

    QString fullName = ui->UpdateAccountFullName->text();
    QString userName = ui->UpdateAccountUserName->text();
    QString passWord = ui->UpdateAccountPassword->text();
    int age = ui->UpdateAccountAge->text().toInt();
    QString email = ui->UpdateAccountEmail->text();

    // Check if email is not valid
    QRegularExpression emailRegex("^[\\w\\.]+@[\\w\\.]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch match = emailRegex.match(email);
    if(email.isEmpty())
    {
        QString message = QString("UpdateAccount:%1:%2:%3:%4:%5:%6").arg(fullName).arg(userName).arg(passWord).arg(age).arg(email).arg(Ad_accountNumber);
        SystemUser.WriteData(message);
    }
    else if (!match.hasMatch())
    {
        ui->UpdateEmailErrorLabel->setText("Valid email is required.");
        ui->UpdateEmailErrorLabel->setVisible(true);
    }
    else
    {
        ui->UpdateEmailErrorLabel->setVisible(false);
        QString message = QString("UpdateAccount:%1:%2:%3:%4:%5:%6").arg(fullName).arg(userName).arg(passWord).arg(age).arg(email).arg(Ad_accountNumber);
        SystemUser.WriteData(message);
    }

}


void MainWindow::on_pB_ClientGetAccountNumber_clicked()
{
    QMessageBox::information(this, "Request response", "Account number: "+clientAccountNumber);
}


void MainWindow::on_pB_ClientViewAccountBalance_clicked()
{
    QString message = QString("GetAccountBalance:%1").arg(clientAccountNumber);
    SystemUser.WriteData(message);
}





void MainWindow::on_pb_ViewMyHistoryBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pB_ViewMyHistory_clicked()
{
    ui->ClientTransactionHistoryListWidget->clear();
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pb_ViewMyHistoryView_clicked()
{
    bool valid = true;

    QRegularExpression digitRegex("^[0-9]+$");
    // Check if history count is empty or not a valid number
    QString historyCountStr = ui->lE_ClientViewHistoryCount->text();
    bool isNumber;
    int historyCount = historyCountStr.toInt(&isNumber);
    if (historyCountStr.isEmpty() || !digitRegex.match(historyCountStr).hasMatch() || !isNumber || historyCount <= 0 || historyCount > 20)
    {
        ui->ClientViewHistoryCountErrorLabel->setText("Valid history count (1-20) is required.");
        ui->ClientViewHistoryCountErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->ClientViewHistoryCountErrorLabel->setVisible(false);
    }

    if (valid)
    {
        ui->ClientTransactionHistoryListWidget->clear();
        QString message = QString("ViewTransactions:%1:%2").arg(clientAccountNumber).arg(historyCountStr);
        SystemUser.WriteData(message);
    }
}




void MainWindow::on_pB_MakeTransaction_clicked()
{
    // Create a regular expression that matches the required format
    QRegularExpression regExp("[+-]\\d+"); // Matches a + or - followed by one or more digits
    QRegularExpressionValidator validator(regExp, this);

    // Prompt the user for the transaction amount
    bool ok;
    QString transactionAmount = QInputDialog::getText(this,
                                                      tr("Make Transaction"),
                                                      tr("Enter transaction amount (e.g., +100 for deposit, -50 for withdrawal):"),
                                                      QLineEdit::Normal, "", &ok);

    // Check if the input was valid and accepted
    if (ok && !transactionAmount.isEmpty())
    {
        // Validate the input
        int pos = 0;
        if (validator.validate(transactionAmount, pos) == QValidator::Acceptable)
        {
            // Process the transaction amount
            QString message = QString("MakeTransaction:%1:%2").arg(clientAccountNumber).arg(transactionAmount);
            SystemUser.WriteData(message);
        }
        else
        {
            // Show an error message if the input is invalid
            QMessageBox::warning(this, tr("Invalid Input"),
                                 tr("Please enter a valid transaction amount (e.g., +100 for deposit, -50 for withdrawal)."));
        }
    }
}



void MainWindow::on_pB_ClientBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pB_ClientTransferMoney_clicked()
{
    // Prompt the user for the target account number
    bool ok;
    QString targetAccountNumber = QInputDialog::getText(this,
                                                        tr("Transfer Money"),
                                                        tr("Enter the account number to transfer money to:"),
                                                        QLineEdit::Normal, "", &ok);

    // Validate the account number
    QRegularExpression accountNumberRegex("\\d+"); // Matches one or more digits
    QRegularExpressionMatch match = accountNumberRegex.match(targetAccountNumber);

    // Check if the input was valid and accepted
    if (ok && !targetAccountNumber.isEmpty() && match.hasMatch())
    {
        // Prompt the user for the transfer amount
        QString transferAmount = QInputDialog::getText(this,
                                                       tr("Transfer Money"),
                                                       tr("Enter the transfer amount:"),
                                                       QLineEdit::Normal, "", &ok);

        // Check if the input was valid and accepted
        if (ok && !transferAmount.isEmpty())
        {
            // Validate the amount
            bool isNumber;
            int amount = transferAmount.toInt(&isNumber);
            if (isNumber && amount > 0)
            {
                // Construct the message and send it to the server
                QString message = QString("TransferMoney:%1:%2:%3").arg(clientAccountNumber).arg(targetAccountNumber).arg(amount);
                SystemUser.WriteData(message);
            }
            else
            {
                // Show an error message if the input is invalid
                QMessageBox::warning(this, tr("Invalid Input"),
                                     tr("Please enter a valid transfer amount."));
            }
        }
        else if (!ok)
        {
            // User cancelled the input
            return;
        }
        else
        {
            // Show an error message if the input is empty
            QMessageBox::warning(this, tr("Invalid Input"),
                                 tr("Transfer amount cannot be empty."));
        }
    }
    else if (!ok)
    {
        // User cancelled the input
        return;
    }
    else
    {
        // Show an error message if the input is empty or invalid
        QMessageBox::warning(this, tr("Invalid Input"),
                             tr("Target account number must be digits and cannot be empty."));
    }
}



