#ifndef POINT_HELPER_HPP
#define POINT_HELPER_HPP

#include <QPointF>
#include <cmath>

namespace Lipuma{
	/*
		Linear Interpolation
		from x=0 => x=1 interpolates from a to b
	*/
	QPointF lerp(QPointF a, QPointF b, float x){
		return (a*(1-x) + b* x);
	}

	/*
		Normalizes a 2d vector represented as a QPointF to length 1u
	*/
	QPointF normalize(QPointF p){
		double d = sqrt(abs((pow(p.x(), 2) + pow(p.y(), 2))));
		return p/d;
	}

	double distance(QPointF p){
		return sqrt(abs((pow(p.x(), 2) + pow(p.y(), 2))));
	}
}

#endif // POINT_HELPER_HPP
