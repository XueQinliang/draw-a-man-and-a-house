#ifndef PERSON_H
#define PERSON_H
#include "point.h"
#include "line.h"
#include <QPainter>
class person{
public:
    person(){}
    person(int x,int y,int size,int state,double angle):x(x),y(y),size(size),state(state),angle(angle){}
    person(person &ps){
        this->x=ps.x;
        this->y=ps.y;
        this->size=ps.size;
        this->state=ps.state;
        this->angle=ps.angle;
    }
    void drawperson(QPainter &paint);
    ~person(){}
private:
    int x,y,size,state;
    double angle;
};

#endif // PERSON_H
