#ifndef LINE_H
#define LINE_H
#include "point.h"
#include <QPainter>
class line{
public:line(point p1,point p2):_p1(p1),_p2(p2){}
    line(line &l):_p1(l._p1),_p2(l._p2){}
    void drawline(QPainter &paint);
    ~line(){}
private:
    point _p1,_p2;
};

#endif // LINE_H
