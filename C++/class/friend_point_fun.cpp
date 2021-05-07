/* Friend Function
Calculating the distance between two points by using the friend function
*/
#include<iostream>
#include<cmath>
using namespace std;
class Point
{
private:
    double X, Y;
public:
    Point(double xi, double yi) {X = xi; Y = yi;}
    double GetX() {return X;}
    double GetY() {return Y;}
    friend double Distance(Point &a, Point &b);
};

double Distance(Point &a, Point &b)
{
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dy + dx * dy);
}

double Distance2(Point &a, Point &b)
{
    double dx = a.GetX() - b.GetX();
    double dy = a.GetY() - b.GetY();
    return sqrt(dx * dx - dy * dy);
}
int main()
{
    Point p1(3.0, 5.0), p2(4.0, 6.0);
    double d = Distance(p1, p2);    // Call by friend function
    cout<<"This distance is "<<d<<endl;
    double d2 = Distance2(p1, p2);  // Call by Getters in class
    cout<<"This distance is "<<d2<<endl;    // can not get the private data
    
}
