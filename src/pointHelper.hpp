#ifndef POINT_HELPER_HPP
#define POINT_HELPER_HPP

#include <QPointF>
#include <cmath>

namespace Lipuma{
	/*
		Linear Interpolation
		from x=0 => x=1 interpolates from a to b
	*/
	QPointF lerp(QPointF a, QPointF b, qreal x){
		return (a*(1-x) + b* x);
	}

	/*
		Normalizes a 2d vector represented as a QPointF to unit length
	*/
	QPointF normalize(QPointF p){
		qreal d = sqrt(abs(QPointF::dotProduct(p,p)));
		return p/d;
	}

	// Computes the euclidan distance of a vector
	qreal distance(QPointF p){
		return sqrt(abs(QPointF::dotProduct(p,p)));
	}
}

#endif // POINT_HELPER_HPP
