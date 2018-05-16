#include "line.h"
#include "point.h"
#include <QPainter>
void line::drawline(QPainter &paint){
    paint.drawLine(_p1.getx(),_p1.gety(),_p2.getx(),_p2.gety());
}
