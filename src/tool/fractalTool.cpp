#include <QMouseEvent>
#include <QWheelEvent>
#include <QMessageLogger>
#include <fractalLine.hpp>
#include <tool/fractalTool.hpp>
#include <canvas.hpp>

namespace Lipuma {
	FractalTool::FractalTool(){
		line = nullptr;
		isDrawing = false;
	}

	void FractalTool::mousePressEvent(QMouseEvent *e){
		line = new FractalLine(e->pos(), e->pos());
		Canvas::singleton->scene()->addItem(line);
		isDrawing = true;
	}

	void FractalTool::mouseMoveEvent(QMouseEvent *e){
		if (isDrawing) line->setEnd(e->pos());
	}

	void FractalTool::mouseReleaseEvent(QMouseEvent *e){
		// Im not sure if I should unset the line here.
		isDrawing = false;
	}

	void FractalTool::wheelEvent(QWheelEvent *e){
		if (isDrawing){
			float freq = line->getFrequency();
			if (e->angleDelta().y() > 0){
				if (freq > 0){
					line->setFrequency(freq / 0.9);
				}
			}else{
				line->setFrequency(freq * 0.9);
			}
		}
	}
}