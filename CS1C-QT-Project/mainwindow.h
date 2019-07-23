#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "contact.h"
#include "login.h"
#include "canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void update();

private slots:
    void on_pushButton_contact_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_move_clicked();

private:
    Ui::MainWindow *ui;
	contact* contact;
	login* login;
    QTimer* m_timer;
	canvas* canvas;
};

#endif // MAINWINDOW_H
