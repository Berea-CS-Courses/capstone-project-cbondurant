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
namespace Lipuma {
	FractalLine::FractalLine(QPointF start, QPointF end) : start(start), end(end){
		noise = FastNoise::New<FastNoise::FractalFBm>();
		noise->SetSource(FastNoise::New<FastNoise::Simplex>());
		frequency = 20;
		noise->SetOctaveCount(50);
		noise->SetLacunarity(2.0f);
		noise->SetGain(.09);
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
	}

	void FractalLine::setEnd(QPointF e){
		end = e;
		prepareGeometryChange();
		update();
	}

	float FractalLine::getFrequency(){
		return frequency;
	}

	void FractalLine::setFrequency(float f){
		frequency = f;
		prepareGeometryChange();
		update();
	}

	void FractalLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
		const int POINTS = (distance(start-end) / PERIOD) + 8; 
		float curve[POINTS] = {};
		noise->GenUniformGrid2D(curve,0,0,POINTS,1,frequency,1337);
		QPainterPath path;
		path.moveTo(start);
		if (distance(end-start) < 1){return;}
		QPointF perp = Lipuma::normalize((end - start).transposed());
		perp.setX(-perp.x());
		for (int i = 1; i <= POINTS; i++){
			QPointF point = Lipuma::lerp(start, end, (float)i/POINTS);
			point += perp * curve[i-1]*50;
			assert (abs(point.x()) < 100000);
			path.lineTo(point);
		}
		painter->drawPath(path);
		//painter->drawRect(boundingRect());
	}
}