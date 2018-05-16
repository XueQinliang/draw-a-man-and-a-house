#ifndef HOUSE_H
#define HOUSE_H
#include "point.h"
#include "line.h"
#include <QPainter>
class house{
public:
    house(){}
    house(int x,int y,int size):x(x),y(y),size(size){}
    house(house &hs){
        this->x=hs.x;
        this->y=hs.y;
        this->size=hs.size;
    }
    void drawhouse(QPainter &paint);
    ~house(){}
private:
    int x,y,size;
};
#endif // HOUSE_H
