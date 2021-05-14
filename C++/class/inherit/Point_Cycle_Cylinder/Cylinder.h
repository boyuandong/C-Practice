// Cylinder.h
#ifndef CYLINDER_H
#define CYLINDER_H
class Cylinder:public Circle
{
friend ostream & operator<<(ostream & output, const Cylinder & cy);
protected:
    double height;
public:
    Cylinder(double h=0.0, double r=0.0, int x=0, int y=0); //instructor
    void setHeight(double h);       // setter
    double getHeight()const;        // getter
    double area()const;             // get surface area of cylinder
    double volume()const;           // get volume of cylinder
};

Cylinder::Cylinder(double h, double r, int a, int b):Circle(r,a,b)
{
    setHeight(h);
}
void Cylinder::setHeight(double h)
{
    height = ( h>=0 ? h: 0);
}
double Cylinder::getHeight()const
{ return height; }
double Cylinder::area()const
{ return 2* Circle::area() + 2 * 3.14159 * radius * height; }
double Cylinder::volume()const
{ return Circle::area() * height; }
// overload <<
ostream & operator<<(ostream & output, const Cylinder & cy)
{
    output<<"Center="<<"["<<cy.x<<","<<cy.y<<"]"
            <<";Radius="<<setiosflags(ios::fixed|ios::showpoint)
            <<setprecision(2)<<cy.radius<<";Height="<<cy.height;
    return output;
}
#endif