#include "shapesparser.h"

ShapesParser::ShapesParser()
{ }

/*vector<Shapes::Line>&*/
vector<Shapes::Shape*> ShapesParser::readShapesFile(QPainter * painter)
{
	// MUST CHANGE FILE PATH TO BE MORE GENERAL
    string fileName("C:\\Users\\chatm\\Desktop\\CS1C-QT-Project\\CS1C-QT-Project\\shapes.txt");

	std::ifstream inFile;
	inFile.open(fileName.c_str());

	if (inFile.fail())
	{
		// exit if file not found. might use exception handling for this.
		qInfo() << "inFile failed to load.";
		exit(1);
	}


	while(std::getline(inFile, line))
	{
		if (line != "")
		{
			std::istringstream lineStream(line);

			std::getline(lineStream, setting, ' ');
			std::getline(lineStream, value, '\n');

			if (setting == "ShapeId:")
			{
				id = std::stoi(value);

				std::getline(inFile, line);
				std::istringstream lineStream(line);

				std::getline(lineStream, setting, ' ');
				std::getline(lineStream, value, '\n');

				switch (value[0])
				{
					case 'L':
					{
						// construct a line
						Shapes::Line* pLine = new Shapes::Line(painter,id);

						parseLine(pLine, inFile);
						//pLine->draw();

						loadedShapes.push_back(pLine);

						break;
					}
					case 'P':
					{
						if(value[4] == 'l')
						{
							// construct a polyline
							Shapes::Polyline* pPolyline = new Shapes::Polyline(painter,id);

							parsePolyline(pPolyline, inFile);
							//pPolyline->draw();

							loadedShapes.push_back(pPolyline);

							break;
						}
						else if(value[4] == 'g')
						{
							// construct a polygon
							Shapes::Polygon* pPolygon = new Shapes::Polygon(painter,id);

							parsePolygon(pPolygon, inFile);
							//pPolygon->draw();

							loadedShapes.push_back(pPolygon);
						}
						break;
					}
					case 'R':
					{
						// construct a rectangle
						Shapes::Rectangle* pRectangle = new Shapes::Rectangle(painter,id);

						parseRectangle(pRectangle, inFile);
						//pRectangle->draw();

						loadedShapes.push_back(pRectangle);

						break;
					}
					case 'S':
					{
						// construct a square
						Shapes::Rectangle* pRectangle = new Shapes::Rectangle(painter,id);

						parseRectangle(pRectangle, inFile);
						//pRectangle->draw();

						loadedShapes.push_back(pRectangle);

						break;
					}
					case 'E':
					{
						// construct an ellipse
						Shapes::Ellipse* pEllipse = new Shapes::Ellipse(painter,id);

						parseEllipse(pEllipse, inFile);
						//pEllipse->draw();

						loadedShapes.push_back(pEllipse);

						break;
					}
					case 'C':
					{
						// construct a circle
						Shapes::Ellipse* pEllipse = new Shapes::Ellipse(painter,id);

						parseEllipse(pEllipse, inFile);
						//pEllipse->draw();

						loadedShapes.push_back(pEllipse);

						break;
					}
					case 'T':
					{
						// construct text
						Shapes::Text* pText = new Shapes::Text(painter,id);

						parseText(pText, inFile);
						//pText->draw();

						loadedShapes.push_back(pText);
						break;
					}
					default:
					{
						break;
					}
				}
			}

			//qInfo() << QString::fromStdString(setting);
			//qInfo() << QString::fromStdString(value);
		}
	}

	inFile.close();

	for (int i = 0; i < loadedShapes.size(); i++)
		qInfo() << loadedShapes[i]->getX();

	return loadedShapes;
}

