#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QInputDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include"User.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void requestResponse(QString message);
public slots:
    void onConnectedServer();
    void onDisconnectedServer();
    void onErrorOccurredServer(QAbstractSocket::SocketError socketError);
    void onStateChangedServer(QAbstractSocket::SocketState socketState);
    void onReadyReadServer(QString Data);
    void onUserSendRequest(QString Data);
private slots:

    void on_pBConnect_clicked();
    void on_pBLogin_clicked();
    void on_pB_AddAccount_clicked();
    void on_pBCreateAccount_clicked();
    void on_pBAddAccoutBack_clicked();
    void on_pB_AdminGetAccountNumber_clicked();
    void on_pB_DeleteAccount_clicked();
    void on_pB_AdminGetAccountBalance_clicked();
    void on_pB_AdminViewTransactionHistory_clicked();
    void on_pBAdminViewTransactionBack_clicked();
    void on_pBAdminViewTransactionView_clicked();
    void on_pB_ViewBankDatabase_clicked();
    void on_pB_ViewBankDatabaseBack_clicked();
    void on_pB_UpdateClientAccount_clicked();
    void on_pB_ClientUpdateAccountBack_clicked();
    void on_pB_Update_clicked();
    void on_pB_ClientGetAccountNumber_clicked();
    void on_pB_ClientViewAccountBalance_clicked();
    void on_pb_ViewMyHistoryBack_clicked();
    void on_pB_ViewMyHistory_clicked();
    void on_pb_ViewMyHistoryView_clicked();
    void on_pB_MakeTransaction_clicked();
    void on_pB_ClientTransferMoney_clicked();
    void on_showPasswordCheckBox_stateChanged(int arg1);
    void on_pBAdminLogout_clicked();
    void on_pBClientLogout_clicked();

private:
    Ui::MainWindow *ui;
    User SystemUser;
    QString loggerAccountNumber;
    QString loggerUserName;
};
#endif // MAINWINDOW_H
