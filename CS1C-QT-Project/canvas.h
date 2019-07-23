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

protected:
	void paintEvent(QPaintEvent *) override;

private slots:
	void on_pushButton_load_clicked();

private:
	Ui::canvas *ui;
	bool readFile;
	vector<Shapes::Shape*> shapesData;
	int xCoord;
	int yCoord;
};

#endif // CANVAS_H
