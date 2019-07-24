#ifndef SHAPES_H
#define SHAPES_H

//#include <QApplication>
#include <QPainter>
#include "vector.h"

using std::string;
using namespace project;

namespace Shapes {


// Specification for Shape class
//! shape base class
/*!
  Shape abstract base class for drawing QPainter shapes
*/
class Shape
{
public:
    //! ShapeType enum
    /*! Enum to assign numerical values to shape names */
	enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    //! shape constructor
    /*!
      Initializes a shape object with default values and a pointer to a QPainter object
    */
	Shape(QPainter* painter = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);

    //! shape destructor
    /*!
      Deletes a shape object
    */
	virtual ~Shape() { }

    //! ShapeType member function
    /*!
      Member function to return the ShapeType of a shape object
      \return a ShapeType enum
    */
	ShapeType getShape() const;

    //! getPen member function
    /*!
      Obtains the QPen object within the shape
      \return a QPen object reference
    */
	const QPen& getPen() const;

    //! getBrush member function
    /*!
      Obtains the QBrush object within the shape
      \return a QBrush object reference
    */
	const QBrush& getBrush() const;

    //! Sets the ShapeType of a shape object to a user-specified value
    /*!
      \param shape a ShapeType enum argument
    */
	void setShape(ShapeType shape);

    //! Sets the data of the QPen object within the shape
    /*!
      \param color the color of the pen
      \param width the width of the pen
      \param style the PenStyle of the pen
      \param cap the CapStyle of the pen
      \param join the JoinStyle of the pen
    */
	void setPen (Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);

    //! Sets the color of the QPen object within the shape
    /*!
      \param color the color of the pen
    */
	void setPenColor(Qt::GlobalColor color);

    //! Sets the width of the QPen object within the shape
    /*!
      \param width the width of the QPen
    */
	void setPenWidth(int width);

    //! Sets the PenStyle of the QPen object within the shape
    /*!
      \param width the width of the QPen
    */
	void setPenStyle(Qt::PenStyle style);

    //! Sets the CapStyle of the QPen object within the shape
    /*!
      \param cap the CapStyle of the QPen
    */
	void setPenCapStyle(Qt::PenCapStyle cap);

    //! Sets the JoinStyle of the QPen object within the shape
    /*!
      \param join the JoinStyle of the QPen
    */
	void setPenJoinStyle(Qt::PenJoinStyle join);

    //! Sets the data of the QBrush object within the shape
    /*!
      \param color the color of the QBrush
      \param style the style of the QBrush
    */
	void setBrush(Qt::GlobalColor color, Qt::BrushStyle style);

    //! Sets the color of the QBrush object within the shape
    /*!
      \param color the color of the QBrush
    */
	void setBrushColor(Qt::GlobalColor color);

    //! Sets the style of the QBrush object within the shape
    /*!
      \param style the BrushStyle of the QBrush
    */
	void setBrushStyle(Qt::BrushStyle style);

    //! Resets the style of the QPainter object to its default style
	void defaultStyle();

    //! Draws a rectangle with the specified dimensions
    /*!
      \param width the width of the rectangle
      \param height the height of the rectangle
    */
	void drawRectangle(int width, int height);

    //! Renders the ID of a Shape
	void drawID();

    //! Sets the X and Y coordinates of the rendered shape object
    /*!
      \param x the x coordinate of the shape on the canvas
      \param y the y coordinate of the shape on the canvas
    */
	void setXY(int x, int y);

    //! Sets the X and Y coordinates of the rendered shape object
    /*!
      \return x the x coordinate of the shape
    */
	int getX();
	int getY();
	int getId();

	virtual void draw(const int translateX, const int translateY) = 0;
    bool operator<(const Shape&) const;
    bool operator==(const Shape&) const;

protected:
	QPainter* getQPainter();

private:
	QPainter* qpainter;

	int x {0};
	int y {0};
    int id;
    double area;
    double perimeter;
	ShapeType shape;
	QPen pen;
	QBrush brush;
};


// Specification for Line class
class Line : public Shape
{
public:
	Line(QPainter* painter = nullptr, int id = -1) : Shape{painter, id, ShapeType::Line} {}
	~Line() override {}

	void setPoints(const QPoint& pointBegin, const QPoint& pointEnd);

	void draw(const int translateX = 0, const int translateY = 0) override;

private:
	QPoint pointBegin;
	QPoint pointEnd;
};


// Specification for Polyline class
class Polyline : public Shape
{
public:
	Polyline(QPainter* painter = nullptr, int id = -1) : Shape{painter, id, ShapeType::Polyline} {}
	~Polyline() override {}

	void setPoint(const QPoint& point);

	void draw(const int translateX = 0, const int translateY = 0) override;

private:
	vector<QPoint> points;
};


class Polygon : public Shape
{
public:
	Polygon(QPainter* painter = nullptr, int id = -1) : Shape{painter, id, ShapeType::Polygon} {}
	~Polygon() override {}

	void setPoint(const QPoint& point);

	void draw(const int translateX = 0, const int translateY = 0) override;

private:
	project::vector<QPoint> points;
};

class Rectangle : public Shape
{
public:
	Rectangle(QPainter* painter = nullptr, int id = -1) : Shape{painter, id, ShapeType::Rectangle} {}
	~Rectangle() override {}

	void setRectangle(const QRect& rect);

	void draw(const int translateX = 0, const int translateY = 0) override;
private:
	QRect rect;
};

class Ellipse : public Shape
{
public:
	Ellipse(QPainter* painter = nullptr, int id = -1) : Shape{painter, id, ShapeType::Ellipse} {}
	~Ellipse() override {}

	void setEllipse(const QRect& rect);

	void draw(const int translateX = 0, const int translateY = 0) override;
private:
	QRect rect;
};

class Text : public Shape
{
public:
	Text(QPainter* painter = nullptr, int id = -1) : Shape{painter, id, ShapeType::Text} {}
	~Text() override {}

	void setText(const QRect& rect, const QString& text);
	void setFont(const QString& family, QFont::Weight weight, QFont::Style style, int size, Qt::AlignmentFlag alignment);

	void setFont(const QString& family);
	void setString(const QString& text);
	void setRect(const QRect& rect);
	void setWeight(QFont::Weight weight);
	void setStyle(QFont::Style style);
	void setPointSize(int size);
	void setAlignment(Qt::AlignmentFlag alignment);

	void draw(const int translateX = 0, const int translateY = 0) override;

private:
	QFont font;
	QString text;
	QRect rect;
	Qt::AlignmentFlag alignment;
};

} // end of Shapes namespace

#endif // SHAPES_H