void ShapesParser::writeShapesFile(vector<Shapes::Shape*> shapesData)
{
//	QFile file(":/test.txt");
//		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//		{
//			qInfo() << "outFile failed to load.";
//			exit(1);
//		}
	string fileName("C:\\Users\\roverdog\\Desktop\\CS1C-QT-Project\\CS1C-QT-Project\\test.txt");

	std::ofstream outFile;
	outFile.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);

	if (outFile.fail())
	{
		// exit if file not found. might use exception handling for this.
		qInfo() << "outFile failed to load.";
		exit(1);
	}

	outFile << '\n';
	for (Shapes::Shape* shape : shapesData)
	{
		qInfo() << "writing line";
		if (shape->getShape() == Shapes::Shape::ShapeType::Line)
		{
			Shapes::Line* pLine = dynamic_cast<Shapes::Line*>(shape);

			outFile << "ShapeId: " << pLine->getId() << '\n';
			outFile << "ShapeType: Line\n";
			int x1, y1, x2, y2;
			pLine->getPoints(x1,y1,x2,y2);
			outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << '\n';

			//QColor color(pLine->getPen().color());
			outFile << "PenColor: " << "color" << '\n';

			outFile << "PenWidth: " << pLine->getPen().width() << '\n';
			outFile << "PenStyle: " << writePenStyle(pLine->getPen().style()) << '\n';
			outFile << "PenCapStyle: " << writeCapStyle(pLine->getPen().capStyle()) << '\n';
			outFile << "PenJoinStyle: " << writeJoinStyle(pLine->getPen().joinStyle()) << '\n';

			outFile << '\n';
		}
		else if (shape->getShape() == Shapes::Shape::ShapeType::Polyline)
		{
			Shapes::Polyline* pPolyLine = dynamic_cast<Shapes::Polyline*>(shape);

			outFile << "ShapeId: " << pPolyLine->getId() << '\n';
			outFile << "ShapeType: Polyline\n";
			int x1{0}, y1{0}, x2{0}, y2{0};
			//pPolyLine->getPoints(x1,y1,x2,y2);
			outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << '\n';

			//QColor color(pPolyLine->getPen().color());
			outFile << "PenColor: " << "color" << '\n';

			outFile << "PenWidth: " << pPolyLine->getPen().width() << '\n';
			outFile << "PenStyle: " << writePenStyle(pPolyLine->getPen().style()) << '\n';
			outFile << "PenCapStyle: " << writeCapStyle(pPolyLine->getPen().capStyle()) << '\n';
			outFile << "PenJoinStyle: " << writeJoinStyle(pPolyLine->getPen().joinStyle()) << '\n';

			outFile << '\n';
		}
		else if (shape->getShape() == Shapes::Shape::ShapeType::Polygon)
		{
			Shapes::Polygon* pPolygon = dynamic_cast<Shapes::Polygon*>(shape);
			outFile << "ShapeId: " << pPolygon->getId() << '\n';
			outFile << "ShapeType: Polygon\n";
			int x1{0}, y1{0}, x2{0}, y2{0};
			//pPolyLine->getPoints(x1,y1,x2,y2);
			outFile << "ShapeDimensions: " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << '\n';

			//QColor color(pPolygon->getPen().color());
			outFile << "PenColor: " << "color" << '\n';

			outFile << "PenWidth: " << pPolygon->getPen().width() << '\n';
			outFile << "PenStyle: " << writePenStyle(pPolygon->getPen().style()) << '\n';
			outFile << "PenCapStyle: " << writeCapStyle(pPolygon->getPen().capStyle()) << '\n';
			outFile << "PenJoinStyle: " << writeJoinStyle(pPolygon->getPen().joinStyle()) << '\n';

			outFile << "BrushColor: " << "color" << '\n';
			outFile << "BrushStyle: " << writeBrushStyle(pPolygon->getBrush().style()) << '\n';

			outFile << '\n';
		}
		else if (shape->getShape() == Shapes::Shape::ShapeType::Rectangle)
		{
			Shapes::Rectangle* pRectangle = dynamic_cast<Shapes::Rectangle*>(shape);

			outFile << "ShapeId: " << pRectangle->getId() << '\n';

			if (pRectangle->getRect().width() == pRectangle->getRect().height())
			{
				outFile << "ShapeType: Square\n";
				outFile << "ShapeDimensions: " << pRectangle->getX() << ", " << pRectangle->getY()
						<< ", " << pRectangle->getRect().width() << '\n';
			}

			else
			{
				outFile << "ShapeType: Rectangle\n";
				outFile << "ShapeDimensions: " << pRectangle->getX() << ", " << pRectangle->getY()
						<< ", " << pRectangle->getRect().width() << ", " << pRectangle->getRect().height() << '\n';
			}

			//QColor color(pRectangle->getPen().color());
			outFile << "PenColor: " << "color" << '\n';

			outFile << "PenWidth: " << pRectangle->getPen().width() << '\n';
			outFile << "PenStyle: " << writePenStyle(pRectangle->getPen().style()) << '\n';
			outFile << "PenCapStyle: " << writeCapStyle(pRectangle->getPen().capStyle()) << '\n';
			outFile << "PenJoinStyle: " << writeJoinStyle(pRectangle->getPen().joinStyle()) << '\n';

			outFile << "BrushColor: " << "color" << '\n';
			outFile << "BrushStyle: " << writeBrushStyle(pRectangle->getBrush().style()) << '\n';

			outFile << '\n';
		}
		else if (shape->getShape() == Shapes::Shape::ShapeType::Ellipse)
		{
			Shapes::Ellipse* pEllipse = dynamic_cast<Shapes::Ellipse*>(shape);

			outFile << "ShapeId: " << pEllipse->getId() << '\n';

			if (pEllipse->getRect().width() == pEllipse->getRect().height())
			{
				outFile << "ShapeType: Circle\n";
				outFile << "ShapeDimensions: " << pEllipse->getX() << ", " << pEllipse->getY()
						<< ", " << pEllipse->getRect().width() << '\n';
			}

			else
			{
			outFile << "ShapeType: Ellipse\n";
			outFile << "ShapeDimensions: " << pEllipse->getX() << ", " << pEllipse->getY()
					<< ", " << pEllipse->getRect().width() << ", " << pEllipse->getRect().height() << '\n';
			}

			//QColor color(pEllipse->getPen().color());
			outFile << "PenColor: " << "color" << '\n';

			outFile << "PenWidth: " << pEllipse->getPen().width() << '\n';
			outFile << "PenStyle: " << writePenStyle(pEllipse->getPen().style()) << '\n';
			outFile << "PenCapStyle: " << writeCapStyle(pEllipse->getPen().capStyle()) << '\n';
			outFile << "PenJoinStyle: " << writeJoinStyle(pEllipse->getPen().joinStyle()) << '\n';

			outFile << "BrushColor: " << "color" << '\n';
			outFile << "BrushStyle: " << writeBrushStyle(pEllipse->getBrush().style()) << '\n';

			outFile << '\n';
		}
		else if (shape->getShape() == Shapes::Shape::ShapeType::Text)
		{
			Shapes::Text* pText = dynamic_cast<Shapes::Text*>(shape);

			outFile << "ShapeId: " << pText->getId() << '\n';
			outFile << "ShapeType: Text\n";
			outFile << "ShapeDimensions: " << pText->getX() << ", " << pText->getY()
					<< ", " << pText->getRect().width() << ", " << pText->getRect().height() << '\n';

			outFile << "TextString: " << pText->getText().toUtf8().constData() << '\n';

			outFile << "TextColor: " << "color" << '\n';

			outFile << "TextAlignment: " << /*writeAlignment(pText->getAlignment())*/ "alignment" << '\n';
			outFile << "TextPointSize: " << pText->getFont().pointSize() << '\n';
			outFile << "TextFontFamily: " << writeFamily(pText->getFont().family()) << '\n';
			outFile << "TextFontStyle: " << writeFontStyle(pText->getFont().style()) << '\n';
			outFile << "TextFontWeight: " << /*writeFontWeight(pText->getFont().weight())*/ "weight" << '\n';

			outFile << '\n';
		}
	}
}

