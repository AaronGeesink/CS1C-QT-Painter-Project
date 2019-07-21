#include "shapesparser.h"
#include <QDebug>

ShapesParser::ShapesParser()
{ }

/*vector<Shapes::Line>&*/
void ShapesParser::readShapesFile()
{
	// MUST CHANGE FILE PATH TO BE MORE GENERAL
	string fileName("C:\\Users\\roverdog\\Desktop\\CS1C-QT-Project\\CS1C-QT-Project\\shapes.txt");

	std::ifstream inFile;
	inFile.open(fileName.c_str());

	if (inFile.fail())
	{
		// exit if file not found. might use exception handling for this.
		qInfo() << "inFile failed to load.";
		exit(1);
	}

	std::string line;
	std::string setting;
	std::string value;
	int id;

	while(std::getline(inFile, line))
	{
		if (line != "")
		{
			std::istringstream lineStream(line);

			std::getline(lineStream, setting, ' ');
			std::getline(lineStream, value, '\n');

			qInfo() << QString::fromStdString(setting);
			qInfo() << QString::fromStdString(value);
		}
	}

	//vector<Shapes::Line> test;
	//return test;
}

void ShapesParser::writeShapesFile()
{

}
