#include "tool/selectionTool.hpp"

#include "canvas.hpp"

namespace Lipuma {
	void SelectionTool::mousePressEvent(QMouseEvent *e, QGraphicsView */* view */){
		e->ignore();
	}
}
