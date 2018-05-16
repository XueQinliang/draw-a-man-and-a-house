#include"house.h"
#include <QPainter>
void house::drawhouse(QPainter &paint){
    paint.setBrush(Qt::yellow);
    QPointF houseside2[4] = {
          QPointF(x,y+5*size),
          QPointF(x,y),
          QPointF(x+3*size,y-3*size),
          QPointF(x+3*size,y+2*size)
    };
    paint.drawPolygon(houseside2, 4);
    paint.drawRect(x+3*size,y-3*size,10*size,5*size);
    paint.drawRect(x,y,10*size,5*size);
    paint.setBrush(Qt::black);
    paint.drawRect(x+6*size,y+size,2*size,4*size);
    paint.setBrush(Qt::white);
    paint.drawRect(x+3*size,y+size,2*size,2*size);
    paint.setBrush(Qt::gray);
    QPointF roof1[3] = {
          QPointF(x+3*size,y-3*size),
          QPointF(x,y),
          QPointF(x+3*size/2,y-4*size),
    };
    paint.drawPolygon(roof1, 3);
    QPointF roof2[3] = {
          QPointF(x+13*size,y-3*size),
          QPointF(x+10*size,y),
          QPointF(x+23*size/2,y-4*size),
    };
    paint.drawPolygon(roof2, 3);
    QPointF roof3[4] = {
        QPointF(x+3*size/2,y-4*size),
        QPointF(x+23*size/2,y-4*size),
        QPointF(x+10*size,y),
        QPointF(x,y)
    };
    paint.drawPolygon(roof3, 4);
    paint.setBrush(Qt::yellow);
    QPointF houseside1[4] = {
          QPointF(x+10*size,y+5*size),
          QPointF(x+10*size,y),
          QPointF(x+13*size,y-3*size),
          QPointF(x+13*size,y+2*size)
    };
    paint.drawPolygon(houseside1, 4);
    for(int i=0;i<10*size;i=i+4){
        point p1(x+i,y),p2(x+3*size/2+i,y-4*size);
        line l(p1,p2);
        l.drawline(paint);
    }


}
