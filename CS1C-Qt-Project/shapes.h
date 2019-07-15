#ifndef SHAPES_H
#define SHAPES_H

//#include <QApplication>
#include <QPainter>
using namespace Qt;

namespace Shapes {

// Specification for Shape class
class Shape
{
public:
	enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

	Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);
	virtual ~Shape() { }

	ShapeType getShape() const;
	const QPen& getPen() const;
	const QBrush& getBrush() const;

	void setShape(ShapeType shape);
	void setPen (GlobalColor, int width, PenStyle, PenCapStyle, PenJoinStyle);
	void setPen(GlobalColor, BrushStyle);

	void defaultStyle();
	void drawRectangle(int width, int height);

	virtual void draw(const int translateX, const int translateY) = 0;

protected:
	QPainter& getQPainter();

private:
	QPainter qpainter;

	int id;
	ShapeType shape;
	QPen pen;
	QBrush brush;
};


// Specification for Line class
class Line : public Shape
{
public:
	Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Line} {}
	~Line() override {}

	void setPoints(const QPoint& pointBegin, const QPoint& pointEnd);

	void draw(const int translateX = 0, const int translateY = 0) override;
};


// Specification for Polyline class
class Polyline : public Shape
{
public:
	Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
	~Polyline() override {}

	void setPoint(const QPoint& point);

	void draw(const int translateX = 0, const int translateY = 0) override;
};



class Polygon : public Shape
{
public:
	Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
	~Polygon() override {}

	void setPoint(const QPoint& point);

	void draw(const int translateX = 0, const int translateY = 0) override;
};

} // end of Shapes namespace

#endif // SHAPES_H
