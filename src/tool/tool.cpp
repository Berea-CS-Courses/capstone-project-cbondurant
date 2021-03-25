#include <QMouseEvent>
#include <QWheelEvent>

#include "tool/tool.hpp"

namespace Lipuma {
	Tool::Tool() {}
	void Tool::enableEvent() {}
	void Tool::disableEvent() {}
	void Tool::mousePressEvent(QMouseEvent *e) {e->ignore();}
	void Tool::mouseReleaseEvent(QMouseEvent *e) {e->ignore();}
	void Tool::mouseDoubleClickEvent(QMouseEvent *e) {e->ignore();}
	void Tool::mouseMoveEvent(QMouseEvent *e) {e->ignore();}
	void Tool::wheelEvent(QWheelEvent *e) {e->ignore();}
}
