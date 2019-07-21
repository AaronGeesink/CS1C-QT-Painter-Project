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

protected:
	void paintEvent(QPaintEvent *) override;

private:
	Ui::canvas *ui;
	vector<Shapes::Shape*> shapesData;
};

#endif // CANVAS_H
