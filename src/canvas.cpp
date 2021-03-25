#include <QPointF>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cmath>
#include "canvas.hpp"
#include "tool/tool.hpp"
#include "tool/toolManager.hpp"
#include "tool/fractalTool.hpp"
#include "drawable/drawable.hpp"

namespace Lipuma {
	Canvas::Canvas(QGraphicsScene *parent) : QGraphicsView(parent){
		setBackgroundRole(QPalette::Base);
		setAutoFillBackground(true);
		setDragMode(QGraphicsView::RubberBandDrag);
		setResizeAnchor(QGraphicsView::AnchorUnderMouse);
		_currentTool = ToolManager::getFractalTool();
		setSceneRect(0, 0, 2000, 2000);
	}

	Canvas *Canvas::singleton = nullptr;

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

    void Canvas::keyPressEvent(QKeyEvent *e){
        if (e->key() == Qt::Key_S && _currentTool != ToolManager::getSelectionTool()){
            _currentTool->disableEvent();
            _currentTool = ToolManager::getSelectionTool();
            _currentTool->enableEvent(); 
            e->accept();
        }
        if (e->key() == Qt::Key_F && _currentTool != ToolManager::getFractalTool()){
            _currentTool->disableEvent();
            _currentTool = ToolManager::getFractalTool();
            _currentTool->enableEvent(); 
            e->accept();
        }
        if (e->key() == Qt::Key_Delete || e->key() == Qt::Key_Backspace){
            auto itemList = scene()->selectedItems();
            for (auto i = itemList.begin(); i != itemList.end(); i++){
                scene()->removeItem(*i);
                delete *i;
            } 
            e->accept();
        }
        QGraphicsView::keyPressEvent(e);
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
        if (!e->isAccepted()) QGraphicsView::mouseMoveEvent(e);
	}

	void Canvas::mousePressEvent(QMouseEvent *e){
		_currentTool->mousePressEvent(e);
        if (!e->isAccepted()) QGraphicsView::mousePressEvent(e);
	}

	void Canvas::mouseDoubleClickEvent(QMouseEvent *e){
		_currentTool->mouseDoubleClickEvent(e);
        if (!e->isAccepted()) QGraphicsView::mouseDoubleClickEvent(e);
	}

	void Canvas::mouseReleaseEvent(QMouseEvent *e){
		_currentTool->mouseReleaseEvent(e);
        if (!e->isAccepted()) QGraphicsView::mouseReleaseEvent(e);
	}
}
