#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "shapes.h"
#include <QWidget>

class RenderArea : public QWidget
{
private:
	QPixmap pixmap;

protected:
	void paintEvent(QPaintEvent *event) override;

public:
	RenderArea(QWidget *parent = 0);

};

#endif // RENDERAREA_H