void ShapesParser::removeSpaces(string &str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
}


void ShapesParser::parseLine(Shapes::Line* pLine, std::ifstream& inFile)
{
	while (line != "")
	{
		std::getline(inFile, line);
		std::istringstream lineStream(line);

		std::getline(lineStream, setting, ' ');
		std::getline(lineStream, value, '\n');

		switch(setting[0])
		{
			case 'S':
			{
				QPoint pointBegin = ShapesParser::parsePoint(value);
				QPoint pointEnd = ShapesParser::parsePoint(value);

				pLine->setPoints(pointBegin,pointEnd);
				break;
			}
			case 'P':
			{
				if (setting[3] == 'C' && setting [4] != 'a')
				{
					//qInfo() << QString::fromStdString(value);
					pLine->setPenColor(parseColor(value));
				}
				else if (setting[3] == 'W')
				{
					pLine->setPenWidth(parseInt(value));
				}
				else if (setting[3] == 'S')
				{
					pLine->setPenStyle(parsePenStyle(value));
				}
				else if (setting[4] == 'a')
				{
					pLine->setPenCapStyle(parseCap(value));
				}
				else if (setting[3] == 'J')
				{
					pLine->setPenJoinStyle(parseJoin(value));
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void ShapesParser::parsePolyline(Shapes::Polyline* pPolyline, std::ifstream& inFile)
{
	while (line != "")
	{
		std::getline(inFile, line);
		std::istringstream lineStream(line);

		std::getline(lineStream, setting, ' ');
		std::getline(lineStream, value, '\n');

		switch(setting[0])
		{
			case 'S':
			{
				vector<QPoint> points;

				while(value != "")
					points.push_back(ShapesParser::parsePoint(value));

				for(int i = 0; i < points.size(); i++)
					pPolyline->setPoint(points[i]);

				break;
			}
			case 'P':
			{
				if (setting[3] == 'C' && setting [4] != 'a')
				{
					pPolyline->setPenColor(parseColor(value));
				}
				else if (setting[3] == 'W')
				{
					pPolyline->setPenWidth(parseInt(value));
				}
				else if (setting[3] == 'S')
				{
					pPolyline->setPenStyle(parsePenStyle(value));
				}
				else if (setting[4] == 'a')
				{
					pPolyline->setPenCapStyle(parseCap(value));
				}
				else if (setting[3] == 'J')
				{
					pPolyline->setPenJoinStyle(parseJoin(value));
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void ShapesParser::parsePolygon(Shapes::Polygon* pPolygon, std::ifstream& inFile)
{
	while (line != "")
	{
		std::getline(inFile, line);
		std::istringstream lineStream(line);

		std::getline(lineStream, setting, ' ');
		std::getline(lineStream, value, '\n');

		switch(setting[0])
		{
			case 'S':
			{
				vector<QPoint> points;

				while(value != "")
					points.push_back(ShapesParser::parsePoint(value));

				for(int i = 0; i < points.size(); i++)
					pPolygon->setPoint(points[i]);

				break;
			}
			case 'P':
			{
				if (setting[3] == 'C' && setting [4] != 'a')
				{
					pPolygon->setPenColor(parseColor(value));
				}
                else if (setting[3] == 'W')
				{
					pPolygon->setPenWidth(parseInt(value));
				}
				else if (setting[3] == 'S')
				{
					pPolygon->setPenStyle(parsePenStyle(value));
				}
				else if (setting[4] == 'a')
				{
					pPolygon->setPenCapStyle(parseCap(value));
				}
				else if (setting[3] == 'J')
				{
					pPolygon->setPenJoinStyle(parseJoin(value));
				}
				break;
			}
			case 'B':
			{
				if (setting[5] == 'C')
				{
					pPolygon->setBrushColor(parseColor(value));
				}
				else if (setting[5] == 'S')
				{
					pPolygon->setBrushStyle(parseBrushStyle(value));
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void ShapesParser::parseRectangle(Shapes::Rectangle* pRectangle, std::ifstream& inFile)
{
	while (line != "")
	{
		std::getline(inFile, line);
		std::istringstream lineStream(line);

		std::getline(lineStream, setting, ' ');
		std::getline(lineStream, value, '\n');

		switch(setting[0])
		{
			case 'S':
			{
				pRectangle->setRectangle(parseRect(value));
				break;
			}
			case 'P':
			{
				if (setting[3] == 'C' && setting [4] != 'a')
				{
					pRectangle->setPenColor(parseColor(value));
				}
				else if (setting[3] == 'W')
				{
					pRectangle->setPenWidth(parseInt(value));
				}
				else if (setting[3] == 'S')
				{
					pRectangle->setPenStyle(parsePenStyle(value));
				}
				else if (setting[4] == 'a')
				{
					pRectangle->setPenCapStyle(parseCap(value));
				}
				else if (setting[3] == 'J')
				{
					pRectangle->setPenJoinStyle(parseJoin(value));
				}
				break;
			}
			case 'B':
			{
				if (setting[5] == 'C')
				{
					pRectangle->setBrushColor(parseColor(value));
				}
				else if (setting[5] == 'S')
				{
					pRectangle->setBrushStyle(parseBrushStyle(value));
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void ShapesParser::parseEllipse(Shapes::Ellipse* pEllipse, std::ifstream& inFile)
{
	while (line != "")
	{
		std::getline(inFile, line);
		std::istringstream lineStream(line);

		std::getline(lineStream, setting, ' ');
		std::getline(lineStream, value, '\n');

		switch(setting[0])
		{
			case 'S':
			{
				pEllipse->setEllipse(parseRect(value));
				break;
			}
			case 'P':
			{
				if (setting[3] == 'C' && setting [4] != 'a')
				{
					pEllipse->setPenColor(parseColor(value));
				}
				else if (setting[3] == 'W')
				{
					pEllipse->setPenWidth(parseInt(value));
				}
				else if (setting[3] == 'S')
				{
					pEllipse->setPenStyle(parsePenStyle(value));
				}
				else if (setting[4] == 'a')
				{
					pEllipse->setPenCapStyle(parseCap(value));
				}
				else if (setting[3] == 'J')
				{
					pEllipse->setPenJoinStyle(parseJoin(value));
				}
				break;
			}
			case 'B':
			{
				if (setting[5] == 'C')
				{
					pEllipse->setBrushColor(parseColor(value));
				}
				else if (setting[5] == 'S')
				{
					pEllipse->setBrushStyle(parseBrushStyle(value));
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void ShapesParser::parseText(Shapes::Text* pText, std::ifstream& inFile)
{
	while (line != "")
	{
		std::getline(inFile, line);
		std::istringstream lineStream(line);

		std::getline(lineStream, setting, ' ');
		std::getline(lineStream, value, '\n');

		switch(setting[0])
		{
			case 'S':
			{
				pText->setRect(parseRect(value));
				break;
			}
			case 'T':
			{
				if (setting[4] == 'S')
				{
					pText->setString(parseString(value));
				}
				else if (setting[4] == 'C')
				{
					pText->setPenColor(parseColor(value));
				}
				else if (setting[4] == 'A')
				{
					pText->setAlignment(parseAlignment(value));
				}
				else if (setting[4] == 'P')
				{
					pText->setPointSize(parseInt(value));
				}
				else if (setting[4] == 'F')
				{
					if (setting[8] == 'F')
					{
						pText->setFont(parseFont(value));
					}
					else if (setting[8] == 'S')
					{
						pText->setStyle(parseTextStyle(value));
					}
					else if (setting[8] == 'W')
					{
						pText->setWeight(parseWeight(value));
					}
				}
				break;
			}
			default:
			{
				break;
			}
		}
	}
}


QPoint ShapesParser::parsePoint(string& points)
{
	removeSpaces(points);
	string begin = points;

	//qInfo() << QString::fromStdString(points);

	std::istringstream lineStream(points);
	string str;
	char delim = ',';
	int x;
	int y;

	lineStream >> x >> delim >> y;
	if (lineStream.peek() == delim)
		lineStream.ignore();

	//qInfo() << x;
	//qInfo() << y;

	lineStream >> points;
	if(begin == points)
		points = "";

	//qInfo() << QString::fromStdString(points);

	QPoint coordinate(x,y);
	return coordinate;
}

Qt::GlobalColor ShapesParser::parseColor(string& color)
{
	switch (color[0])
	{
		case 'w':
		{
			return Qt::GlobalColor::white;
		}
		case 'b':
		{
			if (color[2] == 'u')
				return Qt::GlobalColor::blue;
			else
				return Qt::GlobalColor::black;
		}
		case 'r':
		{
			return Qt::GlobalColor::red;
		}
		case 'g':
		{
			if (color[2] == 'e')
				return Qt::GlobalColor::green;
			else
				return Qt::GlobalColor::gray;
		}
		case 'c':
		{
			return Qt::GlobalColor::cyan;
		}
		case 'm':
		{
			return Qt::GlobalColor::magenta;
		}
		case 'y':
		{
			return Qt::GlobalColor::yellow;
		}
		default:
		{
			return Qt::GlobalColor::black;
		}
	}
}

int ShapesParser::parseInt(string& width)
{
	std::istringstream lineStream(width);
	int temp;

	lineStream >> temp;
	return temp;
}

Qt::PenStyle ShapesParser::parsePenStyle(string& penStyle)
{
	switch (penStyle[0])
	{
		case 'N':
		{
			return Qt::PenStyle::NoPen;
		}
		case 'S':
		{
			return Qt::PenStyle::SolidLine;
		}
		case 'D':
		{
		if (penStyle[1] == 'o')
			return Qt::PenStyle::DotLine;
		else if (penStyle[4] == 'L')
			return Qt::PenStyle::DashLine;
		else if (penStyle[7] == 'L')
			return Qt::PenStyle::DashDotLine;
		else
			return Qt::PenStyle::DashDotDotLine;
		}
		default:
		{
			return Qt::PenStyle::SolidLine;
		}
	}
}

Qt::PenCapStyle ShapesParser::parseCap(string& cap)
{
	switch (cap[0])
	{
		case 'F':
		{
			return Qt::PenCapStyle::FlatCap;
		}
		case 'S':
		{
			return Qt::PenCapStyle::SquareCap;
		}
		case 'R':
		{
			return Qt::PenCapStyle::RoundCap;
		}
		default:
		{
			return Qt::PenCapStyle::FlatCap;
		}
	}
}
Qt::PenJoinStyle ShapesParser::parseJoin(string& join)
{
	switch (join[0])
	{
		case 'M':
		{
			return Qt::PenJoinStyle::MiterJoin;
		}
		case 'B':
		{
			return Qt::PenJoinStyle::BevelJoin;
		}
		case 'R':
		{
			return Qt::PenJoinStyle::RoundJoin;
		}
		default:
		{
			return Qt::PenJoinStyle::MiterJoin;
		}
	}
}

Qt::BrushStyle ShapesParser::parseBrushStyle(string& brushStyle)
{
	switch (brushStyle[0])
	{
		case 'S':
		{
			return Qt::BrushStyle::SolidPattern;
		}
		case 'H':
		{
			return Qt::BrushStyle::HorPattern;
		}
		case 'V':
		{
			return Qt::BrushStyle::VerPattern;
		}
		case 'N':
		{
			return Qt::BrushStyle::NoBrush;
		}
		default:
		{
			return Qt::BrushStyle::SolidPattern;
		}
	}
}

QRect ShapesParser::parseRect(string& rect)
{
	removeSpaces(rect);

	std::istringstream lineStream(rect);
	int x;
	int y;
	int width;
	int height;
	char delim = ',';

	int size = std::count(rect.begin(), rect.end(), delim);

	if (size == 2)
	{
		lineStream >> x >> delim >> y >> delim >> width;
		QRect rectangle(x, y, width, width);
		return rectangle;
	}
	else
	{
		lineStream >> x >> delim >> y >> delim >> width >> delim >> height;
		QRect rectangle(x, y, width, height);
		return rectangle;
	}
}

QString ShapesParser::parseString(string& text)
{
	return QString::fromStdString(text);
}


Qt::AlignmentFlag ShapesParser::parseAlignment(string& alignment)
{
	switch(alignment[5])
	{
		case 'L':
		   return Qt::AlignmentFlag::AlignLeft;
		case 'R':
			return Qt::AlignmentFlag::AlignRight;
		case 'T':
			return Qt::AlignmentFlag::AlignTop;
		case 'B':
			return Qt::AlignmentFlag::AlignBottom;
		case 'C':
			return Qt::AlignmentFlag::AlignCenter;
		default:
			return Qt::AlignmentFlag::AlignCenter;
	}
}

QString ShapesParser::parseFont(string& font)
{
	switch(font[0])
	{
		case 'C':
		{
			if (font[2] == 'm')
			{
				QString fontFamily = "Comic Sans MS";
				return fontFamily;
			}
			else if (font[2] == 'u')
			{
				QString fontFamily = "Courier";
				return fontFamily;
			}
			else
			{
				QString fontFamily = "Times";
				return fontFamily;
			}
		}
		case 'H':
		{
			QString fontFamily = "Helvetica";
			return fontFamily;
		}
		case 'T':
		{
			QString fontFamily = "Times";
			return fontFamily;
		}
		default:
		{
			QString fontFamily = "Times";
			return fontFamily;
		}
	}
}

QFont::Style ShapesParser::parseTextStyle(string& textStyle)
{
	switch(textStyle[5])
	{
		case 'N':
			return QFont::Style::StyleNormal;
		case 'I':
			return QFont::Style::StyleItalic;
		case 'O':
			return QFont::Style::StyleOblique;
		default:
			return QFont::Style::StyleNormal;
	}
}

QFont::Weight ShapesParser::parseWeight(string& weight)
{
	switch (weight[0])
	{
		case 'T':
			return QFont::Weight::Thin;
		case 'L':
			return QFont::Weight::Light;
		case 'N':
			return QFont::Weight::Normal;
		case 'B':
			return QFont::Weight::Bold;
		default:
			return QFont::Weight::Normal;
	}
}

string writeColor(const QColor color)
{

	if ( color == QColor(Qt::GlobalColor::white))
		return "white";

	else if ( color == QColor(Qt::GlobalColor::blue))
		return "blue";

	else if ( color == QColor(Qt::GlobalColor::black))
		return "black";

	else if ( color == QColor(Qt::GlobalColor::red))
		return "red";

	else if ( color == QColor(Qt::GlobalColor::green))
		return "green";

	else if ( color == QColor(Qt::GlobalColor::gray))
		return "gray";

	else if ( color == QColor(Qt::GlobalColor::cyan))
		return "cyan";

	else if ( color == QColor(Qt::GlobalColor::magenta))
		return "magenta";

	else if ( color == QColor(Qt::GlobalColor::yellow))
		return "yellow";

	else
		return "black";
}

string ShapesParser::writePenStyle(Qt::PenStyle penStyle)
{
	if (penStyle == Qt::PenStyle::NoPen)
		return "NoPen";
	else if (penStyle == Qt::PenStyle::SolidLine)
		return "SolidLine";
	if (penStyle == Qt::PenStyle::DashLine)
		return "DashLine";
	else if (penStyle == Qt::PenStyle::DotLine)
		return "DotLine";
	if (penStyle == Qt::PenStyle::DashDotLine)
		return "DashDotLine";
	else if (penStyle == Qt::PenStyle::SolidLine)
		return "DashDotDotLine";
	else
		return "SolidLine";
}
string ShapesParser::writeCapStyle(Qt::PenCapStyle cap)
{
	if (cap == Qt::PenCapStyle::FlatCap)
		return "FlatCap";
	else if (cap == Qt::PenCapStyle::SquareCap)
		return "SquareCap";
	else if (cap == Qt::PenCapStyle::RoundCap)
		return "RoundCap";
	else
		return "FlatCap";
}

string ShapesParser::writeJoinStyle(Qt::PenJoinStyle join)
{
	if (join == Qt::PenJoinStyle::MiterJoin)
		return "MiterJoin";
	else if (join == Qt::PenJoinStyle::BevelJoin)
		return "BevelJoin";
	else if (join == Qt::PenJoinStyle::RoundJoin)
		return "RoundJoin";
	else
		return "MiterJoin";
}

string ShapesParser::writeBrushStyle(Qt::BrushStyle brushStyle)
{
	if (brushStyle == Qt::BrushStyle::SolidPattern)
		return "SolidPattern";
	else if (brushStyle == Qt::BrushStyle::HorPattern)
		return "HorPattern";
	else if (brushStyle == Qt::BrushStyle::VerPattern)
		return "VerPattern";
	else if (brushStyle == Qt::BrushStyle::NoBrush)
		return "NoBrush";
	else
		return "SolidPattern";
}

string writeAlignment(Qt::AlignmentFlag alignment)
{
	if (alignment == Qt::AlignmentFlag::AlignLeft)
		return "AlignLeft";
	else if (alignment == Qt::AlignmentFlag::AlignRight)
		return "AlignRight";
	else if (alignment == Qt::AlignmentFlag::AlignTop)
		return "AlignTop";
	else if (alignment == Qt::AlignmentFlag::AlignBottom)
		return "AlignBottom";
	else if (alignment == Qt::AlignmentFlag::AlignCenter)
		return "AlignCenter";
	else
		return "AlignCenter";
}

string ShapesParser::writeFamily(QString family)
{
	if (family == "Comic Sans MS")
		return "Comic Sans MS";
	else if (family == "Courier")
		return "Courier";
	else if (family == "Helvetica")
		return "Helvetica";
	else if (family == "Times")
		return "Times";
}

string ShapesParser::writeFontStyle(QFont::Style style)
{
	if (style == QFont::Style::StyleNormal)
		return "StyleNormal";
	else if (style == QFont::Style::StyleItalic)
		return "StyleItalic";
	else if (style == QFont::Style::StyleOblique)
		return "StyleOblique";
	else
		return "StyleNormal";
}

string writeFontWeight(QFont::Weight weight)
{
	if (weight == 0)
		return "Thin";
	else if (weight == 25)
		return "Light";
	else if (weight == 50)
		return "Normal";
	else if (weight == 75)
		return "Bold";
	else
		return "Normal";
}
