#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes.h"
#include "canvas.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    contact = new class contact(this);
    login = new class login(this);

	canvas = ui->widget;

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
		int id = ui->lineEdit_id->text().toInt();

		if (xCoord < 0 || yCoord < 0)
		{
			QMessageBox::warning(this,"Coordinate Error","Cannot set to negative coordinates");
			return;
		}

		canvas->setPositionCoords(xCoord, yCoord, id);
    }
    else
    {
        login-> show();
    }
}

void MainWindow::on_pushButton_load_clicked()
{
	canvas->loadFile();
}

void MainWindow::on_pushButton_save_clicked()
{
	if(login->getLoggedInAsAdmin())
		canvas->saveFile();
	else
	{
		login-> show();
	}
}
