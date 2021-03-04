#include <QGraphicsItem>
#include <QMessageLogger>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <FastNoise/FastNoise.h>
#include "fractalLine.hpp"
#include "pointHelper.hpp"

#include <vector>

FractalLine::FractalLine(QPointF start, QPointF end) : start(start), end(end){
	noise = FastNoise::New<FastNoise::FractalFBm>();
	noise->SetSource(FastNoise::New<FastNoise::Simplex>());
	noise->SetOctaveCount(5);
	noise->SetLacunarity(0.3f);
	noise->SetGain(0);
}

QRectF FractalLine::boundingRect() const {
	QMargins extent(10,10,10,10);
	return QRectF(start, start).marginsAdded(extent)
	.united(QRectF(end, end).marginsAdded(extent));
}

void FractalLine::setStart(QPointF s){
	start = s;
	prepareGeometryChange();
	update();
	return;
}

void FractalLine::setEnd(QPointF e){
	end = e;
	prepareGeometryChange();
	update();
	return;
}


void FractalLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	float curve[SEGMENTS] = {};
	noise->GenUniformGrid2D(curve,0,0,SEGMENTS,1,0.2f,1337);
	QPainterPath path;
	path.moveTo(start);
	QPointF perp = Lipuma::normalize((end - start).transposed());
	perp.setX(-perp.x());
	for (int i = 1; i < SEGMENTS; i++){
		QPointF point = Lipuma::lerp(start, end, (float)i/SEGMENTS);
		point += perp * curve[i]*5;
		path.lineTo(point);
	}
	painter->drawPath(path);
	// painter->drawRect(boundingRect());
}
