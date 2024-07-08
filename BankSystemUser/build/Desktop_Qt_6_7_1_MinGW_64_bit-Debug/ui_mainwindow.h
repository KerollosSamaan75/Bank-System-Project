/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Login;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *usernameErrorLabel;
    QLineEdit *lEUserName;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *passwordErrorLabel;
    QLineEdit *lEPassword;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pBLogin;
    QPushButton *pBClear;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QListWidget *Console;
    QPushButton *pBConnect;
    QWidget *Admin;
    QLabel *Adminlabel;
    QPushButton *pB_AddAccount;
    QPushButton *pB_AdminGetAccountNumber;
    QLabel *label_4;
    QPushButton *pB_DeleteAccount;
    QPushButton *pBAdminBack;
    QPushButton *pB_AdminGetAccountBalance;
    QPushButton *pB_AdminViewTransactionHistory;
    QPushButton *pB_ViewBankDatabase;
    QPushButton *pB_UpdateClientAccount;
    QWidget *Client;
    QLabel *Userlabel;
    QLabel *label_9;
    QPushButton *pB_ClientGetAccountNumber;
    QPushButton *pB_ClientViewAccountBalance;
    QPushButton *pB_ViewMyHistory;
    QPushButton *pB_MakeTransaction;
    QPushButton *pB_ClientBack;
    QPushButton *pB_ClientTransferMoney;
    QWidget *AddAccount;
    QLabel *AddAccountlabel;
    QPushButton *pBCreateAccount;
    QPushButton *pBAddAccoutBack;
    QLabel *label_3;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QLabel *NewUserFullNameErrorLabel;
    QLineEdit *NewUserFullName;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_6;
    QLabel *NewUserUserNameErrorLabel;
    QLineEdit *NewUserUserName;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_7;
    QLabel *NewUserPassWordErrorLabel;
    QLineEdit *NewUserPassWord;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_8;
    QLabel *NewUserEmailErrorLabel;
    QLineEdit *NewUserEmail;
    QWidget *layoutWidget8;
    QVBoxLayout *verticalLayout_9;
    QLabel *NewUserAgeErrorLabel;
    QLineEdit *NewUserAge;
    QWidget *layoutWidget9;
    QVBoxLayout *verticalLayout_10;
    QLabel *NewUserBalanceErrorLabel;
    QLineEdit *NewUserBalance;
    QWidget *AdminViewTransactionHistory;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *AdminViewHistoryAccountNumberErrorLabel;
    QLineEdit *lE_AdminViewHistoryAccountNumber;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_12;
    QLabel *AdminViewHistoryCountErrorLabel;
    QLineEdit *lE_AdminViewHistoryCount;
    QPushButton *pBAdminViewTransactionView;
    QPushButton *pBAdminViewTransactionBack;
    QListWidget *AdTransactionHistorylistWidget;
    QWidget *ViewBankDatabase;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pB_ViewBankDatabaseBack;
    QListWidget *BankDataBaselistWidget;
    QWidget *UpdateClientAccount;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *UpdateAccountPassword;
    QPushButton *pB_ClientUpdateAccountBack;
    QPushButton *pB_Update;
    QLineEdit *UpdateAccountUserName;
    QLineEdit *UpdateAccountAge;
    QLineEdit *UpdateAccountFullName;
    QWidget *layoutWidget10;
    QVBoxLayout *verticalLayout_37;
    QLabel *UpdateEmailErrorLabel;
    QLineEdit *UpdateAccountEmail;
    QWidget *ViewMyHistory;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pb_ViewMyHistoryBack;
    QPushButton *pb_ViewMyHistoryView;
    QListWidget *ClientTransactionHistoryListWidget;
    QWidget *layoutWidget11;
    QVBoxLayout *verticalLayout_13;
    QLabel *ClientViewHistoryCountErrorLabel;
    QLineEdit *lE_ClientViewHistoryCount;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(801, 642);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 781, 591));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));
        Login = new QWidget();
        Login->setObjectName("Login");
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 50, 671, 71));
        label->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 120, 351, 371));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_2->setScaledContents(true);
        frame = new QFrame(Login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(439, 200, 331, 381));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 311, 78));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usernameErrorLabel = new QLabel(layoutWidget);
        usernameErrorLabel->setObjectName("usernameErrorLabel");
        usernameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(usernameErrorLabel);

        lEUserName = new QLineEdit(layoutWidget);
        lEUserName->setObjectName("lEUserName");
        lEUserName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(lEUserName);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 117, 301, 78));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        passwordErrorLabel = new QLabel(layoutWidget1);
        passwordErrorLabel->setObjectName("passwordErrorLabel");
        passwordErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(passwordErrorLabel);

        lEPassword = new QLineEdit(layoutWidget1);
        lEPassword->setObjectName("lEPassword");
        lEPassword->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(lEPassword);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 223, 301, 151));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pBLogin = new QPushButton(layoutWidget2);
        pBLogin->setObjectName("pBLogin");
        pBLogin->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));

        verticalLayout_4->addWidget(pBLogin);

        pBClear = new QPushButton(layoutWidget2);
        pBClear->setObjectName("pBClear");
        pBClear->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));

        verticalLayout_4->addWidget(pBClear);

        layoutWidget3 = new QWidget(Login);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(40, 440, 351, 143));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Console = new QListWidget(layoutWidget3);
        Console->setObjectName("Console");
        Console->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"Segoe UI\";"));

        verticalLayout->addWidget(Console);

        pBConnect = new QPushButton(layoutWidget3);
        pBConnect->setObjectName("pBConnect");
        pBConnect->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));

        verticalLayout->addWidget(pBConnect);

        stackedWidget->addWidget(Login);
        Admin = new QWidget();
        Admin->setObjectName("Admin");
        Adminlabel = new QLabel(Admin);
        Adminlabel->setObjectName("Adminlabel");
        Adminlabel->setGeometry(QRect(20, 70, 501, 61));
        Adminlabel->setStyleSheet(QString::fromUtf8("font: 700 30pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        pB_AddAccount = new QPushButton(Admin);
        pB_AddAccount->setObjectName("pB_AddAccount");
        pB_AddAccount->setGeometry(QRect(20, 190, 351, 81));
        pB_AddAccount->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_AdminGetAccountNumber = new QPushButton(Admin);
        pB_AdminGetAccountNumber->setObjectName("pB_AdminGetAccountNumber");
        pB_AdminGetAccountNumber->setGeometry(QRect(400, 370, 341, 81));
        pB_AdminGetAccountNumber->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        label_4 = new QLabel(Admin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(520, 10, 221, 201));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_4->setScaledContents(true);
        pB_DeleteAccount = new QPushButton(Admin);
        pB_DeleteAccount->setObjectName("pB_DeleteAccount");
        pB_DeleteAccount->setGeometry(QRect(20, 280, 351, 81));
        pB_DeleteAccount->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pBAdminBack = new QPushButton(Admin);
        pBAdminBack->setObjectName("pBAdminBack");
        pBAdminBack->setGeometry(QRect(20, 520, 151, 61));
        pBAdminBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_AdminGetAccountBalance = new QPushButton(Admin);
        pB_AdminGetAccountBalance->setObjectName("pB_AdminGetAccountBalance");
        pB_AdminGetAccountBalance->setGeometry(QRect(400, 190, 341, 81));
        pB_AdminGetAccountBalance->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_AdminViewTransactionHistory = new QPushButton(Admin);
        pB_AdminViewTransactionHistory->setObjectName("pB_AdminViewTransactionHistory");
        pB_AdminViewTransactionHistory->setGeometry(QRect(400, 280, 341, 81));
        pB_AdminViewTransactionHistory->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_ViewBankDatabase = new QPushButton(Admin);
        pB_ViewBankDatabase->setObjectName("pB_ViewBankDatabase");
        pB_ViewBankDatabase->setGeometry(QRect(20, 370, 351, 81));
        pB_ViewBankDatabase->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_UpdateClientAccount = new QPushButton(Admin);
        pB_UpdateClientAccount->setObjectName("pB_UpdateClientAccount");
        pB_UpdateClientAccount->setGeometry(QRect(220, 460, 341, 81));
        pB_UpdateClientAccount->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        stackedWidget->addWidget(Admin);
        Client = new QWidget();
        Client->setObjectName("Client");
        Userlabel = new QLabel(Client);
        Userlabel->setObjectName("Userlabel");
        Userlabel->setGeometry(QRect(20, 50, 411, 111));
        Userlabel->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label_9 = new QLabel(Client);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(520, 20, 221, 191));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_9->setScaledContents(true);
        pB_ClientGetAccountNumber = new QPushButton(Client);
        pB_ClientGetAccountNumber->setObjectName("pB_ClientGetAccountNumber");
        pB_ClientGetAccountNumber->setGeometry(QRect(40, 230, 331, 81));
        pB_ClientGetAccountNumber->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_ClientViewAccountBalance = new QPushButton(Client);
        pB_ClientViewAccountBalance->setObjectName("pB_ClientViewAccountBalance");
        pB_ClientViewAccountBalance->setGeometry(QRect(220, 410, 331, 81));
        pB_ClientViewAccountBalance->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_ViewMyHistory = new QPushButton(Client);
        pB_ViewMyHistory->setObjectName("pB_ViewMyHistory");
        pB_ViewMyHistory->setGeometry(QRect(410, 230, 331, 81));
        pB_ViewMyHistory->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_MakeTransaction = new QPushButton(Client);
        pB_MakeTransaction->setObjectName("pB_MakeTransaction");
        pB_MakeTransaction->setGeometry(QRect(40, 320, 331, 81));
        pB_MakeTransaction->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_ClientBack = new QPushButton(Client);
        pB_ClientBack->setObjectName("pB_ClientBack");
        pB_ClientBack->setGeometry(QRect(50, 510, 121, 61));
        pB_ClientBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_ClientTransferMoney = new QPushButton(Client);
        pB_ClientTransferMoney->setObjectName("pB_ClientTransferMoney");
        pB_ClientTransferMoney->setGeometry(QRect(410, 320, 341, 81));
        pB_ClientTransferMoney->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
"background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        stackedWidget->addWidget(Client);
        AddAccount = new QWidget();
        AddAccount->setObjectName("AddAccount");
        AddAccountlabel = new QLabel(AddAccount);
        AddAccountlabel->setObjectName("AddAccountlabel");
        AddAccountlabel->setGeometry(QRect(40, 40, 341, 111));
        AddAccountlabel->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        pBCreateAccount = new QPushButton(AddAccount);
        pBCreateAccount->setObjectName("pBCreateAccount");
        pBCreateAccount->setGeometry(QRect(470, 510, 241, 71));
        pBCreateAccount->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pBAddAccoutBack = new QPushButton(AddAccount);
        pBAddAccoutBack->setObjectName("pBAddAccoutBack");
        pBAddAccoutBack->setGeometry(QRect(50, 510, 241, 71));
        pBAddAccoutBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        label_3 = new QLabel(AddAccount);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 10, 351, 191));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_3->setScaledContents(true);
        layoutWidget4 = new QWidget(AddAccount);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(20, 210, 361, 78));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        NewUserFullNameErrorLabel = new QLabel(layoutWidget4);
        NewUserFullNameErrorLabel->setObjectName("NewUserFullNameErrorLabel");
        NewUserFullNameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_5->addWidget(NewUserFullNameErrorLabel);

        NewUserFullName = new QLineEdit(layoutWidget4);
        NewUserFullName->setObjectName("NewUserFullName");
        NewUserFullName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_5->addWidget(NewUserFullName);

        layoutWidget5 = new QWidget(AddAccount);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(20, 310, 361, 78));
        verticalLayout_6 = new QVBoxLayout(layoutWidget5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        NewUserUserNameErrorLabel = new QLabel(layoutWidget5);
        NewUserUserNameErrorLabel->setObjectName("NewUserUserNameErrorLabel");
        NewUserUserNameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_6->addWidget(NewUserUserNameErrorLabel);

        NewUserUserName = new QLineEdit(layoutWidget5);
        NewUserUserName->setObjectName("NewUserUserName");
        NewUserUserName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_6->addWidget(NewUserUserName);

        layoutWidget6 = new QWidget(AddAccount);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(20, 410, 361, 78));
        verticalLayout_7 = new QVBoxLayout(layoutWidget6);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        NewUserPassWordErrorLabel = new QLabel(layoutWidget6);
        NewUserPassWordErrorLabel->setObjectName("NewUserPassWordErrorLabel");
        NewUserPassWordErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_7->addWidget(NewUserPassWordErrorLabel);

        NewUserPassWord = new QLineEdit(layoutWidget6);
        NewUserPassWord->setObjectName("NewUserPassWord");
        NewUserPassWord->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_7->addWidget(NewUserPassWord);

        layoutWidget7 = new QWidget(AddAccount);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(412, 210, 351, 78));
        verticalLayout_8 = new QVBoxLayout(layoutWidget7);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        NewUserEmailErrorLabel = new QLabel(layoutWidget7);
        NewUserEmailErrorLabel->setObjectName("NewUserEmailErrorLabel");
        NewUserEmailErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_8->addWidget(NewUserEmailErrorLabel);

        NewUserEmail = new QLineEdit(layoutWidget7);
        NewUserEmail->setObjectName("NewUserEmail");
        NewUserEmail->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_8->addWidget(NewUserEmail);

        layoutWidget8 = new QWidget(AddAccount);
        layoutWidget8->setObjectName("layoutWidget8");
        layoutWidget8->setGeometry(QRect(410, 310, 351, 78));
        verticalLayout_9 = new QVBoxLayout(layoutWidget8);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        NewUserAgeErrorLabel = new QLabel(layoutWidget8);
        NewUserAgeErrorLabel->setObjectName("NewUserAgeErrorLabel");
        NewUserAgeErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(NewUserAgeErrorLabel);

        NewUserAge = new QLineEdit(layoutWidget8);
        NewUserAge->setObjectName("NewUserAge");
        NewUserAge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(NewUserAge);

        layoutWidget9 = new QWidget(AddAccount);
        layoutWidget9->setObjectName("layoutWidget9");
        layoutWidget9->setGeometry(QRect(412, 410, 351, 78));
        verticalLayout_10 = new QVBoxLayout(layoutWidget9);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        NewUserBalanceErrorLabel = new QLabel(layoutWidget9);
        NewUserBalanceErrorLabel->setObjectName("NewUserBalanceErrorLabel");
        NewUserBalanceErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_10->addWidget(NewUserBalanceErrorLabel);

        NewUserBalance = new QLineEdit(layoutWidget9);
        NewUserBalance->setObjectName("NewUserBalance");
        NewUserBalance->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_10->addWidget(NewUserBalance);

        stackedWidget->addWidget(AddAccount);
        AdminViewTransactionHistory = new QWidget();
        AdminViewTransactionHistory->setObjectName("AdminViewTransactionHistory");
        label_5 = new QLabel(AdminViewTransactionHistory);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 30, 361, 141));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label_6 = new QLabel(AdminViewTransactionHistory);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(430, 10, 291, 181));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_6->setScaledContents(true);
        layoutWidget_2 = new QWidget(AdminViewTransactionHistory);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 240, 361, 78));
        verticalLayout_11 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        AdminViewHistoryAccountNumberErrorLabel = new QLabel(layoutWidget_2);
        AdminViewHistoryAccountNumberErrorLabel->setObjectName("AdminViewHistoryAccountNumberErrorLabel");
        AdminViewHistoryAccountNumberErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_11->addWidget(AdminViewHistoryAccountNumberErrorLabel);

        lE_AdminViewHistoryAccountNumber = new QLineEdit(layoutWidget_2);
        lE_AdminViewHistoryAccountNumber->setObjectName("lE_AdminViewHistoryAccountNumber");
        lE_AdminViewHistoryAccountNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_11->addWidget(lE_AdminViewHistoryAccountNumber);

        layoutWidget_3 = new QWidget(AdminViewTransactionHistory);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(20, 360, 361, 78));
        verticalLayout_12 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        AdminViewHistoryCountErrorLabel = new QLabel(layoutWidget_3);
        AdminViewHistoryCountErrorLabel->setObjectName("AdminViewHistoryCountErrorLabel");
        AdminViewHistoryCountErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_12->addWidget(AdminViewHistoryCountErrorLabel);

        lE_AdminViewHistoryCount = new QLineEdit(layoutWidget_3);
        lE_AdminViewHistoryCount->setObjectName("lE_AdminViewHistoryCount");
        lE_AdminViewHistoryCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_12->addWidget(lE_AdminViewHistoryCount);

        pBAdminViewTransactionView = new QPushButton(AdminViewTransactionHistory);
        pBAdminViewTransactionView->setObjectName("pBAdminViewTransactionView");
        pBAdminViewTransactionView->setGeometry(QRect(220, 500, 171, 71));
        pBAdminViewTransactionView->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pBAdminViewTransactionBack = new QPushButton(AdminViewTransactionHistory);
        pBAdminViewTransactionBack->setObjectName("pBAdminViewTransactionBack");
        pBAdminViewTransactionBack->setGeometry(QRect(10, 500, 161, 71));
        pBAdminViewTransactionBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        AdTransactionHistorylistWidget = new QListWidget(AdminViewTransactionHistory);
        AdTransactionHistorylistWidget->setObjectName("AdTransactionHistorylistWidget");
        AdTransactionHistorylistWidget->setGeometry(QRect(430, 190, 321, 371));
        AdTransactionHistorylistWidget->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(AdminViewTransactionHistory);
        ViewBankDatabase = new QWidget();
        ViewBankDatabase->setObjectName("ViewBankDatabase");
        label_7 = new QLabel(ViewBankDatabase);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(520, 20, 221, 161));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(ViewBankDatabase);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(48, 50, 451, 111));
        label_8->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        pB_ViewBankDatabaseBack = new QPushButton(ViewBankDatabase);
        pB_ViewBankDatabaseBack->setObjectName("pB_ViewBankDatabaseBack");
        pB_ViewBankDatabaseBack->setGeometry(QRect(30, 520, 141, 61));
        pB_ViewBankDatabaseBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        BankDataBaselistWidget = new QListWidget(ViewBankDatabase);
        BankDataBaselistWidget->setObjectName("BankDataBaselistWidget");
        BankDataBaselistWidget->setGeometry(QRect(25, 170, 731, 341));
        BankDataBaselistWidget->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        BankDataBaselistWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        BankDataBaselistWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        stackedWidget->addWidget(ViewBankDatabase);
        UpdateClientAccount = new QWidget();
        UpdateClientAccount->setObjectName("UpdateClientAccount");
        label_28 = new QLabel(UpdateClientAccount);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(30, 30, 371, 101));
        label_28->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label_29 = new QLabel(UpdateClientAccount);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(530, 30, 201, 151));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_29->setScaledContents(true);
        UpdateAccountPassword = new QLineEdit(UpdateClientAccount);
        UpdateAccountPassword->setObjectName("UpdateAccountPassword");
        UpdateAccountPassword->setGeometry(QRect(40, 440, 671, 44));
        UpdateAccountPassword->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));
        pB_ClientUpdateAccountBack = new QPushButton(UpdateClientAccount);
        pB_ClientUpdateAccountBack->setObjectName("pB_ClientUpdateAccountBack");
        pB_ClientUpdateAccountBack->setGeometry(QRect(50, 500, 121, 61));
        pB_ClientUpdateAccountBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pB_Update = new QPushButton(UpdateClientAccount);
        pB_Update->setObjectName("pB_Update");
        pB_Update->setGeometry(QRect(220, 500, 141, 61));
        pB_Update->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        UpdateAccountUserName = new QLineEdit(UpdateClientAccount);
        UpdateAccountUserName->setObjectName("UpdateAccountUserName");
        UpdateAccountUserName->setGeometry(QRect(40, 230, 671, 44));
        UpdateAccountUserName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));
        UpdateAccountAge = new QLineEdit(UpdateClientAccount);
        UpdateAccountAge->setObjectName("UpdateAccountAge");
        UpdateAccountAge->setGeometry(QRect(40, 290, 671, 44));
        UpdateAccountAge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));
        UpdateAccountFullName = new QLineEdit(UpdateClientAccount);
        UpdateAccountFullName->setObjectName("UpdateAccountFullName");
        UpdateAccountFullName->setGeometry(QRect(40, 170, 671, 44));
        UpdateAccountFullName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));
        layoutWidget10 = new QWidget(UpdateClientAccount);
        layoutWidget10->setObjectName("layoutWidget10");
        layoutWidget10->setGeometry(QRect(40, 350, 671, 78));
        verticalLayout_37 = new QVBoxLayout(layoutWidget10);
        verticalLayout_37->setObjectName("verticalLayout_37");
        verticalLayout_37->setContentsMargins(0, 0, 0, 0);
        UpdateEmailErrorLabel = new QLabel(layoutWidget10);
        UpdateEmailErrorLabel->setObjectName("UpdateEmailErrorLabel");
        UpdateEmailErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_37->addWidget(UpdateEmailErrorLabel);

        UpdateAccountEmail = new QLineEdit(layoutWidget10);
        UpdateAccountEmail->setObjectName("UpdateAccountEmail");
        UpdateAccountEmail->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_37->addWidget(UpdateAccountEmail);

        stackedWidget->addWidget(UpdateClientAccount);
        ViewMyHistory = new QWidget();
        ViewMyHistory->setObjectName("ViewMyHistory");
        label_10 = new QLabel(ViewMyHistory);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 20, 471, 151));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        label_11 = new QLabel(ViewMyHistory);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(540, 10, 201, 161));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_11->setScaledContents(true);
        pb_ViewMyHistoryBack = new QPushButton(ViewMyHistory);
        pb_ViewMyHistoryBack->setObjectName("pb_ViewMyHistoryBack");
        pb_ViewMyHistoryBack->setGeometry(QRect(20, 490, 131, 71));
        pb_ViewMyHistoryBack->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        pb_ViewMyHistoryView = new QPushButton(ViewMyHistory);
        pb_ViewMyHistoryView->setObjectName("pb_ViewMyHistoryView");
        pb_ViewMyHistoryView->setGeometry(QRect(200, 490, 141, 71));
        pb_ViewMyHistoryView->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; \n"
