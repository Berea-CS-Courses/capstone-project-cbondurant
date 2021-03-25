#ifndef TOOL_FRACTALTOOL_HPP
#define TOOL_FRACTALTOOL_HPP

#include <QMouseEvent>
#include <QWheelEvent>

#include "tool/tool.hpp"
#include "drawable/fractalLine.hpp"

namespace Lipuma {

	/*
		This tool implements a click-drag interface for drawing brushes
	*/
	class FractalTool : public Tool{
	public:
		FractalTool();

		void mousePressEvent(QMouseEvent *e) override;
		void mouseReleaseEvent(QMouseEvent *e) override;
		void mouseMoveEvent(QMouseEvent *e) override;
		void wheelEvent(QWheelEvent *e) override;
	private:
		FractalLine *line;
		bool isDrawing;
	};
}

#endif //TOOL_FRACTALTOOL_HPP
