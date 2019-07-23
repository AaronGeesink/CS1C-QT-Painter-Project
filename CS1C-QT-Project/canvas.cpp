#include "canvas.h"
#include "ui_canvas.h"
#include "shapesparser.h"
#include <QDebug>

canvas::canvas(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::canvas)
{
	ui->setupUi(this);
	readFile = false;
}

canvas::~canvas()
{
	delete ui;
}

void canvas::setPositionCoords(int x, int y)
{
	qInfo() << x;
	qInfo() << y;

	this->xCoord = x;
	this->yCoord = y;

	qInfo() << x;
	qInfo() << y;
}

void canvas::setShapesData(vector<Shapes::Shape*> shapesData)
{
	this->shapesData = shapesData;
}

void canvas::loadFile()
{
	readFile = true;
}

void canvas::paintEvent(QPaintEvent *)
{
	//if (readFile)
	//{
		ShapesParser parser;
		shapesData = parser.readShapesFile(this);
		readFile = false;
	//}

	for (int i = 0; i < shapesData.size(); i++)
	{
		shapesData[i]->draw(0,0);
	}

}

void canvas::on_pushButton_load_clicked()
{
	readFile = true;
}
