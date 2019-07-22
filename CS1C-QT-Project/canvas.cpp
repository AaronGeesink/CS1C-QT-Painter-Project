#include "canvas.h"
#include "ui_canvas.h"
#include "shapesparser.h"

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

void canvas::paintEvent(QPaintEvent *)
{
	//if (readFile)
	//{
		ShapesParser parser;
		parser.readShapesFile(this);
		readFile = false;
		//this->update();
	//}

//	for (int i = 0; i < shapesData.size(); i++)
//	{
//		shapesData[i]->draw(0,0);
//	}



//	Shapes::Line line(this);

//	line.setPoints(QPoint(20, 90), QPoint( 100, 20));

//	line.setPen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);

//	line.draw();

//	line.defaultStyle();
//	line.drawRectangle(width() - 1, height() - 1);



//	Shapes::Polyline polyline(this);

//	polyline.setPoint(QPoint(460,90));
//	polyline.setPoint(QPoint(470,20));
//	polyline.setPoint(QPoint(530,40));
//	polyline.setPoint(QPoint(540,80));

//	polyline.setPen(Qt::green, 6, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

//	polyline.draw();

//	polyline.defaultStyle();
//	polyline.drawRectangle(width() - 1, height() - 1);

//	Shapes::Polygon polygon(this);

//	polygon.setPoint(QPoint(900,90));
//	polygon.setPoint(QPoint(910,20));
//	polygon.setPoint(QPoint(970,40));
//	polygon.setPoint(QPoint(980,80));

//	polygon.setPen(Qt::cyan, 6, Qt::DashDotDotLine, Qt::FlatCap, Qt::MiterJoin);
//	polygon.setBrush(Qt::yellow, Qt::SolidPattern);

//	polygon.draw();

//	polygon.defaultStyle();
//	polygon.drawRectangle(width() - 1, height() - 1);

//	Shapes::Rectangle rectangle(this);

//	rectangle.setRectangle(QRect(20,200,170,100));

//	rectangle.setPen(Qt::blue, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
//	rectangle.setBrush(Qt::red, Qt::VerPattern);

//	rectangle.draw();

//	rectangle.defaultStyle();
//	rectangle.drawRectangle(width() - 1, height() - 1);

//	Shapes::Ellipse ellipse(this);

//	ellipse.setEllipse(QRect(520,200,170,100));

//	ellipse.setPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
//	ellipse.setBrush(Qt::black, Qt::NoBrush);

//	ellipse.draw();

//	ellipse.defaultStyle();
//	ellipse.drawRectangle(width() - 1, height() - 1);

	Shapes::Text text(this);

	text.setText(QRect(420,300,200,200),"The Rainmakers Class Project");
	text.setFont("Comic Sans MS", QFont::Normal, QFont::StyleNormal, 10, Qt::AlignCenter);

	text.setPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

	text.draw();

}

void canvas::on_pushButton_load_clicked()
{
	readFile = true;
}
