#ifndef SHAPESPARSER_H
#define SHAPESPARSER_H

#include "shapes.h"
#include "canvas.h"
#include <fstream>
#include <sstream>

class ShapesParser
{
public:
	ShapesParser();

	// MUST CHANGE FILE PATH TO BE MORE GENERAL
	void readShapesFile();

	void writeShapesFile();
};

#endif // SHAPESPARSER_H
