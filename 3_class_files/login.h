#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool getLoggedInAsAdmin() const;
    void setLoggedInAsAdmin(bool loggedIn);

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::login *ui;
    bool loggedInAsAdmin;
};

#endif // LOGIN_H
