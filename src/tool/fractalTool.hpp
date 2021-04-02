#ifndef TOOL_FRACTALTOOL_HPP
#define TOOL_FRACTALTOOL_HPP

#include <QMouseEvent>
#include <QWheelEvent>
#include <QGraphicsView>

#include "tool/tool.hpp"
#include "drawable/fractalLine.hpp"

namespace Lipuma {

	/*
		This tool implements a click-drag interface for drawing brushes
	*/
	class FractalTool : public Tool{
	public:
		FractalTool();

		void mousePressEvent(QMouseEvent *e, QGraphicsView *view) override;
		void mouseReleaseEvent(QMouseEvent *e, QGraphicsView *view) override;
		void mouseMoveEvent(QMouseEvent *e, QGraphicsView *view) override;
		void wheelEvent(QWheelEvent *e, QGraphicsView *view) override;
	private:
		FractalLine *line;
		bool isDrawing;
	};
}

#endif //TOOL_FRACTALTOOL_HPP
