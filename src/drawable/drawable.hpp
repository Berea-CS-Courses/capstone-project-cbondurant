#ifndef DRAWABLE_DRAWABLE_HPP
#define DRAWABLE_DRAWABLE_HPP

#include <QGraphicsItem>

namespace Lipuma {
    class Drawable : public QGraphicsItem{
        public:
            bool selected;
    };
}

#endif
