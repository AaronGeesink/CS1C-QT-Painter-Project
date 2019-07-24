#include "shapes.h"

using namespace Shapes;

Shape::Shape(QPainter* painter, int id, ShapeType shape)
	: qpainter{painter}, id{id}, shape{shape}
{
	pen = Qt::SolidLine;
	brush = Qt::NoBrush;
}

QPainter* Shape::getQPainter()
{
	return qpainter;
}

Shape::ShapeType Shape::getShape() const
{
	return shape;
}

const QPen & Shape::getPen() const
{
	return pen;
}

const QBrush & Shape::getBrush() const
{
	return brush;
}

void Shape::setShape(ShapeType shape)
{
	this->shape = shape;
}

void Shape::setPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
	pen.setColor(color);
	pen.setWidth(width);
	pen.setStyle(style);
	pen.setCapStyle(cap);
	pen.setJoinStyle(join);
}

void Shape::setPenColor(Qt::GlobalColor color)
{
	pen.setColor(color);
}

void Shape::setPenWidth(int width)
{
	pen.setWidth(width);
}

void Shape::setPenStyle(Qt::PenStyle style)
{
	pen.setStyle(style);
}

void Shape::setPenCapStyle(Qt::PenCapStyle cap)
{
	pen.setCapStyle(cap);
}

void Shape::setPenJoinStyle(Qt::PenJoinStyle join)
{
	pen.setJoinStyle(join);
}

void Shape::setBrush(Qt::GlobalColor color, Qt::BrushStyle style)
{
	brush.setColor(color);
	brush.setStyle(style);
}

void Shape::setBrushColor(Qt::GlobalColor color)
{
	brush.setColor(color);
}

void Shape::setBrushStyle(Qt::BrushStyle style)
{
	brush.setStyle(style);
}

void Shape::defaultStyle()
{
	pen.setColor(Qt::black);
	pen.setWidth(1);
	pen.setStyle(Qt::SolidLine);
	pen.setCapStyle(Qt::SquareCap);
	pen.setJoinStyle(Qt::BevelJoin);
	brush.setStyle(Qt::NoBrush);
	brush.setColor(Qt::black);

	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());
	getQPainter()->save();
}

void Shape::drawRectangle(int width, int height)
{
	getQPainter()->drawRect(QRect(0,0,width,height));
	getQPainter()->restore();

}

void Shape::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Shape::getX()
{
	return x;
}

int Shape::getY()
{
	return y;
}

int Shape::getId()
{
	return id;
}

void Line::setPoints(const QPoint & pointBegin, const QPoint & pointEnd)
{
	this->pointBegin = pointBegin;
	this->pointEnd = pointEnd;
	setXY(pointBegin.x(), pointBegin.y());

	this->pointBegin.setX(pointBegin.x() - getX());
	this->pointBegin.setY(pointBegin.y() - getY());

	this->pointEnd.setX(pointEnd.x() - getX());
	this->pointEnd.setY(pointEnd.y() - getY());
}

void Line::draw(const int translateX, const int translateY)
{
	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());

	getQPainter()->save();
	getQPainter()->translate(translateX, translateY);

	getQPainter()->drawLine(pointBegin, pointEnd);

	getQPainter()->translate(-20,-30);
	QString text = "id: " + QString::number( getId() );
	getQPainter()->drawText(pointBegin, text);

	getQPainter()->restore();
}

void Polyline::setPoint(const QPoint & point)
{
	points.push_back(point);

//	setXY(points.end()->x(), points.end()->y());

//	this->points.end()->setX(points.end()->x() - getX());
//	this->points.end()->setY(points.end()->y() - getX());
}

void Polyline::draw(const int translateX, const int translateY)
{
	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());

	getQPainter()->save();
	getQPainter()->translate(translateX, translateY);

	getQPainter()->drawPolyline(points.begin(), points.size());

	getQPainter()->translate(-20,-30);
	QString text = "id: " + QString::number( getId() );
	getQPainter()->drawText(points[0], text);

	getQPainter()->restore();
}

void Polygon::setPoint(const QPoint & point)
{
	points.push_back(point);

//	setXY(points.end()->x(), points.end()->y());

//	this->points.end()->setX(points.end()->x() - getX());
//	this->points.end()->setY(points.end()->y() - getX());

}

void Polygon::draw(const int translateX, const int translateY)
{
	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());

	getQPainter()->save();
	getQPainter()->translate(translateX, translateY);

	getQPainter()->drawPolygon(points.begin(), points.size());

	getQPainter()->translate(-20,-30);
	QString text = "id: " + QString::number( getId() );
	getQPainter()->drawText(points[0], text);

	getQPainter()->restore();

}

void Rectangle::setRectangle(const QRect & rect)
{
	this->rect = rect;
	setXY(rect.x(),rect.y());
	this->rect.moveTo(0,0);
}

void Rectangle::draw(const int translateX, const int translateY)
{
	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());

	getQPainter()->save();
	getQPainter()->translate(translateX, translateY);

	getQPainter()->drawRect(rect);

	getQPainter()->translate(-20,-30);
	QString text = "id: " + QString::number( getId() );
	getQPainter()->drawText(rect, text);

	getQPainter()->restore();
}

void Ellipse::setEllipse(const QRect & rect)
{
	this->rect = rect;
	setXY(rect.x(),rect.y());
	this->rect.moveTo(0,0);
}

void Ellipse::draw(const int translateX, const int translateY)
{
	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());

	getQPainter()->save();
	getQPainter()->translate(translateX, translateY);

	getQPainter()->drawEllipse(rect);

	getQPainter()->translate(-20,-30);
	QString text = "id: " + QString::number( getId() );
	getQPainter()->drawText(rect, text);

	getQPainter()->restore();
}

void Text::setText(const QRect& rect, const QString& text)
{
	this->rect = rect;
	setXY(rect.x(),rect.y());
	this->rect.moveTo(0,0);

	this->text = text;
}

void Text::setString(const QString& text)
{
	this->text = text;
}

void Text::setFont(const QString& family, QFont::Weight weight, QFont::Style style,  int size, Qt::AlignmentFlag alignment)
{
	font.setFamily(family);
	font.setWeight(weight);
	font.setStyle(style);
	font.setPointSize(size);
	this->alignment = alignment;
}

void Text::setFont(const QString& family)
{
	font.setFamily(family);
}

void Text::setRect(const QRect& rect)
{
	this->rect = rect;
}

void Text::setWeight(QFont::Weight weight)
{
	font.setWeight(weight);
}

void Text::setStyle(QFont::Style style)
{
	font.setStyle(style);
}

void Text::setPointSize(int size)
{
	font.setPointSize(size);
}

void Text::setAlignment(Qt::AlignmentFlag alignment)
{
	this->alignment = alignment;
}


void Shapes::Text::draw(const int translateX, const int translateY)
{
	getQPainter()->setFont(font);
	getQPainter()->setPen(getPen());
	getQPainter()->setBrush(getBrush());

	getQPainter()->save();
	getQPainter()->translate(translateX, translateY);

	getQPainter()->drawText(rect, alignment, text);

	getQPainter()->translate(-20,-30);
	QString text = "id: " + QString::number( getId() );
	getQPainter()->drawText(rect, text);
	getQPainter()->translate(0,0);

	getQPainter()->restore();

}

bool Shapes::Shape::operator<(const Shape & other) const
{
    return this->id < other.id;
}

bool Shapes::Shape::operator==(const Shape & other) const
{
    return this->id == other.id;
}
