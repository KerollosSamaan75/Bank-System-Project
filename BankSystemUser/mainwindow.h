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
    void onConnectedDevice();
    void onDisconnectedDevice();
    void onErrorOccurredDevice(QAbstractSocket::SocketError socketError);
    void onStateChangedDevice(QAbstractSocket::SocketState socketState);
    void onReadyReadDevice(QString Data);
    void onUserWriteData(QString Data);
private slots:

    void on_pBConnect_clicked();
    void on_pBLogin_clicked();

    void on_pB_AddAccount_clicked();

    void on_pBCreateAccount_clicked();

    void on_pBAddAccoutBack_clicked();

    void on_pB_AdminGetAccountNumber_clicked();

    void on_pB_DeleteAccount_clicked();

    void on_pBAdminBack_clicked();

    void on_pB_AdminGetAccountBalance_clicked();

    void on_pB_AdminViewTransactionHistory_clicked();

    void on_pBAdminViewTransactionBack_clicked();

    void on_pBAdminViewTransactionView_clicked();

    void on_pB_ViewBankDatabase_clicked();

    void on_pB_ViewBankDatabase_2_clicked();

    void on_pB_ViewBankDatabaseBack_clicked();

    void on_pB_UpdateClientAccount_clicked();

    void on_pB_ClientUpdateAccountBack_clicked();

    void on_pB_Update_clicked();

    void on_pB_ClientGetAccountNumber_clicked();

private:
    Ui::MainWindow *ui;
    User SystemUser;
    QString Ad_accountNumber;
    QString clientAccountNumber;
    QString clientUserName;
};
#endif // MAINWINDOW_H
