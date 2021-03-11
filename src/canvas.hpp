#ifndef CANVAS_H_
#define CANVAS_H_

#include <QGraphicsView>
#include <QPointF>
#include <QWheelEvent>
#include <vector>

#include "fractalLine.hpp"
#include "tool/tool.hpp"
namespace Lipuma {
	/*
		Subclass of the QGraphics view.
		Intends to override and improve panning behavior.
	*/
	class Canvas : public QGraphicsView {
		Q_OBJECT

	public:
		explicit Canvas(QGraphicsScene *parent = nullptr);
		FractalLine *line;

		Tool *getCurrentTool();
		void setCurrentTool(Tool *brush);
		static Canvas *singleton;

	protected:
		void wheelEvent(QWheelEvent *e) override;
		void mouseMoveEvent(QMouseEvent *e) override;
		void mousePressEvent(QMouseEvent *e) override;
		void mouseReleaseEvent(QMouseEvent *e) override;
		void mouseDoubleClickEvent(QMouseEvent *e) override;

	private:
		Tool *_currentTool;
		QPointF _offset;
		bool _isPanning;
		QPoint _panPrev;
		std::vector<FractalLine*> lines;
	};

}
#endif // CANVAS_H_
