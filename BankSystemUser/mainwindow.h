#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Include QMainWindow for main window functionality
#include <QMessageBox> // Include QMessageBox for message boxes
#include <QIntValidator> // Include QIntValidator for integer validation
#include <QDoubleValidator> // Include QDoubleValidator for double validation
#include <QRegularExpression> // Include QRegularExpression for regular expressions
#include <QRegularExpressionValidator> // Include QRegularExpressionValidator for regex validation
#include <QInputDialog> // Include QInputDialog for input dialogs
#include <QJsonArray> // Include QJsonArray for JSON array handling
#include <QJsonDocument> // Include QJsonDocument for JSON document handling
#include <QJsonObject> // Include QJsonObject for JSON object handling
#include <QStandardItemModel> // Include QStandardItemModel for item models
#include <QNetworkInterface>
#include <QHostAddress>
#include "User.h" // Include the User class

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow; // Forward declare the Ui::MainWindow class
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow // Define MainWindow class inheriting from QMainWindow
{
    Q_OBJECT // Enable meta-object features like signals and slots

public:
    MainWindow(QWidget *parent = nullptr); // Constructor with optional parent parameter
    ~MainWindow(); // Destructor
    void requestResponse(QString message); // Method to handle request responses

public slots:
    void onConnectedServer(); // Slot called when connected to server
    void onDisconnectedServer(); // Slot called when disconnected from server
    void onErrorOccurredServer(QAbstractSocket::SocketError socketError); // Slot called on socket error
    void onStateChangedServer(QAbstractSocket::SocketState socketState); // Slot called on socket state change
    void onReadyReadServer(QString Data); // Slot called when data is ready to read
    void onUserSendRequest(QString Data); // Slot called when user sends a request

private slots:
    void on_pBConnect_clicked(); // Slot for connect button click
    void on_pBLogin_clicked(); // Slot for login button click
    void on_pB_AddAccount_clicked(); // Slot for add account button click
    void on_pBCreateAccount_clicked(); // Slot for create account button click
    void on_pBAddAccoutBack_clicked(); // Slot for add account back button click
    void on_pB_AdminGetAccountNumber_clicked(); // Slot for admin get account number button click
    void on_pB_DeleteAccount_clicked(); // Slot for delete account button click
    void on_pB_AdminGetAccountBalance_clicked(); // Slot for admin get account balance button click
    void on_pB_AdminViewTransactionHistory_clicked(); // Slot for admin view transaction history button click
    void on_pBAdminViewTransactionBack_clicked(); // Slot for admin view transaction back button click
    void on_pBAdminViewTransactionView_clicked(); // Slot for admin view transaction view button click
    void on_pB_ViewBankDatabase_clicked(); // Slot for view bank database button click
    void on_pB_ViewBankDatabaseBack_clicked(); // Slot for view bank database back button click
    void on_pB_UpdateClientAccount_clicked(); // Slot for update client account button click
    void on_pB_ClientUpdateAccountBack_clicked(); // Slot for client update account back button click
    void on_pB_Update_clicked(); // Slot for update button click
    void on_pB_ClientGetAccountNumber_clicked(); // Slot for client get account number button click
    void on_pB_ClientViewAccountBalance_clicked(); // Slot for client view account balance button click
    void on_pb_ViewMyHistoryBack_clicked(); // Slot for view my history back button click
    void on_pB_ViewMyHistory_clicked(); // Slot for view my history button click
    void on_pb_ViewMyHistoryView_clicked(); // Slot for view my history view button click
    void on_pB_MakeTransaction_clicked(); // Slot for make transaction button click
    void on_pB_ClientTransferMoney_clicked(); // Slot for client transfer money button click
    void on_showPasswordCheckBox_stateChanged(int arg1); // Slot for show password checkbox state change
    void on_pBAdminLogout_clicked(); // Slot for admin logout button click
    void on_pBClientLogout_clicked(); // Slot for client logout button click
    void on_pB_AdminConnectAgain_clicked(); // Slot for admin connect again button click
    void on_pB_AddAccountConnectAgain_clicked(); // Slot for add account connect again button click
    void on_pB_ClientConnectAgain_clicked(); // Slot for client connect again button click
    void on_pB_ViewTransactionHistoryConnectAgain_clicked(); // Slot for view transaction history connect again button click
    void on_pB_ViewBankDataBaseConnectAgain_clicked(); // Slot for view bank database connect again button click
    void on_pB_UpdateAccountConnectAgain_clicked(); // Slot for update account connect again button click
    void on_pB_ViewClientTransactionHistoryConnectAgain_clicked(); // Slot for view client transaction history connect again button click

private:
    Ui::MainWindow *ui; // Pointer to the UI
    User SystemUser; // Instance of the User class
    QString clientUserName; // Client username
    QString clientAccountNumber; // Client account number
    QString adminUserName; // Admin username
};

#endif // MAINWINDOW_H
