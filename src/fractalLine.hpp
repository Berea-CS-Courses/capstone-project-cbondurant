#include <QPointF>
#include <QPolygonF>
#include <random>

class FractalLine {

public:
	QPolygonF* toPolyLine();
	QPolygonF* fractalize(const QPointF *a, const QPointF *b, int d);
	FractalLine(QPointF*, QPointF*, int);
	
private:
	QPointF *start;
	QPointF *end;
	int seed;
	float deform;
	float falloff;
	int depth; // Max number of deform iterations

	static std::minstd_rand rand;
};
