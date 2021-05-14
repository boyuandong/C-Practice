// Point.h
#ifndef POINT_H
#define POINT_H
class Point
{
friend ostream & operator<<(ostream & output, const Point & p);
protected:
    int x, y;
public:
    Point(int = 0, int = 0);    //intstructor
    void setPoint(int, int);    //setter
    int getX() const
    { return x; }
    int getY() const
    { return y; }
};

Point::Point(int a, int b)  //intstructor
{
    setPoint(a,b);
}
void Point::setPoint(int a, int b)  //setter
{
    x = a;
    y = b;
}
// overload <<
ostream & operator<<(ostream & output, const Point & p)
{
    output<<"["<<p.x<<","<<p.y<<"]";
    return output;
}
#endif
