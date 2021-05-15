// figure.h
// Pure virtual function
#include<iostream>
using namespace std;
class Figure
{
    protected:
        double x, y;
    public:
        void set_dim(double i, double j=0)
        {
            x = i;
            y = j;
        }                                       // Usually Pure Virtual function is in the base class
        virtual void show_area()const = 0;      // This is Pure virtual function, no meaning here, but will be complied in derived class
};
class Triangle : public Figure 
{
    public:
        void show_area()const
        {
            cout<<"Triangle with high "<<x<<" and base "<<y;
            cout<<" has an area of "<<x*y*0.5<<endl;
        }
};
class Square : public Figure 
{
    public:
        void show_area()const
        {
            cout<<"Square with dimension "<<x<<"*"<<y;
            cout<<" has an area of "<<x*y<<endl;            
        }
};
class Circle : public Figure
{
    public:
        void show_area()const
        {
            cout<<"Circle with radius "<<x;
            cout<<" has an area of "<<3.14*x*x<<endl; 
        }
};
