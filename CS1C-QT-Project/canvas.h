#ifndef CANVAS_H
#define CANVAS_H

#include "shapes.h"
#include <QWidget>

namespace Ui {
class canvas;
}

class canvas : public QWidget
{
	Q_OBJECT

public:
	explicit canvas(QWidget *parent = nullptr);
	~canvas() override;
	void setPositionCoords(int x, int y, int id);
	void setShapesData(vector<Shapes::Shape*> shapesData);
	void loadFile();
	void saveFile();

protected:
	void paintEvent(QPaintEvent *) override;

private:
	Ui::canvas *ui;
	bool render;
	bool error;
	vector<Shapes::Shape*> shapesData;
	vector<Shapes::Shape*> buffer;
};

#endif // CANVAS_H
