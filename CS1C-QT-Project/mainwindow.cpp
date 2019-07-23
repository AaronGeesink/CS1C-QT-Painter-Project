#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    contact = new class contact(this);
    login = new class login(this);

    ui->statusBar->showMessage("Logged in as Guest");
    m_timer = new QTimer(this);
    connect (m_timer,&QTimer::timeout,this,&MainWindow::update);
    m_timer->start(100);
	//setBackgroundRole(QPalette::Base);
	//setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete contact;
    delete login;
    delete m_timer;
}

void MainWindow::on_pushButton_contact_clicked()
{
    contact->show();
}

void MainWindow::on_pushButton_login_clicked()
{
    login -> show();
}


void MainWindow::update()
{
    if(login->getLoggedInAsAdmin() == true)
    {
        ui->statusBar->showMessage("Logged in as Admin");
    }
    else
    {
        ui->statusBar->showMessage("Logged in as Guest");
    }
}

void MainWindow::on_pushButton_move_clicked()
{
    if(login->getLoggedInAsAdmin())
    {
        int xCoord = ui->lineEdit_xCoord->text().toInt();
        int yCoord = ui->lineEdit_yCoord->text().toInt();
        canvas->setPositionCoords(xCoord,yCoord);
    }
    else
    {
        login-> show();
    }
}
