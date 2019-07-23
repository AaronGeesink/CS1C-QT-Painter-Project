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
	vector<Shapes::Shape*> shapesData;
    void setPositionCoords(int xCoord, int yCoord);

protected:
	void paintEvent(QPaintEvent *) override;

private slots:
	void on_pushButton_load_clicked();

private:
	Ui::canvas *ui;
	bool readFile;
    int xCoord;
    int yCoord;
};

#endif // CANVAS_H
