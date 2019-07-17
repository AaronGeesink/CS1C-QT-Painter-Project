#include "renderarea.h"

void RenderArea::paintEvent(QPaintEvent * event)
{
	Shapes::Line line(this);

	line.setPoints(QPoint(20, 90), QPoint(100, 20));

	line.setPen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);

	line.draw();
}

RenderArea::RenderArea(QWidget * parent)
{
}
