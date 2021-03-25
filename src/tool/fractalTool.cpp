#include <QMouseEvent>
#include <QWheelEvent>
#include <QMessageLogger>
#include <drawable/fractalLine.hpp>
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
        e->accept();
	}

	void FractalTool::mouseMoveEvent(QMouseEvent *e){
		if (isDrawing) line->setEnd(e->pos());
        e->accept();
	}

	void FractalTool::mouseReleaseEvent(QMouseEvent *e){
		// Im not sure if I should unset the line here.
		isDrawing = false;
        e->accept();
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
        e->accept();
	}
}
