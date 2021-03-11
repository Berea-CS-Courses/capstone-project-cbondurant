#include <QMouseEvent>
#include <QWheelEvent>

#include "tool/tool.hpp"

namespace Lipuma {
	Tool::Tool() {}
	void Tool::enableEvent() {}
	void Tool::disableEvent() {}
	void Tool::mousePressEvent(QMouseEvent *e) {}
	void Tool::mouseReleaseEvent(QMouseEvent *e) {}
	void Tool::mouseDoubleClickEvent(QMouseEvent *e) {}
	void Tool::mouseMoveEvent(QMouseEvent *e) {}
	void Tool::wheelEvent(QWheelEvent *e) {}
}