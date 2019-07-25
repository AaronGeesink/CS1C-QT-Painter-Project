#include "canvas.h"
#include "ui_canvas.h"
#include "shapesparser.h"
#include <QDebug>
#include <QTime>

canvas::canvas(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::canvas)
{
	ui->setupUi(this);
	readFile = false;
	render = false;
}

canvas::~canvas()
{
	delete ui;
}

void canvas::setPositionCoords(int x, int y, int id)
{
	//render = false;
	for (int i = 0; i < shapesData.size(); i++)
	{
		if (shapesData[i]->id == id)
		{
			shapesData[i]->setXY(x,y);
		}
	}
	ShapesParser parser;
	parser.writeShapesFile(shapesData);
	shapesData = buffer;
	update();
	//render = true;
}

void canvas::setShapesData(vector<Shapes::Shape*> shapesData)
{
	this->shapesData = shapesData;
}

void canvas::loadFile()
{
	render = !render;
	readFile = !readFile;
	update();
	buffer = shapesData;
}

void canvas::saveFile()
{
	ShapesParser parser;
	parser.writeShapesFile(shapesData);
}

void canvas::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	QPainter* painterPtr = &painter;

	ShapesParser parser;
	shapesData = parser.readShapesFile(painterPtr);
	readFile = false;

	if (render)
	{
		for (Shapes::Shape* shape : shapesData)
		{
			shape->draw(shape->getX(), shape->getY());
		}
	}
}

