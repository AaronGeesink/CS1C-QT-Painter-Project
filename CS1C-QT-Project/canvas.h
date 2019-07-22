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

protected:
	void paintEvent(QPaintEvent *) override;

private slots:
	void on_pushButton_load_clicked();

private:
	Ui::canvas *ui;
	bool readFile;
	int x;
	int y;
};

#endif // CANVAS_H
