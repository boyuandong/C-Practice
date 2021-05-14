// Main.cpp
#include<iostream>
#include<iomanip>
using namespace std;
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
int main()
{
    Point p(72, 115);
    cout<<"The initial location of p is "<<p<<endl; // The initial location of p is [72,115]
    p.setPoint(10, 10);
    cout<<"\nThe new location of p is "<<p<<endl;   // The new location of p is [10,10]
    Circle c(2.5, 37, 43);
    cout<<"\nThe initial location and radius of c are\n"<<c<<endl;  // Center=[37,43];Radius=2.5
    c.setRadius(4.25);
    c.setPoint(2, 2);
    cout<<"\nThe new location and radius of c are\n"<<c<<"\nArea="<<c.area()<<"\n"; // Center=[2,2];Radius=4.25 Area=56.745
    Cylinder cyl(5.7, 2.5, 12, 23);
    cout<<"\nThe initial location, radius and height of cyl are\n"<<cyl // Center=[12,23];Radius=2.50;Height=5.70Area=128.81
        <<"\nArea="<<cyl.area()<<"\nVolume="<<cyl.volume()<<endl;     // Area=128.81   Volume=111.92
    return 0;
}