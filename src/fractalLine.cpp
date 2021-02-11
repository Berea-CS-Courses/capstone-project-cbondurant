#include "fractalLine.hpp"

std::minstd_rand FractalLine::rand = std::minstd_rand();

FractalLine::FractalLine(QPointF *st, QPointF *e, int d){
	std::random_device s;
	seed = s();
    start = st;
    end = e;
    depth = d;
    deform = 0.75;
}

QPolygonF* FractalLine::fractalize(const QPointF *a, const QPointF *b, int d){
	QPointF mid = (*a + *b)/2;

	QPointF offset = *b - mid;

	float tmp = offset.x();
	offset.setX(offset.y() * -1);
	offset.setY(tmp);
	int r = rand();
    float deformRand = (float)(r - ((float)FractalLine::rand.max()/2))/ (float)FractalLine::rand.max();
	mid += offset * deform * deformRand;
	QPolygonF *line = new QPolygonF();
	float dist = pow(offset.x(),2) + pow(offset.y(),2);
	if (abs(sqrt(dist)*deform) > 1 and d != 0){
		line->append(*this->fractalize(a,&mid,d-1));
		line->append(*this->fractalize(&mid,b,d-1));
	}else{
        line->append(*a);
        line->append(mid);
        line->append(*b);
	}
	return line;
}

QPolygonF* FractalLine::toPolyLine(){
	FractalLine::rand.seed(seed);
	return this->fractalize(start, end, depth);
}
