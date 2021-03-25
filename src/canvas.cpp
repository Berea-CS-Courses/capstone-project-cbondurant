#include <QPointF>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cmath>
#include "canvas.hpp"
#include "tool/tool.hpp"
#include "tool/fractalTool.hpp"
#include "drawable/drawable.hpp"

namespace Lipuma {
	Canvas::Canvas(QGraphicsScene *parent) : QGraphicsView(parent){
		setBackgroundRole(QPalette::Base);
		setAutoFillBackground(true);
		//setDragMode(QGraphicsView::ScrollHandDrag);
		setResizeAnchor(QGraphicsView::AnchorUnderMouse);
		_currentTool = new FractalTool();
		setSceneRect(0, 0, 2000, 2000);
        selected = new std::set<Drawable*>();
	}

	Canvas *Canvas::singleton = nullptr;

    void Canvas::selectObject(Drawable* item){
        item->selected = true;
        selected->insert(item); 
    }

    void Canvas::deselectObject(Drawable* item){
        item->selected = false;
        selected->erase(item);
    }

    const std::set<Drawable*>& Canvas::getObjectIterator() const{
        return *selected;
    }

	void Canvas::wheelEvent(QWheelEvent *e){
		_currentTool->wheelEvent(e);
		/*
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
		*/
	}

	void Canvas::setCurrentTool(Tool *tool) {
		_currentTool->disableEvent();
		_currentTool = tool;
		_currentTool->enableEvent();
	}

	Tool *Canvas::getCurrentTool(){
		return _currentTool;
	}

	void Canvas::mouseMoveEvent(QMouseEvent *e){
		_currentTool->mouseMoveEvent(e);
	}

	void Canvas::mousePressEvent(QMouseEvent *e){
		_currentTool->mousePressEvent(e);
	}

	void Canvas::mouseDoubleClickEvent(QMouseEvent *e){
		_currentTool->mouseDoubleClickEvent(e);
	}

	void Canvas::mouseReleaseEvent(QMouseEvent *e){
		_currentTool->mouseReleaseEvent(e);
	}
}
