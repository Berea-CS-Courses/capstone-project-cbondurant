#ifndef CANVAS_H_
#define CANVAS_H_

#include <QGraphicsView>
#include <QPointF>
#include <QWheelEvent>
#include <vector>

#include "fractalLine.hpp"

class Canvas : public QGraphicsView {
	Q_OBJECT

public:
	explicit Canvas(QGraphicsScene *parent = nullptr);
	FractalLine *line;

protected:
	void wheelEvent(QWheelEvent *e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
private:
	QPointF _offset;
	bool _isPanning;
	QPoint _panPrev;
	std::vector<FractalLine*> lines;
};

#endif // CANVAS_H_
