#include "canvas.h"
#include "ui_canvas.h"
#include "shapesparser.h"
#include <QDebug>
#include <QTime>
#include <QMessageBox>

canvas::canvas(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::canvas)
{
	ui->setupUi(this);
	render = false;
}

canvas::~canvas()
{
	delete ui;
}

void canvas::setPositionCoords(int x, int y, int id)
{
	for (int i = 0; i < shapesData.size(); i++)
	{
		if (shapesData[i]->id == id)
		{
			shapesData[i]->setXY(x,y);
			error = true;
		}
	}

	if (!error)
	{
		QMessageBox::warning(this,"id Error","Not a valid id");
		error = false;
		return;
	}

	ShapesParser parser;
	parser.writeShapesFile(shapesData);
	shapesData = buffer;
	update();
}

void canvas::setShapesData(vector<Shapes::Shape*> shapesData)
{
	this->shapesData = shapesData;
}

void canvas::loadFile()
{
	render = true;
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

	if (render)
	{
		for (Shapes::Shape* shape : shapesData)
		{
			shape->draw(shape->getX(), shape->getY());
		}
	}
}

