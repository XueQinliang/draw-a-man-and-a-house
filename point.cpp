#include "point.h"
point::point(point &p){
        x=p.x;
        y=p.y;
    }
int point::getx(){return x;}
int point::gety(){return y;}
