#ifndef FRACTAL_LINE_H_
#define FRACTAL_LINE_H_

#include <QPointF>
#include <QRectF>
#include <QGraphicsItem>
#include <QPolygonF>
#include <FastNoise/FastNoise.h>


class FractalLine : public QGraphicsItem {

public:
	FractalLine(QPointF, QPointF);
	QRectF boundingRect() const override;
	void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

	float getLacunarity();
	void setLacunarity(float);

	void setStart(QPointF);
	void setEnd(QPointF);
	

private:
	FastNoise::SmartNode<FastNoise::Fractal<>> noise;
	static const int SEGMENTS = 500;

	QPointF start, end;
};

#endif // FRACTAL_LINE_H_
