#include <QPointF>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "canvas.hpp"

Canvas::Canvas(QWidget *parent) : QWidget(parent){
	lines = std::vector<FractalLine*>();
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
	for (int i = 0; i < 5; i++){
		lines.emplace(lines.end(),new FractalLine(new QPointF(5+i*200, 5),new QPointF(405+i*25, 495), 6));
	}
}

QSize Canvas::sizeHint() const{
	return QSize(400,400);
}

QSize Canvas::minimumSizeHint() const{
	return QSize(100,100);
}

void Canvas::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_Right){
		falloff += 1;
	}
	if (event->key() == Qt::Key_Left){
		falloff -= 1;
		if (falloff < 1) falloff = 1;
	}
	if (event->key() == Qt::Key_Up){
		deform += 0.1;
	}
	if (event->key() == Qt::Key_Down){
		deform -= 0.1;
		if (deform <0.1) deform = 0.1;
	}
	update();
}

void Canvas::paintEvent(QPaintEvent * /*event*/){
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, false);
	for (const auto &l : lines){
		painter.drawPolyline(*l->toPolyLine());
	}
}
