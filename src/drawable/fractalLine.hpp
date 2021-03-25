#ifndef DRAWABLE_FRACTAL_LINE_HPP
#define DRAWABLE_FRACTAL_LINE_HPP

#include <QPointF>
#include <QRectF>
#include <QGraphicsItem>
#include <QPolygonF>
#include <FastNoise/FastNoise.h>

namespace Lipuma {

	/*
		Fractally deformed line with configurable deformation settings.

		Lacunarity: how much the frequency increases each iteration.
		Gain: how much the amplitude of each iteration decreases.
	*/
	class FractalLine : public QGraphicsItem {

	public:
		FractalLine(QPointF, QPointF);
		QRectF boundingRect() const override;
		void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

        // Get the rate at which fractal layers decrease in effect
		float getLacunarity();
        // Set the rate at which fractal layers decrease in effect
		void setLacunarity(float);

		void setStart(QPointF);
		void setEnd(QPointF);
		
        // Get frequency of crossing the zero per unit
		float getFrequency();
		void setFrequency(float);

	private:
		FastNoise::SmartNode<FastNoise::Fractal<>> noise;
		static const int SEGMENTS = 100;

		// 
		static const int PERIOD = 2;

		QPointF start, end;

		float frequency;
	};
}

#endif // DRAWABLE_FRACTAL_LINE_HPP
