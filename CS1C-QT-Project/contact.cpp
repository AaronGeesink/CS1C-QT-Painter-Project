#include "contact.h"
#include "ui_contact.h"

contact::contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contact)
{
    ui->setupUi(this);
	ui->label->setPixmap(QPixmap(":/El Rainmakers logo (qt resize2).png"));
}

contact::~contact()
{
    delete ui;
}
