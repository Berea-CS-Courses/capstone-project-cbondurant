#ifndef BRUSH_BRUSH_HPP
#define BRUSH_BRUSH_HPP

#include <QMouseEvent>
#include <QWheelEvent>

namespace Lipuma {
	/*
		Pure virtual interface for reimplementing swappable mouse behavior.
	*/
	class Tool {
	public:
		Tool();

		// Events for the brush to handle

		// Called when the tool is activated in the canvas
		virtual void enableEvent();

		// Called when a different tool is selected while this one is
		virtual void disableEvent();

		// Passthroughs of Qt events when tool active
		virtual void mousePressEvent(QMouseEvent *e);
		virtual void mouseReleaseEvent(QMouseEvent *e);
		virtual void mouseDoubleClickEvent(QMouseEvent *e);
		virtual void mouseMoveEvent(QMouseEvent *e);

		virtual void wheelEvent(QWheelEvent *e);

		// Brush settings interface
	};
}

#endif // BRUSH_BRUSH_HPP