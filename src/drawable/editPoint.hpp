#ifndef DRAWABLE_EDIT_POINT_HPP
#define DRAWABLE_EDIT_POINT_HPP

#include <QGraphicsObject>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>

namespace Lipuma {
	class EditPoint : public QGraphicsObject {

		Q_OBJECT

	public:
		EditPoint();
		void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
		void mouseMoveEvent(QGraphicsSceneMouseEvent *e) override;
		void mouseReleaseEvent(QGraphicsSceneMouseEvent *e) override;

		QRectF boundingRect() const override;
		void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

	signals:
		void pointMoved(QPointF);

	private:
		bool _isTracking;

		// The function to be called on the parent

	};
}

#endif