#ifndef POINT_H
#define POINT_H
class point{
public:point(int x=0,int y=0):x(x),y(y){}
    point(point &p);
    int getx();
    int gety();
    ~point(){}
private:
    int x,y;
};

#endif // POINT_H
