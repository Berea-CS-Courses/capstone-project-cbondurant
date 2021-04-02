#include <QMouseEvent>
#include <QWheelEvent>
#include <QGraphicsView>

#include "tool/tool.hpp"

namespace Lipuma {
	Tool::Tool() {}
	void Tool::enableEvent(QGraphicsView */* view */) {}
	void Tool::disableEvent(QGraphicsView */* view */) {}
	void Tool::mousePressEvent(QMouseEvent *e, QGraphicsView */* view */) {e->ignore();}
	void Tool::mouseReleaseEvent(QMouseEvent *e, QGraphicsView */* view */) {e->ignore();}
	void Tool::mouseDoubleClickEvent(QMouseEvent *e, QGraphicsView */* view */) {e->ignore();}
	void Tool::mouseMoveEvent(QMouseEvent *e, QGraphicsView */* view */) {e->ignore();}
	void Tool::wheelEvent(QWheelEvent *e, QGraphicsView */* view */) {e->ignore();}
}
