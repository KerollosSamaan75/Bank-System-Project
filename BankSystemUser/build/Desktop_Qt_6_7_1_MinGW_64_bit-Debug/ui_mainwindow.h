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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QCheckBox *showPasswordCheckBox;
    QPushButton *pBConnect;
    QWidget *Admin;
    QLabel *Adminlabel;
    QPushButton *pB_AddAccount;
    QPushButton *pB_AdminGetAccountNumber;
    QLabel *label_4;
    QPushButton *pB_DeleteAccount;
    QPushButton *pBAdminLogout;
    QPushButton *pB_AdminGetAccountBalance;
    QPushButton *pB_AdminViewTransactionHistory;
    QPushButton *pB_ViewBankDatabase;
    QPushButton *pB_UpdateClientAccount;
    QPushButton *pB_AdminConnectAgain;
    QWidget *Client;
    QLabel *Userlabel;
    QLabel *label_9;
    QPushButton *pB_ClientGetAccountNumber;
    QPushButton *pB_ClientViewAccountBalance;
    QPushButton *pB_ViewMyHistory;
    QPushButton *pB_MakeTransaction;
    QPushButton *pBClientLogout;
    QPushButton *pB_ClientTransferMoney;
    QPushButton *pB_ClientConnectAgain;
    QWidget *AddAccount;
    QLabel *AddAccountlabel;
    QPushButton *pBCreateAccount;
    QPushButton *pBAddAccoutBack;
    QLabel *label_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QLabel *NewUserFullNameErrorLabel;
    QLineEdit *NewUserFullName;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_6;
    QLabel *NewUserUserNameErrorLabel;
    QLineEdit *NewUserUserName;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_7;
    QLabel *NewUserPassWordErrorLabel;
    QLineEdit *NewUserPassWord;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_9;
    QLabel *NewUserAgeErrorLabel;
    QLineEdit *NewUserAge;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_10;
    QLabel *NewUserBalanceErrorLabel;
    QLineEdit *NewUserBalance;
    QWidget *layoutWidget8;
    QVBoxLayout *verticalLayout_8;
    QLabel *NewUserEmailErrorLabel;
    QLineEdit *NewUserEmail;
    QPushButton *pB_AddAccountConnectAgain;
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
    QPushButton *pB_ViewTransactionHistoryConnectAgain;
    QTableView *AdTransactionHistoryTableView;
    QWidget *ViewBankDatabase;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pB_ViewBankDatabaseBack;
    QPushButton *pB_ViewBankDataBaseConnectAgain;
    QTableView *BankDataBaseTableView;
    QWidget *UpdateClientAccount;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *pB_ClientUpdateAccountBack;
    QPushButton *pB_Update;
    QWidget *layoutWidget9;
    QVBoxLayout *verticalLayout_37;
    QLabel *UpdateEmailErrorLabel;
    QLineEdit *UpdateAccountEmail;
    QPushButton *pB_UpdateAccountConnectAgain;
    QWidget *layoutWidget10;
    QVBoxLayout *verticalLayout;
    QLabel *UpdateFullNameErrorLabel;
    QLineEdit *UpdateAccountFullName;
    QWidget *layoutWidget11;
    QVBoxLayout *verticalLayout_14;
    QLabel *UpdateUserNameErrorLabel;
    QLineEdit *UpdateAccountUserName;
    QWidget *layoutWidget12;
    QVBoxLayout *verticalLayout_15;
    QLabel *UpdateAgeErrorLabel;
    QLineEdit *UpdateAccountAge;
    QWidget *layoutWidget13;
    QVBoxLayout *verticalLayout_18;
    QLabel *UpdatePasswordErrorLabel;
    QLineEdit *UpdateAccountPassword;
    QWidget *ViewMyHistory;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pb_ViewMyHistoryBack;
    QPushButton *pb_ViewMyHistoryView;
    QWidget *layoutWidget14;
    QVBoxLayout *verticalLayout_13;
    QLabel *ClientViewHistoryCountErrorLabel;
    QLineEdit *lE_ClientViewHistoryCount;
    QPushButton *pB_ViewClientTransactionHistoryConnectAgain;
    QTableView *ClientTransactionHistoryTableView;
    QWidget *layoutWidget15;
    QHBoxLayout *horizontalLayout;
    QWidget *layoutWidget16;
    QHBoxLayout *horizontalLayout_2;
    QWidget *layoutWidget17;
    QVBoxLayout *verticalLayout_16;
    QWidget *layoutWidget18;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget19;
    QVBoxLayout *verticalLayout_17;
    QWidget *layoutWidget20;
    QHBoxLayout *horizontalLayout_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(798, 609);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/K.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 561));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Login = new QWidget();
        Login->setObjectName("Login");
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 791, 181));
        label->setStyleSheet(QString::fromUtf8("font: 700 40pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 110, 421, 441));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_2->setScaledContents(true);
        frame = new QFrame(Login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(429, 180, 371, 431));
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
        usernameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(usernameErrorLabel);

        lEUserName = new QLineEdit(layoutWidget);
        lEUserName->setObjectName("lEUserName");
        lEUserName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_2->addWidget(lEUserName);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 117, 311, 78));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        passwordErrorLabel = new QLabel(layoutWidget1);
        passwordErrorLabel->setObjectName("passwordErrorLabel");
        passwordErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(passwordErrorLabel);

        lEPassword = new QLineEdit(layoutWidget1);
        lEPassword->setObjectName("lEPassword");
        lEPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_3->addWidget(lEPassword);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 223, 311, 124));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pBLogin = new QPushButton(layoutWidget2);
        pBLogin->setObjectName("pBLogin");
        pBLogin->setCursor(QCursor(Qt::PointingHandCursor));
        pBLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));

        verticalLayout_4->addWidget(pBLogin);

        pBClear = new QPushButton(layoutWidget2);
        pBClear->setObjectName("pBClear");
        pBClear->setCursor(QCursor(Qt::PointingHandCursor));
        pBClear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));

        verticalLayout_4->addWidget(pBClear);

        showPasswordCheckBox = new QCheckBox(frame);
        showPasswordCheckBox->setObjectName("showPasswordCheckBox");
        showPasswordCheckBox->setGeometry(QRect(10, 190, 111, 22));
        showPasswordCheckBox->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        pBConnect = new QPushButton(Login);
        pBConnect->setObjectName("pBConnect");
        pBConnect->setGeometry(QRect(70, 430, 271, 71));
        pBConnect->setCursor(QCursor(Qt::PointingHandCursor));
        pBConnect->setMouseTracking(true);
        pBConnect->setTabletTracking(true);
        pBConnect->setFocusPolicy(Qt::ClickFocus);
        pBConnect->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        stackedWidget->addWidget(Login);
        Admin = new QWidget();
        Admin->setObjectName("Admin");
        Adminlabel = new QLabel(Admin);
        Adminlabel->setObjectName("Adminlabel");
        Adminlabel->setGeometry(QRect(20, 30, 501, 101));
        Adminlabel->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        pB_AddAccount = new QPushButton(Admin);
        pB_AddAccount->setObjectName("pB_AddAccount");
        pB_AddAccount->setGeometry(QRect(20, 180, 351, 81));
        pB_AddAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pB_AddAccount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_AdminGetAccountNumber = new QPushButton(Admin);
        pB_AdminGetAccountNumber->setObjectName("pB_AdminGetAccountNumber");
        pB_AdminGetAccountNumber->setGeometry(QRect(400, 340, 351, 81));
        pB_AdminGetAccountNumber->setCursor(QCursor(Qt::PointingHandCursor));
        pB_AdminGetAccountNumber->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        label_4 = new QLabel(Admin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, -30, 251, 231));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_4->setScaledContents(true);
        pB_DeleteAccount = new QPushButton(Admin);
        pB_DeleteAccount->setObjectName("pB_DeleteAccount");
        pB_DeleteAccount->setGeometry(QRect(20, 260, 351, 81));
        pB_DeleteAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pB_DeleteAccount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pBAdminLogout = new QPushButton(Admin);
        pBAdminLogout->setObjectName("pBAdminLogout");
        pBAdminLogout->setGeometry(QRect(20, 480, 151, 71));
        pBAdminLogout->setCursor(QCursor(Qt::PointingHandCursor));
        pBAdminLogout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_AdminGetAccountBalance = new QPushButton(Admin);
        pB_AdminGetAccountBalance->setObjectName("pB_AdminGetAccountBalance");
        pB_AdminGetAccountBalance->setGeometry(QRect(400, 180, 351, 81));
        pB_AdminGetAccountBalance->setCursor(QCursor(Qt::PointingHandCursor));
        pB_AdminGetAccountBalance->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_AdminViewTransactionHistory = new QPushButton(Admin);
        pB_AdminViewTransactionHistory->setObjectName("pB_AdminViewTransactionHistory");
        pB_AdminViewTransactionHistory->setGeometry(QRect(400, 260, 351, 81));
        pB_AdminViewTransactionHistory->setCursor(QCursor(Qt::PointingHandCursor));
        pB_AdminViewTransactionHistory->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ViewBankDatabase = new QPushButton(Admin);
        pB_ViewBankDatabase->setObjectName("pB_ViewBankDatabase");
        pB_ViewBankDatabase->setGeometry(QRect(20, 340, 351, 81));
        pB_ViewBankDatabase->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ViewBankDatabase->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_UpdateClientAccount = new QPushButton(Admin);
        pB_UpdateClientAccount->setObjectName("pB_UpdateClientAccount");
        pB_UpdateClientAccount->setGeometry(QRect(200, 430, 351, 81));
        pB_UpdateClientAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pB_UpdateClientAccount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_AdminConnectAgain = new QPushButton(Admin);
        pB_AdminConnectAgain->setObjectName("pB_AdminConnectAgain");
        pB_AdminConnectAgain->setGeometry(QRect(0, 0, 231, 71));
        pB_AdminConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_AdminConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        stackedWidget->addWidget(Admin);
        Client = new QWidget();
        Client->setObjectName("Client");
        Userlabel = new QLabel(Client);
        Userlabel->setObjectName("Userlabel");
        Userlabel->setGeometry(QRect(20, 20, 491, 141));
        Userlabel->setStyleSheet(QString::fromUtf8("font: 700 40pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(Client);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(520, 0, 251, 221));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_9->setScaledContents(true);
        pB_ClientGetAccountNumber = new QPushButton(Client);
        pB_ClientGetAccountNumber->setObjectName("pB_ClientGetAccountNumber");
        pB_ClientGetAccountNumber->setGeometry(QRect(40, 230, 331, 81));
        pB_ClientGetAccountNumber->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ClientGetAccountNumber->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ClientViewAccountBalance = new QPushButton(Client);
        pB_ClientViewAccountBalance->setObjectName("pB_ClientViewAccountBalance");
        pB_ClientViewAccountBalance->setGeometry(QRect(230, 410, 331, 81));
        pB_ClientViewAccountBalance->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ClientViewAccountBalance->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ViewMyHistory = new QPushButton(Client);
        pB_ViewMyHistory->setObjectName("pB_ViewMyHistory");
        pB_ViewMyHistory->setGeometry(QRect(420, 230, 331, 81));
        pB_ViewMyHistory->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ViewMyHistory->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_MakeTransaction = new QPushButton(Client);
        pB_MakeTransaction->setObjectName("pB_MakeTransaction");
        pB_MakeTransaction->setGeometry(QRect(40, 320, 331, 81));
        pB_MakeTransaction->setCursor(QCursor(Qt::PointingHandCursor));
        pB_MakeTransaction->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pBClientLogout = new QPushButton(Client);
        pBClientLogout->setObjectName("pBClientLogout");
        pBClientLogout->setGeometry(QRect(40, 480, 121, 71));
        pBClientLogout->setCursor(QCursor(Qt::PointingHandCursor));
        pBClientLogout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ClientTransferMoney = new QPushButton(Client);
        pB_ClientTransferMoney->setObjectName("pB_ClientTransferMoney");
        pB_ClientTransferMoney->setGeometry(QRect(420, 320, 331, 81));
        pB_ClientTransferMoney->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ClientTransferMoney->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ClientConnectAgain = new QPushButton(Client);
        pB_ClientConnectAgain->setObjectName("pB_ClientConnectAgain");
        pB_ClientConnectAgain->setGeometry(QRect(0, 0, 191, 71));
        pB_ClientConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ClientConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        stackedWidget->addWidget(Client);
        AddAccount = new QWidget();
        AddAccount->setObjectName("AddAccount");
        AddAccountlabel = new QLabel(AddAccount);
        AddAccountlabel->setObjectName("AddAccountlabel");
        AddAccountlabel->setGeometry(QRect(40, 10, 341, 141));
        AddAccountlabel->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        pBCreateAccount = new QPushButton(AddAccount);
        pBCreateAccount->setObjectName("pBCreateAccount");
        pBCreateAccount->setGeometry(QRect(470, 470, 241, 71));
        pBCreateAccount->setCursor(QCursor(Qt::PointingHandCursor));
        pBCreateAccount->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pBAddAccoutBack = new QPushButton(AddAccount);
        pBAddAccoutBack->setObjectName("pBAddAccoutBack");
        pBAddAccoutBack->setGeometry(QRect(30, 470, 141, 71));
        pBAddAccoutBack->setCursor(QCursor(Qt::PointingHandCursor));
        pBAddAccoutBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        label_3 = new QLabel(AddAccount);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(520, 10, 241, 171));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_3->setScaledContents(true);
        layoutWidget3 = new QWidget(AddAccount);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(20, 170, 361, 81));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        NewUserFullNameErrorLabel = new QLabel(layoutWidget3);
        NewUserFullNameErrorLabel->setObjectName("NewUserFullNameErrorLabel");
        NewUserFullNameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_5->addWidget(NewUserFullNameErrorLabel);

        NewUserFullName = new QLineEdit(layoutWidget3);
        NewUserFullName->setObjectName("NewUserFullName");
        NewUserFullName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_5->addWidget(NewUserFullName);

        layoutWidget4 = new QWidget(AddAccount);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(20, 270, 361, 78));
        verticalLayout_6 = new QVBoxLayout(layoutWidget4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        NewUserUserNameErrorLabel = new QLabel(layoutWidget4);
        NewUserUserNameErrorLabel->setObjectName("NewUserUserNameErrorLabel");
        NewUserUserNameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_6->addWidget(NewUserUserNameErrorLabel);

        NewUserUserName = new QLineEdit(layoutWidget4);
        NewUserUserName->setObjectName("NewUserUserName");
        NewUserUserName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_6->addWidget(NewUserUserName);

        layoutWidget5 = new QWidget(AddAccount);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(20, 360, 361, 78));
        verticalLayout_7 = new QVBoxLayout(layoutWidget5);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        NewUserPassWordErrorLabel = new QLabel(layoutWidget5);
        NewUserPassWordErrorLabel->setObjectName("NewUserPassWordErrorLabel");
        NewUserPassWordErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_7->addWidget(NewUserPassWordErrorLabel);

        NewUserPassWord = new QLineEdit(layoutWidget5);
        NewUserPassWord->setObjectName("NewUserPassWord");
        NewUserPassWord->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_7->addWidget(NewUserPassWord);

        layoutWidget6 = new QWidget(AddAccount);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(410, 270, 351, 78));
        verticalLayout_9 = new QVBoxLayout(layoutWidget6);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        NewUserAgeErrorLabel = new QLabel(layoutWidget6);
        NewUserAgeErrorLabel->setObjectName("NewUserAgeErrorLabel");
        NewUserAgeErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(NewUserAgeErrorLabel);

        NewUserAge = new QLineEdit(layoutWidget6);
        NewUserAge->setObjectName("NewUserAge");
        NewUserAge->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(NewUserAge);

        layoutWidget7 = new QWidget(AddAccount);
        layoutWidget7->setObjectName("layoutWidget7");
        layoutWidget7->setGeometry(QRect(412, 360, 351, 78));
        verticalLayout_10 = new QVBoxLayout(layoutWidget7);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        NewUserBalanceErrorLabel = new QLabel(layoutWidget7);
        NewUserBalanceErrorLabel->setObjectName("NewUserBalanceErrorLabel");
        NewUserBalanceErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_10->addWidget(NewUserBalanceErrorLabel);

        NewUserBalance = new QLineEdit(layoutWidget7);
        NewUserBalance->setObjectName("NewUserBalance");
        NewUserBalance->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_10->addWidget(NewUserBalance);

        layoutWidget8 = new QWidget(AddAccount);
        layoutWidget8->setObjectName("layoutWidget8");
        layoutWidget8->setGeometry(QRect(411, 170, 351, 78));
        verticalLayout_8 = new QVBoxLayout(layoutWidget8);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        NewUserEmailErrorLabel = new QLabel(layoutWidget8);
        NewUserEmailErrorLabel->setObjectName("NewUserEmailErrorLabel");
        NewUserEmailErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_8->addWidget(NewUserEmailErrorLabel);

        NewUserEmail = new QLineEdit(layoutWidget8);
        NewUserEmail->setObjectName("NewUserEmail");
        NewUserEmail->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_8->addWidget(NewUserEmail);

        pB_AddAccountConnectAgain = new QPushButton(AddAccount);
        pB_AddAccountConnectAgain->setObjectName("pB_AddAccountConnectAgain");
        pB_AddAccountConnectAgain->setGeometry(QRect(0, 0, 181, 71));
        pB_AddAccountConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_AddAccountConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        stackedWidget->addWidget(AddAccount);
        AdminViewTransactionHistory = new QWidget();
        AdminViewTransactionHistory->setObjectName("AdminViewTransactionHistory");
        label_5 = new QLabel(AdminViewTransactionHistory);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 50, 361, 141));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(AdminViewTransactionHistory);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(510, 10, 221, 181));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_6->setScaledContents(true);
        layoutWidget_2 = new QWidget(AdminViewTransactionHistory);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(40, 240, 361, 78));
        verticalLayout_11 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        AdminViewHistoryAccountNumberErrorLabel = new QLabel(layoutWidget_2);
        AdminViewHistoryAccountNumberErrorLabel->setObjectName("AdminViewHistoryAccountNumberErrorLabel");
        AdminViewHistoryAccountNumberErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_11->addWidget(AdminViewHistoryAccountNumberErrorLabel);

        lE_AdminViewHistoryAccountNumber = new QLineEdit(layoutWidget_2);
        lE_AdminViewHistoryAccountNumber->setObjectName("lE_AdminViewHistoryAccountNumber");
        lE_AdminViewHistoryAccountNumber->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_11->addWidget(lE_AdminViewHistoryAccountNumber);

        layoutWidget_3 = new QWidget(AdminViewTransactionHistory);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(40, 320, 361, 78));
        verticalLayout_12 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        AdminViewHistoryCountErrorLabel = new QLabel(layoutWidget_3);
        AdminViewHistoryCountErrorLabel->setObjectName("AdminViewHistoryCountErrorLabel");
        AdminViewHistoryCountErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_12->addWidget(AdminViewHistoryCountErrorLabel);

        lE_AdminViewHistoryCount = new QLineEdit(layoutWidget_3);
        lE_AdminViewHistoryCount->setObjectName("lE_AdminViewHistoryCount");
        lE_AdminViewHistoryCount->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_12->addWidget(lE_AdminViewHistoryCount);

        pBAdminViewTransactionView = new QPushButton(AdminViewTransactionHistory);
        pBAdminViewTransactionView->setObjectName("pBAdminViewTransactionView");
        pBAdminViewTransactionView->setGeometry(QRect(220, 460, 171, 71));
        pBAdminViewTransactionView->setCursor(QCursor(Qt::PointingHandCursor));
        pBAdminViewTransactionView->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pBAdminViewTransactionBack = new QPushButton(AdminViewTransactionHistory);
        pBAdminViewTransactionBack->setObjectName("pBAdminViewTransactionBack");
        pBAdminViewTransactionBack->setGeometry(QRect(40, 460, 161, 71));
        pBAdminViewTransactionBack->setCursor(QCursor(Qt::PointingHandCursor));
        pBAdminViewTransactionBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ViewTransactionHistoryConnectAgain = new QPushButton(AdminViewTransactionHistory);
        pB_ViewTransactionHistoryConnectAgain->setObjectName("pB_ViewTransactionHistoryConnectAgain");
        pB_ViewTransactionHistoryConnectAgain->setGeometry(QRect(10, 0, 201, 71));
        pB_ViewTransactionHistoryConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ViewTransactionHistoryConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        AdTransactionHistoryTableView = new QTableView(AdminViewTransactionHistory);
        AdTransactionHistoryTableView->setObjectName("AdTransactionHistoryTableView");
        AdTransactionHistoryTableView->setGeometry(QRect(445, 160, 311, 371));
        AdTransactionHistoryTableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        stackedWidget->addWidget(AdminViewTransactionHistory);
        ViewBankDatabase = new QWidget();
        ViewBankDatabase->setObjectName("ViewBankDatabase");
        label_7 = new QLabel(ViewBankDatabase);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(540, 10, 221, 161));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(ViewBankDatabase);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 30, 451, 111));
        label_8->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        pB_ViewBankDatabaseBack = new QPushButton(ViewBankDatabase);
        pB_ViewBankDatabaseBack->setObjectName("pB_ViewBankDatabaseBack");
        pB_ViewBankDatabaseBack->setGeometry(QRect(30, 490, 141, 61));
        pB_ViewBankDatabaseBack->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ViewBankDatabaseBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_ViewBankDataBaseConnectAgain = new QPushButton(ViewBankDatabase);
        pB_ViewBankDataBaseConnectAgain->setObjectName("pB_ViewBankDataBaseConnectAgain");
        pB_ViewBankDataBaseConnectAgain->setGeometry(QRect(0, 0, 181, 71));
        pB_ViewBankDataBaseConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ViewBankDataBaseConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        BankDataBaseTableView = new QTableView(ViewBankDatabase);
        BankDataBaseTableView->setObjectName("BankDataBaseTableView");
        BankDataBaseTableView->setGeometry(QRect(15, 170, 761, 311));
        BankDataBaseTableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        BankDataBaseTableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        BankDataBaseTableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        stackedWidget->addWidget(ViewBankDatabase);
        UpdateClientAccount = new QWidget();
        UpdateClientAccount->setObjectName("UpdateClientAccount");
        label_28 = new QLabel(UpdateClientAccount);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(30, 40, 371, 101));
        label_28->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_29 = new QLabel(UpdateClientAccount);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(540, 20, 201, 131));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_29->setScaledContents(true);
        pB_ClientUpdateAccountBack = new QPushButton(UpdateClientAccount);
        pB_ClientUpdateAccountBack->setObjectName("pB_ClientUpdateAccountBack");
        pB_ClientUpdateAccountBack->setGeometry(QRect(30, 480, 121, 71));
        pB_ClientUpdateAccountBack->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ClientUpdateAccountBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pB_Update = new QPushButton(UpdateClientAccount);
        pB_Update->setObjectName("pB_Update");
        pB_Update->setGeometry(QRect(180, 480, 141, 71));
        pB_Update->setCursor(QCursor(Qt::PointingHandCursor));
        pB_Update->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        layoutWidget9 = new QWidget(UpdateClientAccount);
        layoutWidget9->setObjectName("layoutWidget9");
        layoutWidget9->setGeometry(QRect(40, 410, 671, 61));
        verticalLayout_37 = new QVBoxLayout(layoutWidget9);
        verticalLayout_37->setObjectName("verticalLayout_37");
        verticalLayout_37->setContentsMargins(0, 0, 0, 0);
        UpdateEmailErrorLabel = new QLabel(layoutWidget9);
        UpdateEmailErrorLabel->setObjectName("UpdateEmailErrorLabel");
        UpdateEmailErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_37->addWidget(UpdateEmailErrorLabel);

        UpdateAccountEmail = new QLineEdit(layoutWidget9);
        UpdateAccountEmail->setObjectName("UpdateAccountEmail");
        UpdateAccountEmail->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));

        verticalLayout_37->addWidget(UpdateAccountEmail);

        pB_UpdateAccountConnectAgain = new QPushButton(UpdateClientAccount);
        pB_UpdateAccountConnectAgain->setObjectName("pB_UpdateAccountConnectAgain");
        pB_UpdateAccountConnectAgain->setGeometry(QRect(10, 10, 181, 71));
        pB_UpdateAccountConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_UpdateAccountConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        layoutWidget10 = new QWidget(UpdateClientAccount);
        layoutWidget10->setObjectName("layoutWidget10");
        layoutWidget10->setGeometry(QRect(40, 160, 671, 69));
        verticalLayout = new QVBoxLayout(layoutWidget10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        UpdateFullNameErrorLabel = new QLabel(layoutWidget10);
        UpdateFullNameErrorLabel->setObjectName("UpdateFullNameErrorLabel");
        UpdateFullNameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout->addWidget(UpdateFullNameErrorLabel);

        UpdateAccountFullName = new QLineEdit(layoutWidget10);
        UpdateAccountFullName->setObjectName("UpdateAccountFullName");
        UpdateAccountFullName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));

        verticalLayout->addWidget(UpdateAccountFullName);

        layoutWidget11 = new QWidget(UpdateClientAccount);
        layoutWidget11->setObjectName("layoutWidget11");
        layoutWidget11->setGeometry(QRect(40, 230, 671, 61));
        verticalLayout_14 = new QVBoxLayout(layoutWidget11);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        UpdateUserNameErrorLabel = new QLabel(layoutWidget11);
        UpdateUserNameErrorLabel->setObjectName("UpdateUserNameErrorLabel");
        UpdateUserNameErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_14->addWidget(UpdateUserNameErrorLabel);

        UpdateAccountUserName = new QLineEdit(layoutWidget11);
        UpdateAccountUserName->setObjectName("UpdateAccountUserName");
        UpdateAccountUserName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));

        verticalLayout_14->addWidget(UpdateAccountUserName);

        layoutWidget12 = new QWidget(UpdateClientAccount);
        layoutWidget12->setObjectName("layoutWidget12");
        layoutWidget12->setGeometry(QRect(40, 290, 671, 60));
        verticalLayout_15 = new QVBoxLayout(layoutWidget12);
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        UpdateAgeErrorLabel = new QLabel(layoutWidget12);
        UpdateAgeErrorLabel->setObjectName("UpdateAgeErrorLabel");
        UpdateAgeErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_15->addWidget(UpdateAgeErrorLabel);

        UpdateAccountAge = new QLineEdit(layoutWidget12);
        UpdateAccountAge->setObjectName("UpdateAccountAge");
        UpdateAccountAge->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));

        verticalLayout_15->addWidget(UpdateAccountAge);

        layoutWidget13 = new QWidget(UpdateClientAccount);
        layoutWidget13->setObjectName("layoutWidget13");
        layoutWidget13->setGeometry(QRect(40, 350, 671, 60));
        verticalLayout_18 = new QVBoxLayout(layoutWidget13);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        UpdatePasswordErrorLabel = new QLabel(layoutWidget13);
        UpdatePasswordErrorLabel->setObjectName("UpdatePasswordErrorLabel");
        UpdatePasswordErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 10pt \"Segoe UI\";"));

        verticalLayout_18->addWidget(UpdatePasswordErrorLabel);

        UpdateAccountPassword = new QLineEdit(layoutWidget13);
        UpdateAccountPassword->setObjectName("UpdateAccountPassword");
        UpdateAccountPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));

        verticalLayout_18->addWidget(UpdateAccountPassword);

        stackedWidget->addWidget(UpdateClientAccount);
        ViewMyHistory = new QWidget();
        ViewMyHistory->setObjectName("ViewMyHistory");
        label_10 = new QLabel(ViewMyHistory);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 60, 471, 151));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 35pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(ViewMyHistory);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(540, 10, 201, 161));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/K.png")));
        label_11->setScaledContents(true);
        pb_ViewMyHistoryBack = new QPushButton(ViewMyHistory);
        pb_ViewMyHistoryBack->setObjectName("pb_ViewMyHistoryBack");
        pb_ViewMyHistoryBack->setGeometry(QRect(40, 460, 131, 71));
        pb_ViewMyHistoryBack->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ViewMyHistoryBack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        pb_ViewMyHistoryView = new QPushButton(ViewMyHistory);
        pb_ViewMyHistoryView->setObjectName("pb_ViewMyHistoryView");
        pb_ViewMyHistoryView->setGeometry(QRect(210, 460, 141, 71));
        pb_ViewMyHistoryView->setCursor(QCursor(Qt::PointingHandCursor));
        pb_ViewMyHistoryView->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        layoutWidget14 = new QWidget(ViewMyHistory);
        layoutWidget14->setObjectName("layoutWidget14");
        layoutWidget14->setGeometry(QRect(40, 240, 361, 78));
        verticalLayout_13 = new QVBoxLayout(layoutWidget14);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        ClientViewHistoryCountErrorLabel = new QLabel(layoutWidget14);
        ClientViewHistoryCountErrorLabel->setObjectName("ClientViewHistoryCountErrorLabel");
        ClientViewHistoryCountErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));

        verticalLayout_13->addWidget(ClientViewHistoryCountErrorLabel);

        lE_ClientViewHistoryCount = new QLineEdit(layoutWidget14);
        lE_ClientViewHistoryCount->setObjectName("lE_ClientViewHistoryCount");
        lE_ClientViewHistoryCount->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Segoe UI\";"));

        verticalLayout_13->addWidget(lE_ClientViewHistoryCount);

        pB_ViewClientTransactionHistoryConnectAgain = new QPushButton(ViewMyHistory);
        pB_ViewClientTransactionHistoryConnectAgain->setObjectName("pB_ViewClientTransactionHistoryConnectAgain");
        pB_ViewClientTransactionHistoryConnectAgain->setGeometry(QRect(10, 10, 201, 71));
        pB_ViewClientTransactionHistoryConnectAgain->setCursor(QCursor(Qt::PointingHandCursor));
        pB_ViewClientTransactionHistoryConnectAgain->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #008CBA; /* Blue background */\n"
