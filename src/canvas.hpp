#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <vector>

#include "fractalLine.hpp"

class Canvas : public QWidget {
	Q_OBJECT

public:
	explicit Canvas(QWidget *parent = nullptr);

	QSize minimumSizeHint() const override;
	QSize sizeHint() const override;

protected:
	void paintEvent(QPaintEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;

private:
	float deform, falloff;
	std::vector<FractalLine*> lines;
};
