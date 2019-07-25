#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    loggedInAsAdmin = false;
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
	if (username == "admin" && password == "password")
    {
        loggedInAsAdmin = true;
        hide();
    }
    else
    {
        QMessageBox::warning(this,"Login","Username or Password is incorrect!");
        loggedInAsAdmin = false;
    }
}

bool login::getLoggedInAsAdmin() const
{
    return loggedInAsAdmin;
}

void login::setLoggedInAsAdmin(bool loggedIn)
{
    loggedInAsAdmin = loggedIn;
}
