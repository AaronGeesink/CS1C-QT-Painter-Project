#ifndef SHAPES_H
#define SHAPES_H

//#include <QApplication>
#include <QPainter>
#include "vector.h"

using std::string;
using namespace project;

namespace Shapes {


// Specification for Shape class
//! Shape base class
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
    Shape(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0, ShapeType shape = ShapeType::NoShape);

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

    //! Returns the x coordinate of the shape to the client
    /*!
      \return the x coordinate of the shape
    */

	Shape(const Shape&) = delete;
	Shape& operator=(const Shape&) = delete;

	int getX();

    //! Returns the y coordinate of the shape to the client
    /*!
      \return the y coordinate of the shape
    */
	int getY();

    //! Returns the ID of the shape to the client
    /*!
      \return the ID coordinate of the shape
    */
	int getId();

    //! Translates a shape object to the given coordinate
    /*!
      \param translateX the new x coordinate of the shape object
      \param translateY the new y coordinate of the shape object
    */
	virtual void draw(const int translateX, const int translateY) = 0;

    //! Overloaded less than operator
    /*!
      Compares the IDs of two shape objects
      \return (this->id < other.id);
    */
    bool operator<(const Shape&) const;

    //! Overloaded equality operator
    /*!
      Compares the IDs of two shape objects and returns true if they are equal
      \return (this->id == other.id);
    */
    bool operator==(const Shape&) const;

    bool sortID(Shape * x, Shape * y)
    {
        return (x->id > y->id);
    }

    bool sortPerimeter(Shape * x, Shape * y)
    {
        return (x->perimeter > y->perimeter);
    }

    bool sortArea(Shape * x, Shape * y)
    {
        return (x->area > y->area);
    }

protected:
    //! Returns a pointer to the QPainter object in the shape
    /*!
      \return a pointer to a QPainter object
    */
	QPainter* getQPainter();

private:
    //! A pointer to the QPainter object within each shape
	QPainter* qpainter;
    //! The x coordinate of the shape
	int x {0};
    //! The y coordinate of the shape
	int y {0};
    //! The id of the shape
    int id;
    //! The area of the shape
    double area;
    //! The perimeter of the shape
    double perimeter;
    //! The ShapeType of the shape (i.e. Line, Polyline, Polygon...)
	ShapeType shape;
    //! The QPen data of the shape
	QPen pen;
    //! The QBrush data of the shape
	QBrush brush;
};


// Specification for Line class
//! Line derived class
/*!
  Line class that derives from Shape. Specifies data unique to rendering line objects.
*/
class Line : public Shape
{
public:
    //! Line constructor
    /*!
      Initializes a Line object with default values and Shape data
    */
    Line(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0) : Shape{painter, id, area, perimeter, ShapeType::Line} {}

    //! Line destructor
    /*!
      Deletes a line object
    */
	~Line() override {}

    //! setPoints member function
    /*!
      Sets the points which are used to render a line object
      \param pointBegin the first point of the line
      \param pointEnd the second point of the line
    */
	void setPoints(const QPoint& pointBegin, const QPoint& pointEnd);

    //! Translates a line object to the specified coordinate
    /*!
      \param translateX the new x coordinate of the Line object
      \param translateY the new y coordinate of the Line object
    */
	void draw(const int translateX = 0, const int translateY = 0) override;

private:
    //! The start of the line
	QPoint pointBegin;
    //! The end of the line
	QPoint pointEnd;
};


// Specification for Polyline class
//! Polyline derived class
/*!
  Polyline class that derives from Shape. Specifies data unique to rendering Polyline objects.
*/
class Polyline : public Shape
{
public:
    //! Polyline constructor
    /*!
      Initializes a Polyline object with default values and Shape data
    */
    Polyline(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0) : Shape{painter, id, area, perimeter, ShapeType::Polyline} {}

    //! Polyline destructor
    /*!
      Deletes a Polyline object
    */
	~Polyline() override {}

    //! setPoint member function
    /*!
      Sets one point on a Polyline object
      \param point a point on the Polyline object
    */
	void setPoint(const QPoint& point);

    //! Translates a Polyline object to the specified coordinate
    /*!
      \param translateX the new x coordinate of the Polyline
      \param translateY the new y coordinate of the Polyline
    */
	void draw(const int translateX = 0, const int translateY = 0) override;

private:
    //! A vector storing the different points of the Polyline
	vector<QPoint> points;
};

//! Polygon derived class
/*!
  Polygon class that derives from Shape. Specifies data unique to rendering Polygon objects.
*/
class Polygon : public Shape
{
public:
    //! Polygon constructor
    /*!
      Initializes a Polygon object with default values and Shape data
    */
    Polygon(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0) : Shape{painter, id, area, perimeter, ShapeType::Polygon} {}

    //! Polygon destructor
    /*!
      Deletes a Polygon object
    */
	~Polygon() override {}

    //! setPoint member function
    /*!
      Sets one point on a Polygon object
      \param point a point on the Polygon object
    */
	void setPoint(const QPoint& point);

