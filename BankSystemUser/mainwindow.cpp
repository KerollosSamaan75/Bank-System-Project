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
    ui->NewUserAge->setValidator(new QIntValidator(0, 99, this)); // Age between 0 and 99
    ui->NewUserBalance->setValidator(new QIntValidator(0, 1000000, this));
    ui->AdminViewHistoryAccountNumberErrorLabel->setVisible(false);
    ui->AdminViewHistoryCountErrorLabel->setVisible(false);
    ui->lE_AdminViewHistoryAccountNumber->setPlaceholderText("Enter account number");
    ui->lE_AdminViewHistoryCount->setPlaceholderText("Enter history count");
    ui->UpdateAccountFullName->setPlaceholderText("Enter your fullname");
    ui->UpdateAccountUserName->setPlaceholderText("Enter your username");
    ui->UpdateAccountAge->setPlaceholderText("Enter your age");
    ui->UpdateAccountEmail->setPlaceholderText("Enter your email");
    ui->UpdateAccountPassword->setPlaceholderText("Enter your password");
    ui->UpdateAccountAge->setValidator(new QIntValidator(0, 99, this)); // Age between 0 and 99
    ui->UpdateEmailErrorLabel->setVisible(false);
    ui->UpdateFullNameErrorLabel->setVisible(false);
    ui->UpdatePasswordErrorLabel->setVisible(false);
    ui->UpdateUserNameErrorLabel->setVisible(false);
    ui->UpdateAgeErrorLabel->setVisible(false);
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
        ui->lEUserName->clear();
        ui->lEPassword->clear();
    }
    else if(List[0] =="Admin")
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->Adminlabel->setText(List[0]+":"+List[1]);
        adminUserName =List[1];
        ui->lEUserName->clear();
        ui->lEPassword->clear();

    }
    else if(List[0] == "ViewBankDataBase")
    {
        // Remove the prefix and parse the JSON data
        QString jsonData = message.mid(QString("ViewBankDataBase:").length());
        QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
        QJsonArray jsonArray = doc.array();

        // Create a model for the table view
        QStandardItemModel *model = new QStandardItemModel(jsonArray.size(), 8, this);
        QStringList headers = {"Account Number", "Username", "Full Name", "Age", "Email", "Balance", "Authority", "Login"};
        model->setHorizontalHeaderLabels(headers);

        // Iterate through the JSON array and add data to the model
        for (int row = 0; row < jsonArray.size(); ++row)
        {
            QJsonObject obj = jsonArray[row].toObject();

            model->setItem(row, 0, new QStandardItem(obj["AccountNumber"].toString("N/A")));
            model->setItem(row, 1, new QStandardItem(obj["Username"].toString("N/A")));
            model->setItem(row, 2, new QStandardItem(obj["FullName"].toString("N/A")));
            model->setItem(row, 3, new QStandardItem(obj["Age"].toString("N/A")));
            model->setItem(row, 4, new QStandardItem(obj["Email"].toString("N/A")));
            model->setItem(row, 5, new QStandardItem(obj["Balance"].toString("N/A")));
            model->setItem(row, 6, new QStandardItem(obj["Authority"].toString("N/A")));
            model->setItem(row, 7, new QStandardItem(obj["Login"].toString("N/A")));
        }

        // Set the model to the table view
        ui->BankDataBaseTableView->setModel(model);
    }

    else if(List[0] == "TransactionHistory")
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

        // Create a model for the table view
        QStandardItemModel *model = new QStandardItemModel(transactions.size(), 3, this);
        model->setHorizontalHeaderLabels({"Date", "Time", "Amount"});

        // Set account number as a header
        ui->AdTransactionHistoryTableView->setModel(model);
        ui->ClientTransactionHistoryTableView->setModel(model);

        // Iterate through the transactions and add them to the model
        for (int row = 0; row < transactions.size(); ++row)
        {
            QJsonObject transaction = transactions[row].toObject();
            QString amount = transaction["amount"].toString();
            QString date = transaction["date"].toString();
            QString time = transaction["time"].toString();

            model->setItem(row, 0, new QStandardItem(date));
            model->setItem(row, 1, new QStandardItem(time));
            model->setItem(row, 2, new QStandardItem(amount));
        }
    }
    else
    {
        QMessageBox::information(this, "Request response", message);
    }
}



void MainWindow::onConnectedServer()
{
    ui->Console->clear();
    ui->Console->addItem("User has connected to Server");
    qDebug()<<"User has connected to Server";
    QMessageBox::information(this, "Connection Successful", "You have successfully connected to the server");
    ui->frame->setEnabled(true);
    ui->pBConnect->hide();
    ui->pB_AdminConnectAgain->hide();
    ui->pB_ClientConnectAgain->hide();
    ui->pB_AddAccountConnectAgain->hide();
    ui->pB_ViewTransactionHistoryConnectAgain->hide();
    ui->pB_ViewBankDataBaseConnectAgain->hide();
    ui->pB_UpdateAccountConnectAgain->hide();
    ui->pB_ViewClientTransactionHistoryConnectAgain->hide();
}

