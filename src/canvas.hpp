#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPointF>
#include <QWheelEvent>
#include <set>

#include "tool/tool.hpp"
#include "drawable/drawable.hpp"
namespace Lipuma {
	/*
		Subclass of the QGraphics view.
		Intends to override and improve panning behavior.
	*/
	class Canvas : public QGraphicsView {
		Q_OBJECT

	public:
		explicit Canvas(QGraphicsScene *parent = nullptr);

		Tool *getCurrentTool();
		void setCurrentTool(Tool *brush);
		static Canvas *singleton;

        void selectObject(Drawable*);
        void deselectObject(Drawable*);
        const std::set<Drawable*>& getObjectIterator() const;

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
		std::set<Drawable*> *selected;
	};

}
#endif // CANVAS_HPP
