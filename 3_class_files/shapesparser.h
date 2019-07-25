#ifndef SHAPESPARSER_H
#define SHAPESPARSER_H

#include "shapes.h"
#include "canvas.h"
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QFile>

class ShapesParser
{
public:
	ShapesParser();

	// MUST CHANGE FILE PATH IN readShapesFile() TO BE MORE GENERAL
	vector<Shapes::Shape*> readShapesFile(QPainter* painter);
	void writeShapesFile(vector<Shapes::Shape*> shapesData);

	void parseLine(Shapes::Line* pLine, std::ifstream& inFile);
	void parsePolyline(Shapes::Polyline* pPolyline, std::ifstream& inFile);
	void parsePolygon(Shapes::Polygon* pPolygon, std::ifstream& inFile);
	void parseRectangle(Shapes::Rectangle* pRectangle, std::ifstream& inFile);
	void parseEllipse(Shapes::Ellipse* pEllipse, std::ifstream& inFile);
	void parseText(Shapes::Text* pText, std::ifstream& inFile);

	QPoint parsePoint(string& points);
	Qt::GlobalColor parseColor(string& color);
	int parseInt(string& width);
	Qt::PenStyle parsePenStyle(string& penStyle);
	Qt::PenCapStyle parseCap(string& cap);
	Qt::PenJoinStyle parseJoin(string& join);
	Qt::BrushStyle parseBrushStyle(string& brushStyle);
	QRect parseRect(string& rect);

	QString parseString(string& text);
	Qt::AlignmentFlag parseAlignment(string& alignment);
	QString parseFont(string& font);
	QFont::Style parseTextStyle(string& textStyle);
	QFont::Weight parseWeight(string& weight);

	string writeColor(const QColor& color);
	string writePenStyle(Qt::PenStyle penStyle);
	string writeCapStyle(Qt::PenCapStyle cap);
	string writeJoinStyle(Qt::PenJoinStyle join);
	string writeBrushStyle(Qt::BrushStyle brushStyle);

	string writeAlignment(Qt::AlignmentFlag alignment);
	string writeFamily(QString family);
	string writeFontStyle(QFont::Style style);
	string writeFontWeight(int weight);

	void removeSpaces(string& str);
	void delay();

private:

	int id;
	string line;
	QString qLine;
	string setting;
	string value;
	bool error {true};

	vector<Shapes::Shape*> loadedShapes;
};

#endif // SHAPESPARSER_H
