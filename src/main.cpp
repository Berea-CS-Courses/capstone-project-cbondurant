#include <QApplication>
#include <QPainter>
#include "canvas.hpp"

int main (int argc, char **argv){
	QApplication a(argc, argv);
    QGraphicsScene scene;
	Lipuma::Canvas canvas(&scene);
	canvas.show();
	Lipuma::Canvas::singleton = &canvas;
	return a.exec();
}