    //! Translates a Polygon object to the specified coordinate
    /*!
      \param translateX the new x coordinate of the Polygon
      \param translateY the new y coordinate of the Polygon
    */
	void draw(const int translateX = 0, const int translateY = 0) override;

private:
	project::vector<QPoint> points;
};


//! Rectangle derived class
/*!
  Rectangle class that derives from Shape. Specifies data unique to rendering Rectangle objects.
*/
class Rectangle : public Shape
{
public:
    //! Rectangle constructor
    /*!
      Initializes a Rectangle object with default values and Shape data
    */
    Rectangle(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0) : Shape{painter, id, area, perimeter, ShapeType::Rectangle} {}

    //! Rectangle destructor
    /*!
      Deletes a Rectangle object
    */
	~Rectangle() override {}

    //! setRectangle member function
    /*!
      Sets the QRect data of a Rectangle object
      \param rect a QRect argument
    */
	void setRectangle(const QRect& rect);

    //! Translates a Rectangle object to the specified coordinate
    /*!
      \param translateX the new x coordinate of the Rectangle
      \param translateY the new y coordinate of the Rectangle
    */
	void draw(const int translateX = 0, const int translateY = 0) override;
private:
    //! The QRect data in the Rectangle object
	QRect rect;
};

//! Ellipse derived class
/*!
  Esllipse class that derives from Shape. Specifies data unique to rendering Ellipse objects.
*/
class Ellipse : public Shape
{
public:
    //! Ellipse constructor
    /*!
      Initializes an Ellipse object with default values and Shape data
    */
    Ellipse(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0) : Shape{painter, id, area, perimeter, ShapeType::Ellipse} {}

    //! Ellipse destructor
    /*!
      Deletes a Ellipse object
    */
	~Ellipse() override {}

    //! setEllipse member function
    /*!
      Sets the QRect data of an Ellipse object
      \param rect a QRect argument
    */
	void setEllipse(const QRect& rect);

    //! Translates a Ellipse object to the specified coordinate
    /*!
      \param translateX the new x coordinate of the Ellipse
      \param translateY the new y coordinate of the Ellipse
    */
	void draw(const int translateX = 0, const int translateY = 0) override;
private:
    //! The QRect data in the Ellipse object
	QRect rect;
};

//! Text derived class
/*!
  Text class that derives from Shape. Specifies data unique to rendering Text objects.
*/
class Text : public Shape
{
public:
    //! Text constructor
    /*!
      Initializes a Text object with default values and Shape data
    */
    Text(QPainter* painter = nullptr, int id = -1, double area = 0, double perimeter = 0) : Shape{painter, id, area, perimeter, ShapeType::Text} {}

    //! Text destructor
    /*!
      Deletes a Text object
    */
	~Text() override {}

    //! setText member function
    /*!
      Sets the data of a Text object
      \param rect a QRect argument
      \param text a QString reference argument
    */
	void setText(const QRect& rect, const QString& text);

    //! setFont member function
    /*!
      Sets the font of a Text object
      \param family the font family of the Text
      \param weight the weight of the Text (i.e. bold, thin, etc...)
      \param style the style of the Text (i.e italicized)
      \param size the size of the text
      \param alignment the alignment of the Text (left, center, right)
    */
	void setFont(const QString& family, QFont::Weight weight, QFont::Style style, int size, Qt::AlignmentFlag alignment);

    //! setFont member function
    /*!
      Sets the font family of a Text object
      \param family new the font family of the Text
    */
	void setFont(const QString& family);

    //! setString member function
    /*!
      Sets text rendered by the Text object
      \param text the new text rendered by the Text class
    */
	void setString(const QString& text);

    //! setRect member function
    /*!
      Sets the area in which Text will be drawn
      \param rect the new rectangle which renders the Text
    */
	void setRect(const QRect& rect);

    //! setWeight member function
    /*!
      Sets the weight of the text
      \param new weight of the Text
    */
	void setWeight(QFont::Weight weight);

    //! setStyle member function
    /*!
      Sets the style of the text
      \param new style of the Text
    */
	void setStyle(QFont::Style style);

    //! setPointSize member function
    /*!
      Sets the size of the text
      \param new size of the Text
    */
	void setPointSize(int size);

    //! setAlignment member function
    /*!
      Sets the alignment of the text
      \param new alignment of the Text
    */
	void setAlignment(Qt::AlignmentFlag alignment);

    //! Translates a Text object to the specified coordinate
    /*!
      \param translateX the new x coordinate of the Text
      \param translateY the new y coordinate of the Text
    */
	void draw(const int translateX = 0, const int translateY = 0) override;

private:
    //! The QFont object of the Text
	QFont font;
    //! The QString of the Text (the string being rendered)
	QString text;
    //! The rectangular area in which the Text is rendered
	QRect rect;
    //! The alignment of the text (left, middle, right)
	Qt::AlignmentFlag alignment;
};

} // end of Shapes namespace

#endif // SHAPES_H
