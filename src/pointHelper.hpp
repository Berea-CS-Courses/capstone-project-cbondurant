#ifndef POINT_HELPER_H
#define POINT_HELPER_H

#include <QPointF>
#include <cmath>

namespace Lipuma{
	QPointF lerp(QPointF a, QPointF b, float x){
		return (a*(1-x) + b* x);
	}

	QPointF normalize(QPointF p){
		double d = sqrt(abs((pow(p.x(), 2) + pow(p.y(), 2))));
		return p/d;
	}
}

#endif //POINT_HELPER_H