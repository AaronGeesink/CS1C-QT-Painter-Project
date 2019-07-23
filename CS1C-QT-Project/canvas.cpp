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

void canvas::setPositionCoords(int x, int y, int id)
{
	for (Shapes::Shape* shape : shapesData)
	{
		if (shape->getId() == id)
		{
			this->xCoord = x;
			this->yCoord = y;
		}
	}
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

	for (Shapes::Shape* shape : shapesData)
	{
		//shape->draw(shape->getX(), shape->getY());
		shape->draw(0,0);
	}

}

void canvas::on_pushButton_load_clicked()
{
	readFile = true;
}
