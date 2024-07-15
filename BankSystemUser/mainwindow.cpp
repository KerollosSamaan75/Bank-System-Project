#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&SystemUser,&User::Connected,this,&MainWindow::onConnectedServer);
    connect(&SystemUser,&User::Disconnected,this,&MainWindow::onDisconnectedServer);
    connect(&SystemUser,&User::ErrorOccurred,this,&MainWindow::onErrorOccurredServer);
    connect(&SystemUser,&User::StateChanged,this,&MainWindow::onStateChangedServer);
    connect(&SystemUser,&User::ReadyRead,this,&MainWindow::onReadyReadServer);
    connect(&SystemUser,&User::UserSendRequest,this,&MainWindow::onUserSendRequest);


    ui->stackedWidget->setCurrentIndex(0);
    ui->frame->setEnabled(false);

    ui->usernameErrorLabel->setVisible(false);
    ui->passwordErrorLabel->setVisible(false);
    ui->lEUserName->setPlaceholderText("Enter your username");
    ui->lEPassword->setPlaceholderText("Enter your password");
    ui->lEPassword->setEchoMode(QLineEdit::Password);

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

   // SystemUser.ConnectToServer("192.168.1.17",1234);
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
        loggerUserName =List[1];
        loggerAccountNumber = List[2];
        ui->lEUserName->clear();
        ui->lEPassword->clear();
    }
    else if(List[0] =="Admin")
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->Adminlabel->setText(List[0]+":"+List[1]);
        loggerUserName =List[1];
        loggerAccountNumber = List[2];
        ui->lEUserName->clear();
        ui->lEPassword->clear();

    }
    else if(List[0] == "ViewBankDataBase")
    {
        // Remove the prefix and parse the JSON data
        QString jsonData = message.mid(QString("ViewBankDataBase:").length());
        QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
        QJsonArray jsonArray = doc.array();

        // Clear the table widget
        ui->BankDataBaseTableWidget->clear();

        // Set column headers
        QStringList headers;
        headers << "Account Number" << "Username" << "Full Name" << "Age" << "Email" << "Balance" << "Authority" << "Login";
        ui->BankDataBaseTableWidget->setColumnCount(headers.size());
        ui->BankDataBaseTableWidget->setHorizontalHeaderLabels(headers);

        // Set the number of rows
        ui->BankDataBaseTableWidget->setRowCount(jsonArray.size());

        // Iterate through the JSON array and add data to the table widget
        int row = 0;
        for (const QJsonValue& value : jsonArray)
        {
            QJsonObject obj = value.toObject();

            // Populate each cell with data from the JSON object
            ui->BankDataBaseTableWidget->setItem(row, 0, new QTableWidgetItem(obj["AccountNumber"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 1, new QTableWidgetItem(obj["Username"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 2, new QTableWidgetItem(obj["FullName"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 3, new QTableWidgetItem(obj["Age"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 4, new QTableWidgetItem(obj["Email"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 5, new QTableWidgetItem(obj["Balance"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 6, new QTableWidgetItem(obj["Authority"].toString("N/A")));
            ui->BankDataBaseTableWidget->setItem(row, 7, new QTableWidgetItem(obj["Login"].toString("N/A")));
            row++;
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
        ui->ClientTransactionHistoryListWidget->clear();

        // Display account number as a header
        ui->AdTransactionHistorylistWidget->addItem("Account Number: " + accountNumber);
        ui->ClientTransactionHistoryListWidget->addItem("Account Number: " + accountNumber);

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



void MainWindow::onConnectedServer()
{
    ui->Console->addItem("User has connected to Server");
    qDebug()<<"User has connected to Server";
    QMessageBox::information(this, "Connection Successful", "You have successfully connected to the server\n"
                                    "now you can Login to the Bank System.");
    ui->frame->setEnabled(true);
    ui->pBConnect->setText("Try to Connent again");
}

void MainWindow::onDisconnectedServer()
{
    qDebug() << "User has disconnected from Server" << Qt::endl;

    // Show a QMessageBox
    QMessageBox::information(this, "Disconnected", "You have been disconnected from the server.");

    // Return to the login page
    ui->stackedWidget->setCurrentIndex(0);
    ui->frame->setEnabled(false);
    ui->pBConnect->setText("Try to Connent again");
}


void MainWindow::onErrorOccurredServer(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->Console->addItem(meta.valueToKey(socketError));
    qDebug()<<meta.valueToKey(socketError);
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

void MainWindow::onStateChangedServer(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->Console->addItem(meta.valueToKey(socketState));
    qDebug()<<meta.valueToKey(socketState)<<Qt::endl;
}

void MainWindow::onReadyReadServer(QString Data)
{
    QString data = QString("User Recieved response from server is ==> %1").arg(Data);
    qDebug()<<data<<Qt::endl;
    requestResponse(Data);
}

void MainWindow::onUserSendRequest(QString Data)
{
    QString data = QString("User send request to server ==> %1").arg(Data);
    qDebug()<<data<<Qt::endl;
}

void MainWindow::on_pBConnect_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
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
        SystemUser.SendRequest(message);
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
        SystemUser.SendRequest(message);
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
    SystemUser.SendRequest(message);
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
    SystemUser.SendRequest(message);
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
    SystemUser.SendRequest(message);
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
        QString message = QString("GetTransactionHistory:%1:%2").arg(accountNumber).arg(historyCountStr);
        SystemUser.SendRequest(message);
    }
}


void MainWindow::on_pB_ViewBankDatabase_clicked()
{
    SystemUser.SendRequest("GetBankDataBase:");
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
    loggerAccountNumber = number;
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
        QString message = QString("UpdateAccount:%1:%2:%3:%4:%5:%6").arg(fullName).arg(userName).arg(passWord).arg(age).arg(email).arg(loggerAccountNumber);
        SystemUser.SendRequest(message);
    }
    else if (!match.hasMatch())
    {
        ui->UpdateEmailErrorLabel->setText("Valid email is required.");
        ui->UpdateEmailErrorLabel->setVisible(true);
    }
    else
    {
        ui->UpdateEmailErrorLabel->setVisible(false);
        QString message = QString("UpdateAccount:%1:%2:%3:%4:%5:%6").arg(fullName).arg(userName).arg(passWord).arg(age).arg(email).arg(loggerAccountNumber);
        SystemUser.SendRequest(message);
    }

}


void MainWindow::on_pB_ClientGetAccountNumber_clicked()
{
    QMessageBox::information(this, "Request response", "Account number: "+loggerAccountNumber);
}


void MainWindow::on_pB_ClientViewAccountBalance_clicked()
{
    QString message = QString("GetAccountBalance:%1").arg(loggerAccountNumber);
    SystemUser.SendRequest(message);
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
        QString message = QString("GetTransactionHistory:%1:%2").arg(loggerAccountNumber).arg(historyCountStr);
        SystemUser.SendRequest(message);
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
            QString message = QString("MakeTransaction:%1:%2").arg(loggerAccountNumber).arg(transactionAmount);
            SystemUser.SendRequest(message);
        }
        else
        {
            // Show an error message if the input is invalid
            QMessageBox::warning(this, tr("Invalid Input"),
                                 tr("Please enter a valid transaction amount (e.g., +100 for deposit, -50 for withdrawal)."));
        }
    }
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
                QString message = QString("MakeTransfer:%1:%2:%3").arg(loggerAccountNumber).arg(targetAccountNumber).arg(amount);
                SystemUser.SendRequest(message);
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




void MainWindow::on_showPasswordCheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        ui->lEPassword->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lEPassword->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_pBAdminLogout_clicked()
{
    ui->lEUserName->clear();
    ui->lEPassword->clear();
    QString message = QString("Logout:%1").arg(loggerUserName);
    SystemUser.SendRequest(message);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pBClientLogout_clicked()
{
    ui->lEUserName->clear();
    ui->lEPassword->clear();
    QString message = QString("Logout:%1").arg(loggerUserName);
    SystemUser.SendRequest(message);
    ui->stackedWidget->setCurrentIndex(0);
}

