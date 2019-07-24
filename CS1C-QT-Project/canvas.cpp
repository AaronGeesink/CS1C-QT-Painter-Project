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
	render = false;
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
			shape->setXY(x,y);
		}
	}
	//repaint();
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
	QPainter painter(this);

	QPainter* painterPtr = &painter;
	if (readFile)
	{
		ShapesParser parser;
		shapesData = parser.readShapesFile(painterPtr);
		readFile = false;
		//update();
	}

	if (render)
	{
		for (Shapes::Shape* shape : shapesData)
		{
			shape->draw(shape->getX(), shape->getY());
			//shape->draw(0,0);
			qInfo() << shape->getId();
		}
	}

	painter.end();
}

void canvas::on_pushButton_clicked()
{
	render = !render;
}