void MainWindow::onDisconnectedServer()
{
    qDebug() << "User has disconnected from Server" << Qt::endl;

    // Show a QMessageBox
    QMessageBox::information(this, "Disconnected", "You have been disconnected from the server.\nPlease try to connect again");

    //the login page
    ui->frame->setEnabled(false);
    ui->Console->clear();
    ui->pBConnect->setVisible(true);
    ui->pBConnect->setText("Try to Connent again");

    //Admin page
    ui->pB_AdminConnectAgain->setVisible(true);
    //Client page
    ui->pB_ClientConnectAgain->setVisible(true);
    //Add account page
    ui->pB_AddAccountConnectAgain->setVisible(true);
    ui->pB_ViewTransactionHistoryConnectAgain->setVisible(true);
    ui->pB_ViewBankDataBaseConnectAgain->setVisible(true);
    ui->pB_UpdateAccountConnectAgain->setVisible(true);
    ui->pB_ViewClientTransactionHistoryConnectAgain->setVisible(true);
}


void MainWindow::onErrorOccurredServer(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->Console->clear();
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
    ui->Console->clear();
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

    // Check if fullname is empty, contains non-alphabetical characters, or is less than 5 characters long
    QRegularExpression nameRegex("^[a-zA-Z ]{5,}$"); // Regex for alphabetical characters, spaces, and minimum length of 5
    QRegularExpressionMatch nameMatch = nameRegex.match(ui->NewUserFullName->text());
    if (ui->NewUserFullName->text().isEmpty() || !nameMatch.hasMatch())
    {
        ui->NewUserFullNameErrorLabel->setText("Full name is required Minimum 5 characters\nMust contain only alphabetical characters");
        ui->NewUserFullNameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserFullNameErrorLabel->setVisible(false);
    }

    // Check if username is empty or does not contain both alphabetical characters and digits
    QRegularExpression usernameRegex("^(?=.*[a-zA-Z])(?=.*\\d)[a-zA-Z0-9]+$"); // Regex for at least one alphabetical character and one digit
    QRegularExpressionMatch usernameMatch = usernameRegex.match(ui->NewUserUserName->text());
    if (ui->NewUserUserName->text().isEmpty() || !usernameMatch.hasMatch())
    {
        ui->NewUserUserNameErrorLabel->setText("Username is required without spaces\nMust contain both alphabetical characters and digits.");
        ui->NewUserUserNameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserUserNameErrorLabel->setVisible(false);
    }

    QRegularExpression passwordRegex("^(?=.*[a-zA-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$"); // Regex for password complexity
    QRegularExpressionMatch passwordMatch = passwordRegex.match(ui->NewUserPassWord->text());
    if (ui->NewUserPassWord->text().isEmpty() || !passwordMatch.hasMatch())
    {
        ui->NewUserPassWordErrorLabel->setText("Password must be at least 8 characters long\ninclude at least one letter,one number,and one special char.");
        ui->NewUserPassWordErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserPassWordErrorLabel->setVisible(false);
    }

    // Check if age is empty
    if (ui->NewUserAge->text().isEmpty() || (ui->NewUserAge->text().toInt()) < 18)
    {
        ui->NewUserAgeErrorLabel->setText("Valid age is required.must be 18 or more");
        ui->NewUserAgeErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->NewUserAgeErrorLabel->setVisible(false);
    }

    // Check if email is empty or not valid
    QRegularExpression emailRegex("^[\\w\\.]+@[\\w\\.]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch emailMatch = emailRegex.match(ui->NewUserEmail->text());
    if (ui->NewUserEmail->text().isEmpty() || !emailMatch.hasMatch())
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
    ui->AdTransactionHistoryTableView->clearFocus();
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
        ui->AdTransactionHistoryTableView->clearFocus();
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
    clientAccountNumber = number;
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_pB_ClientUpdateAccountBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pB_Update_clicked()
{
    bool valid = true;

    QString fullName = ui->UpdateAccountFullName->text();
    QString userName = ui->UpdateAccountUserName->text();
    QString passWord = ui->UpdateAccountPassword->text();
    int age = ui->UpdateAccountAge->text().toInt();
    QString email = ui->UpdateAccountEmail->text();

    // Full name validation
    QRegularExpression nameRegex("^[a-zA-Z ]{5,}$"); // Regex for alphabetical characters, spaces, and minimum length of 5
    QRegularExpressionMatch nameMatch = nameRegex.match(fullName);
    if (!fullName.isEmpty() && !nameMatch.hasMatch())
    {
        ui->UpdateFullNameErrorLabel->setText("Full name must contain only alphabetical characters and be at least 5 characters long.");
        ui->UpdateFullNameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->UpdateFullNameErrorLabel->setVisible(false);
    }

    // Username validation
    QRegularExpression usernameRegex("^(?=.*[a-zA-Z])(?=.*\\d)[a-zA-Z0-9]+$"); // Regex for at least one alphabetical character and one digit
    QRegularExpressionMatch usernameMatch = usernameRegex.match(userName);
    if (!userName.isEmpty() && !usernameMatch.hasMatch())
    {
        ui->UpdateUserNameErrorLabel->setText("Username must contain both alphabetical characters and digits, and no spaces.");
        ui->UpdateUserNameErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->UpdateUserNameErrorLabel->setVisible(false);
    }

    // Password validation
    QRegularExpression passwordRegex("^(?=.*[a-zA-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$"); // Regex for password complexity
    QRegularExpressionMatch passwordMatch = passwordRegex.match(passWord);
    if (!passWord.isEmpty() && !passwordMatch.hasMatch())
    {
        ui->UpdatePasswordErrorLabel->setText("Password must be at least 8 characters long and include at least one letter, one number, and one special character.");
        ui->UpdatePasswordErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->UpdatePasswordErrorLabel->setVisible(false);
    }

    // Age validation
    if (!ui->UpdateAccountAge->text().isEmpty() && age < 18)
    {
        ui->UpdateAgeErrorLabel->setText("Valid age is required.must be 18 or more");
        ui->UpdateAgeErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->UpdateAgeErrorLabel->setVisible(false);
    }

    // Email validation
    QRegularExpression emailRegex("^[\\w\\.]+@[\\w\\.]+\\.[a-zA-Z]{2,}$");
    QRegularExpressionMatch emailMatch = emailRegex.match(email);
    if (!email.isEmpty() && !emailMatch.hasMatch())
    {
        ui->UpdateEmailErrorLabel->setText("Valid email is required.");
        ui->UpdateEmailErrorLabel->setVisible(true);
        valid = false;
    }
    else
    {
        ui->UpdateEmailErrorLabel->setVisible(false);
    }


    if (valid)
    {
        QString message = "UpdateAccount";

        // Add only the updated fields to the message
        if (!fullName.isEmpty())
        {
            message.append(QString(":%1").arg(fullName));
        }
        else
        {
            message.append(":");
        }

        if (!userName.isEmpty())
        {
            message.append(QString(":%1").arg(userName));
        }
        else
        {
            message.append(":");
        }

        if (!passWord.isEmpty())
        {
            message.append(QString(":%1").arg(passWord));
        }
        else
        {
            message.append(":");
        }

        if (age > 0)
        {
            message.append(QString(":%1").arg(age));
        }
        else
        {
            message.append(":");
        }

        if (!email.isEmpty())
        {
            message.append(QString(":%1").arg(email));
        }
        else
        {
            message.append(":");
        }

        // Add client account number to the message
        message.append(QString(":%1").arg(clientAccountNumber));

        SystemUser.SendRequest(message);
    }
}



void MainWindow::on_pB_ClientGetAccountNumber_clicked()
{
    QString message = QString("GetAccountNumber:%1").arg(clientUserName);
    SystemUser.SendRequest(message);
}


void MainWindow::on_pB_ClientViewAccountBalance_clicked()
{
    QString message = QString("GetAccountBalance:%1").arg(clientAccountNumber);
    SystemUser.SendRequest(message);
}


void MainWindow::on_pb_ViewMyHistoryBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pB_ViewMyHistory_clicked()
{
    ui->ClientTransactionHistoryTableView->clearFocus();
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
        ui->ClientTransactionHistoryTableView->clearFocus();
        QString message = QString("GetTransactionHistory:%1:%2").arg(clientAccountNumber).arg(historyCountStr);
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
            QString message = QString("MakeTransaction:%1:%2").arg(clientAccountNumber).arg(transactionAmount);
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
                QString message = QString("MakeTransfer:%1:%2:%3").arg(clientAccountNumber).arg(targetAccountNumber).arg(amount);
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
    QString message = QString("Logout:%1").arg(adminUserName);
    SystemUser.SendRequest(message);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pBClientLogout_clicked()
{
    ui->lEUserName->clear();
    ui->lEPassword->clear();
    QString message = QString("Logout:%1").arg(clientUserName);
    SystemUser.SendRequest(message);
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pB_AdminConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}


void MainWindow::on_pB_AddAccountConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}


void MainWindow::on_pB_ClientConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}


void MainWindow::on_pB_ViewTransactionHistoryConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}


void MainWindow::on_pB_ViewBankDataBaseConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}


void MainWindow::on_pB_UpdateAccountConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}


void MainWindow::on_pB_ViewClientTransactionHistoryConnectAgain_clicked()
{
    SystemUser.ConnectToServer("192.168.1.17",1234);
}

