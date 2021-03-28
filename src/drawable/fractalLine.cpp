#include <QColor>
#include <QGraphicsItem>
#include <QMessageLogger>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QtDebug>
#include <FastNoise/FastNoise.h>
#include <cmath>
#include <random>
#include <QMessageLogger>
#include "fractalLine.hpp"
#include "pointHelper.hpp"

#include <vector>
namespace Lipuma {

    std::default_random_engine FractalLine::rand;
    
	FractalLine::FractalLine(QPointF s, QPointF e){
        seed = FractalLine::rand();
        setFlag(QGraphicsItem::ItemIsSelectable);
		noise = FastNoise::New<FastNoise::FractalFBm>();
		noise->SetSource(FastNoise::New<FastNoise::Simplex>());
		frequency = 0.05;
		noise->SetOctaveCount(5);
		noise->SetLacunarity(2.0f);
		noise->SetGain(.9);
        setStart(s);
        setEnd(e);
	}

	QRectF FractalLine::boundingRect() const {
		return QRectF(start.x()-5,-HEIGHT,end.x()+10,HEIGHT*2);
	}

	void FractalLine::setStart(QPointF s){
		setPos(s);
		prepareGeometryChange();
		update();
	}

	void FractalLine::setEnd(QPointF e){
        QPointF delta = e - pos();
        double distance = Lipuma::distance(delta);
        double theta = atan2(delta.y(),delta.x());
        setRotation(theta*180/3.1415);
        end = QPointF(distance,0);
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
    // the option and widget fields are required for this interface but unused,
    // Silencing warning for unused parameter
   
	void FractalLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
		painter->setRenderHint(QPainter::Antialiasing, true);
		// Set highlight color if selected
        if (isSelected()){
            painter->setPen(QColor(255,0,0));
        }

		// Dont draw really really short lines 
		if (end.x() < 0.1) return;

		// Figure out the number of points to render the line with
		const int POINTS = end.x() / PERIOD;
		float curve[((POINTS+8)/8)*8] = {}; // Round to nearest multiple of 8, fastnoise runs better with it
		noise->GenUniformGrid2D(curve,0,0,((POINTS+8)/8)*8,1,frequency,seed);

		// Generate path
		QPainterPath path;
		// First and last point need to always be at zero, so skip the 0th element and the final element
		for (int i = 1; i < POINTS; i++){
			QPointF point = Lipuma::lerp(start, QPointF(POINTS*PERIOD,0), static_cast<float>(i)/static_cast<float>(POINTS));
			point += QPointF(0, curve[i-1]*HEIGHT);
			path.lineTo(point);
		}
		// Draw final point
        path.lineTo(end);
		painter->drawPath(path);
		//painter->drawRect(boundingRect());
	}
#pragma GCC diagnostic pop
}