"    font: 700 14pt \"Segoe UI\"; /* Bold font, 14pt size, \"Segoe UI\" */\n"
"    border: 2px solid #008CBA; /* Blue border */\n"
"    color: white; /* Black text */\n"
"    padding: 10px 15px; /* Reduced padding for smaller button size */\n"
"    text-align: center; /* Centered text */\n"
"    text-decoration: none; /* No underline */\n"
"    display: inline-block; /* Inline block */\n"
"    margin: 4px 2px; /* Margin for spacing */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    outline: none; /* Remove default focus outline */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease, box-shadow 0.3s ease; /* Smooth transitions */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #007BB5; /* Slightly darker blue on hover */\n"
"    border-color: #007BB5; /* Slightly darker blue border on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005F73; /* Darker blue when pressed */\n"
""
                        "    border-color: #005F73; /* Darker blue border when pressed */\n"
"    box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5); /* Shadow effect when pressed */\n"
"}\n"
""));
        ClientTransactionHistoryTableView = new QTableView(ViewMyHistory);
        ClientTransactionHistoryTableView->setObjectName("ClientTransactionHistoryTableView");
        ClientTransactionHistoryTableView->setGeometry(QRect(445, 140, 311, 401));
        ClientTransactionHistoryTableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";"));
        stackedWidget->addWidget(ViewMyHistory);
        layoutWidget15 = new QWidget(centralwidget);
        layoutWidget15->setObjectName("layoutWidget15");
        layoutWidget15->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout = new QHBoxLayout(layoutWidget15);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget16 = new QWidget(centralwidget);
        layoutWidget16->setObjectName("layoutWidget16");
        layoutWidget16->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget16);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget17 = new QWidget(centralwidget);
        layoutWidget17->setObjectName("layoutWidget17");
        layoutWidget17->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_16 = new QVBoxLayout(layoutWidget17);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        layoutWidget18 = new QWidget(centralwidget);
        layoutWidget18->setObjectName("layoutWidget18");
        layoutWidget18->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget18);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget19 = new QWidget(centralwidget);
        layoutWidget19->setObjectName("layoutWidget19");
        layoutWidget19->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_17 = new QVBoxLayout(layoutWidget19);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        layoutWidget20 = new QWidget(centralwidget);
        layoutWidget20->setObjectName("layoutWidget20");
        layoutWidget20->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget20);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 798, 21));
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

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "KS Bank", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Welcome To K&amp;S Bank System</p></body></html>", nullptr));
        label_2->setText(QString());
        usernameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        passwordErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pBLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pBClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        showPasswordCheckBox->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        pBConnect->setText(QCoreApplication::translate("MainWindow", "Connect to Bank Server", nullptr));
        Adminlabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ADMIN</p></body></html>", nullptr));
        pB_AddAccount->setText(QCoreApplication::translate("MainWindow", "Create Client Account", nullptr));
        pB_AdminGetAccountNumber->setText(QCoreApplication::translate("MainWindow", "Get Client Account Number", nullptr));
        label_4->setText(QString());
        pB_DeleteAccount->setText(QCoreApplication::translate("MainWindow", "Delete Client Account", nullptr));
        pBAdminLogout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        pB_AdminGetAccountBalance->setText(QCoreApplication::translate("MainWindow", "View Client Account Balance", nullptr));
        pB_AdminViewTransactionHistory->setText(QCoreApplication::translate("MainWindow", "View Client Transaction History", nullptr));
        pB_ViewBankDatabase->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        pB_UpdateClientAccount->setText(QCoreApplication::translate("MainWindow", "Update Client Account", nullptr));
        pB_AdminConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
        Userlabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Client</p></body></html>", nullptr));
        label_9->setText(QString());
        pB_ClientGetAccountNumber->setText(QCoreApplication::translate("MainWindow", "Get My Account Number", nullptr));
        pB_ClientViewAccountBalance->setText(QCoreApplication::translate("MainWindow", "View My Account Balance", nullptr));
        pB_ViewMyHistory->setText(QCoreApplication::translate("MainWindow", "View My Transaction History", nullptr));
        pB_MakeTransaction->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        pBClientLogout->setText(QCoreApplication::translate("MainWindow", "logout", nullptr));
        pB_ClientTransferMoney->setText(QCoreApplication::translate("MainWindow", "Transfer Money", nullptr));
        pB_ClientConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
        AddAccountlabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ADD ACCOUNT</p></body></html>", nullptr));
        pBCreateAccount->setText(QCoreApplication::translate("MainWindow", "Create Client Accout", nullptr));
        pBAddAccoutBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_3->setText(QString());
        NewUserFullNameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserUserNameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserPassWordErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserAgeErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserBalanceErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        NewUserEmailErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pB_AddAccountConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ViewTransaction</p><p align=\"center\">History</p></body></html>", nullptr));
        label_6->setText(QString());
        AdminViewHistoryAccountNumberErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        AdminViewHistoryCountErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pBAdminViewTransactionView->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        pBAdminViewTransactionBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pB_ViewTransactionHistoryConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        pB_ViewBankDatabaseBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pB_ViewBankDataBaseConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Update Account", nullptr));
        label_29->setText(QString());
        pB_ClientUpdateAccountBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pB_Update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        UpdateEmailErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pB_UpdateAccountConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
        UpdateFullNameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        UpdateUserNameErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        UpdateAgeErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        UpdatePasswordErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">View My Transaction</p><p align=\"center\">History</p></body></html>", nullptr));
        label_11->setText(QString());
        pb_ViewMyHistoryBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pb_ViewMyHistoryView->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        ClientViewHistoryCountErrorLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pB_ViewClientTransactionHistoryConnectAgain->setText(QCoreApplication::translate("MainWindow", "Connect again", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
