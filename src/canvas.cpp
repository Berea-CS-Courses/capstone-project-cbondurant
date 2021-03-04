#include <QPointF>
#include <QPainter>
#include <QGraphicsView>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "canvas.hpp"

Canvas::Canvas(QGraphicsScene *parent) : QGraphicsView(parent){
	lines = std::vector<FractalLine*>();
	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);
	setDragMode(QGraphicsView::ScrollHandDrag);
	setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	//*
	line = new FractalLine(QPointF(0,0), QPointF(200,200));
	scene()->addItem(line);
	for (int i = 0; i < 200; i++){
		// scene()->addLine(5+i*10, 5, 405+i*10, 495);
		// lines.emplace(lines.end(),new FractalLine(new QPointF(5+i*10, 5),new QPointF(405+i*10, 495), 9));
	}
	/**/
	scene()->addText("Hello World");

	// setSceneRect(0, 0, 2000, 2000);
}

void Canvas::wheelEvent(QWheelEvent *e){
	if (e->angleDelta().y() > 0){
		scale(1.0/1.5, 1.0/1.5);
	}
	if (e->angleDelta().y() < 0){
		scale(1.5, 1.5);
	}

	if (transform().m11() < 0.1){
		scale(0.1/transform().m11(), 0.1/transform().m22());
	}

	if (transform().m11() > 10){
		scale(10/transform().m11(), 10/transform().m22());
	}
}

void Canvas::mouseMoveEvent(QMouseEvent *e){
	QGraphicsView::mouseMoveEvent(e);
	line->setEnd(mapToScene(e->pos()));
}