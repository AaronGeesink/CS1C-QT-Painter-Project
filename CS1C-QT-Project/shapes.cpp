#include "shapes.h"

using namespace Shapes;

Shape::Shape(QPaintDevice * device, int id, ShapeType shape)
	: qpainter{device}, id{id}, shape{shape}
{
	pen = Qt::SolidLine;
	brush = Qt::NoBrush;
}

QPainter& Shape::getQPainter()
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

	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());
	getQPainter().save();
}

void Shape::drawRectangle(int width, int height)
{
	qpainter.drawRect(QRect(0,0,width,height));
	qpainter.restore();

}

void Line::setPoints(const QPoint & pointBegin, const QPoint & pointEnd)
{
	this->pointBegin = pointBegin;
	this->pointEnd = pointEnd;
}

void Line::draw(const int translateX, const int translateY)
{
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());

	getQPainter().save();
	getQPainter().translate(translateX, translateY);

	getQPainter().drawLine(pointBegin, pointEnd);

	getQPainter().restore();
}

void Polyline::setPoint(const QPoint & point)
{
	points.push_back(point);
}

void Polyline::draw(const int translateX, const int translateY)
{
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());

	getQPainter().save();
	getQPainter().translate(translateX, translateY);

	getQPainter().drawPolyline(points.begin(), points.size());

	getQPainter().restore();
}

void Polygon::setPoint(const QPoint & point)
{
	points.push_back(point);

}

void Polygon::draw(const int translateX, const int translateY)
{
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());

	getQPainter().save();
	getQPainter().translate(translateX, translateY);

	getQPainter().drawPolygon(points.begin(), points.size());

	getQPainter().restore();
}

void Rectangle::setRectangle(const QRect & rect)
{
	this->rect = rect;
}

void Rectangle::draw(const int translateX, const int translateY)
{
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());

	getQPainter().save();
	getQPainter().translate(translateX, translateY);

	getQPainter().drawRect(rect);

	getQPainter().restore();
}

void Ellipse::setEllipse(const QRect & rect)
{
	this->rect = rect;
}

void Ellipse::draw(const int translateX, const int translateY)
{
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());

	getQPainter().save();
	getQPainter().translate(translateX, translateY);

	getQPainter().drawEllipse(rect);

	getQPainter().restore();
}

void Text::setText(const QRect& rect, const QString& text)
{
	this->rect = rect;
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

void Shapes::Text::draw(const int translateX, const int translateY)
{
	getQPainter().setFont(font);
	getQPainter().setPen(getPen());
	getQPainter().setBrush(getBrush());

	getQPainter().save();
	getQPainter().translate(translateX, translateY);

	getQPainter().drawText(rect, alignment, text);

	getQPainter().restore();

}