"font: 700 20pt \"Segoe UI\";\n"
"        border: none;\n"
"                   color: white;\n"
"                   padding: 15px 20px;\n"
"                   text-align: center;\n"
"                   text-decoration: none;\n"
"                   display: inline-block;\n"
"                   font-size: 20px;\n"
"                   margin: 4px 2px;\n"
"                   border-radius: 20px; \n"
"\n"
""));
        ClientTransactionHistoryListWidget = new QListWidget(ViewMyHistory);
        ClientTransactionHistoryListWidget->setObjectName("ClientTransactionHistoryListWidget");
        ClientTransactionHistoryListWidget->setGeometry(QRect(390, 170, 381, 401));
        ClientTransactionHistoryListWidget->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        layoutWidget11 = new QWidget(ViewMyHistory);
        layoutWidget11->setObjectName("layoutWidget11");
        layoutWidget11->setGeometry(QRect(10, 240, 361, 78));
        verticalLayout_13 = new QVBoxLayout(layoutWidget11);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        ClientViewHistoryCountErrorLabel = new QLabel(layoutWidget11);
        ClientViewHistoryCountErrorLabel->setObjectName("ClientViewHistoryCountErrorLabel");
        ClientViewHistoryCountErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_13->addWidget(ClientViewHistoryCountErrorLabel);

        lE_ClientViewHistoryCount = new QLineEdit(layoutWidget11);
        lE_ClientViewHistoryCount->setObjectName("lE_ClientViewHistoryCount");
        lE_ClientViewHistoryCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_13->addWidget(lE_ClientViewHistoryCount);

        stackedWidget->addWidget(ViewMyHistory);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 801, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pBAddAccoutBack, &QPushButton::clicked, NewUserPassWord, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAddAccoutBack, &QPushButton::clicked, NewUserUserName, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAddAccoutBack, &QPushButton::clicked, NewUserFullName, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAddAccoutBack, &QPushButton::clicked, NewUserEmail, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAddAccoutBack, &QPushButton::clicked, NewUserAge, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAddAccoutBack, &QPushButton::clicked, NewUserBalance, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBClear, &QPushButton::clicked, lEPassword, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBClear, &QPushButton::clicked, lEUserName, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAdminViewTransactionBack, &QPushButton::clicked, lE_AdminViewHistoryAccountNumber, qOverload<>(&QLineEdit::clear));
        QObject::connect(pBAdminViewTransactionBack, &QPushButton::clicked, lE_AdminViewHistoryCount, qOverload<>(&QLineEdit::clear));
        QObject::connect(pB_ClientUpdateAccountBack, &QPushButton::clicked, UpdateAccountFullName, qOverload<>(&QLineEdit::clear));
        QObject::connect(pB_ClientUpdateAccountBack, &QPushButton::clicked, UpdateAccountUserName, qOverload<>(&QLineEdit::clear));
        QObject::connect(pB_ClientUpdateAccountBack, &QPushButton::clicked, UpdateAccountAge, qOverload<>(&QLineEdit::clear));
        QObject::connect(pB_ClientUpdateAccountBack, &QPushButton::clicked, UpdateAccountEmail, qOverload<>(&QLineEdit::clear));
        QObject::connect(pB_ClientUpdateAccountBack, &QPushButton::clicked, UpdateAccountPassword, qOverload<>(&QLineEdit::clear));
        QObject::connect(pb_ViewMyHistoryBack, &QPushButton::clicked, lE_ClientViewHistoryCount, qOverload<>(&QLineEdit::clear));
        QObject::connect(pb_ViewMyHistoryBack, &QPushButton::clicked, ClientTransactionHistoryListWidget, qOverload<>(&QListWidget::clear));

        stackedWidget->setCurrentIndex(7);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IMT Bank System", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome To IMT Bank System", nullptr));
        label_2->setText(QString());
        usernameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        passwordErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pBLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pBClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pBConnect->setText(QCoreApplication::translate("MainWindow", "Connect to Bank Server", nullptr));
        Adminlabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>ADMIN</p></body></html>", nullptr));
        pB_AddAccount->setText(QCoreApplication::translate("MainWindow", "Create Client Account", nullptr));
        pB_AdminGetAccountNumber->setText(QCoreApplication::translate("MainWindow", "Get Client Account Number", nullptr));
        label_4->setText(QString());
        pB_DeleteAccount->setText(QCoreApplication::translate("MainWindow", "Delete Client Account", nullptr));
        pBAdminBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pB_AdminGetAccountBalance->setText(QCoreApplication::translate("MainWindow", "View Client Account Balance", nullptr));
        pB_AdminViewTransactionHistory->setText(QCoreApplication::translate("MainWindow", "View Client Transaction History", nullptr));
        pB_ViewBankDatabase->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        pB_UpdateClientAccount->setText(QCoreApplication::translate("MainWindow", "Update Client Account", nullptr));
        Userlabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Client</p></body></html>", nullptr));
        label_9->setText(QString());
        pB_ClientGetAccountNumber->setText(QCoreApplication::translate("MainWindow", "Get My Account Number", nullptr));
        pB_ClientViewAccountBalance->setText(QCoreApplication::translate("MainWindow", "View My Account Balance", nullptr));
        pB_ViewMyHistory->setText(QCoreApplication::translate("MainWindow", "View My Transaction History", nullptr));
        pB_MakeTransaction->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        pB_ClientBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pB_ClientTransferMoney->setText(QCoreApplication::translate("MainWindow", "Transfer Money", nullptr));
        AddAccountlabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ADD ACCOUNT</p></body></html>", nullptr));
        pBCreateAccount->setText(QCoreApplication::translate("MainWindow", "Create Client Accout", nullptr));
        pBAddAccoutBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_3->setText(QString());
        NewUserFullNameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserUserNameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserPassWordErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserEmailErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserAgeErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserBalanceErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ViewTransaction</p><p align=\"center\">History</p></body></html>", nullptr));
        label_6->setText(QString());
        AdminViewHistoryAccountNumberErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        AdminViewHistoryCountErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pBAdminViewTransactionView->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        pBAdminViewTransactionBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        pB_ViewBankDatabaseBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Update Account", nullptr));
        label_29->setText(QString());
        pB_ClientUpdateAccountBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pB_Update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        UpdateEmailErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">View My Transaction</p><p align=\"center\">History</p></body></html>", nullptr));
        label_11->setText(QString());
        pb_ViewMyHistoryBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pb_ViewMyHistoryView->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        ClientViewHistoryCountErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
