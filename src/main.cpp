#include <QApplication>
#include <QPainter>
#include "canvas.hpp"

int main (int argc, char **argv){
	QApplication a(argc, argv);
	Canvas canvas;
	canvas.show();
	return a.exec();
}
