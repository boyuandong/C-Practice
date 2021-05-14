// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle:public Point
{
friend ostream & operator<<(ostream & output, const Circle & c);
protected:
    double radius;
public:
    Circle(double r=0.0, int x=0, int y=0); //instructor
    void setRadius(double r);   //setter
    double getRadius()const;    // getter
    double area()const;         // get area of the circle
};
//instructor
Circle::Circle(double r, int a, int b):Point(a,b)
{
    setRadius(r);
}
//setRadius
void Circle::setRadius(double r)
{ radius = ( r>=0? r: 0 ); }
//return radius
double Circle::getRadius()const
{ return radius; }
// get area of the circle
double Circle::area()const
{ return 3.1415926 * radius * radius; }
// output the center point of the circle and radius
ostream & operator<<(ostream & output, const Circle & c)
{
    output<<"Center="<<"["<<c.x<<","<<c.y<<"]"<<";Radius="<<c.radius;
    return output;
}
#endif

