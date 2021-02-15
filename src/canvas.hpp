#include <QGraphicsView>
#include <QPointF>
#include <QWheelEvent>
#include <vector>

#include "fractalLine.hpp"

class Canvas : public QGraphicsView {
	Q_OBJECT

public:
	explicit Canvas(QGraphicsScene *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *e) override;
private:
    QPointF _offset;
    bool _isPanning;
    QPoint _panPrev;
	std::vector<FractalLine*> lines;
};
