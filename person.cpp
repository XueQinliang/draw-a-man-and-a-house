#include"person.h"
#include <QPainter>
#include<cmath>
void person::drawperson(QPainter &paint){
    paint.setBrush(Qt::lightGray);
    paint.drawEllipse(x-11*size/8,y-3*size/2,3*size,4*size);
    paint.setBrush(Qt::black);
    paint.drawEllipse(x-size,y,size/2,size/3);
    paint.drawEllipse(x+5*size/6,y,size/2,size/3);
    paint.setBrush(Qt::darkBlue);
    paint.drawRect(x-2*size,y+8*size+state,3*size/2,6*size);
    paint.drawRect(x+size,y+9*size-state,3*size/2,6*size);

    paint.drawRect(x-2*size/5,y+5*size/2,size,size/2);
    paint.drawRect(x-2*size,y+3*size,9*size/2,6*size);
    QPointF arm1[4] = {
          QPointF(x-3*size,y+3*size),
          QPointF(x-3*size+size*cos(angle),y+3*size-size*sin(angle)),
          QPointF(x-3*size+size*cos(angle)+sin(angle)*11*size/2,y+3*size+cos(angle)*11*size/2-size*sin(angle)),
          QPointF(x-3*size+sin(angle)*11*size/2,y+3*size+cos(angle)*11*size/2)
    };
    paint.drawPolygon(arm1, 4);
    angle=3.1415926/2-angle;
    QPointF arm2[4] = {
          QPointF(x+7*size/2-size*cos(angle),y+3*size-size*sin(angle)),
          QPointF(x+7*size/2,y+3*size),
          QPointF(x+7*size/2-sin(angle)*11*size/2,y+3*size+cos(angle)*11*size/2),
          QPointF(x+7*size/2-size*cos(angle)-sin(angle)*11*size/2,y+3*size+cos(angle)*11*size/2-size*sin(angle))
    };
    paint.drawPolygon(arm2, 4);
    paint.setBrush(Qt::red);
    QPointF mouth[4] = {
          QPointF(x-size/3,y+3*size/2),
          QPointF(x-size/12,y+2*size),
          QPointF(x+2*size/3,y+2*size),
          QPointF(x+11*size/12,y+3*size/2)
    };
    paint.drawPolygon(mouth, 4);
    paint.setBrush(Qt::green);
    QPointF hat[4] = {
          QPointF(x-size,y-size),
          QPointF(x+4*size/3,y-size),
          QPointF(x+5*size/3,y-2*size),
          QPointF(x-4*size/3,y-2*size)
    };
    paint.drawPolygon(hat, 4);
    QPointF nose[3] = {
          QPointF(x+size/4,y+size/2),
          QPointF(x,y+5*size/6),
          QPointF(x+size/2,y+5*size/6),
    };
    paint.drawPolygon(nose, 3);
}
