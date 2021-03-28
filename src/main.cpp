#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QDockWidget>
#include <QTextEdit>
#include <QtWidgets>
#include "canvas.hpp"
#include "widget/toolSelector.hpp"

int main (int argc, char **argv){
	QApplication a(argc, argv);
    QGraphicsScene scene;
	Lipuma::Canvas *canvas = new Lipuma::Canvas(&scene);
    QMainWindow *mainWin = new QMainWindow();
    mainWin->setCentralWidget(canvas);

    mainWin->menuBar()->addMenu("Lipuma");

    mainWin->show();
	return a.exec();
}
