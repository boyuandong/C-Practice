// Main.cpp
#include<iostream>
using namespace std;
#include "Base1.h"
#include "Base2.h"
#include "Derived.h"

int main()
{
    Base1 b1(10);
    Base2 b2('k');
    Derived d(5, 'A', 2.5);
    cout<<"Object b1 contains interger: "<<b1.getData()
        <<"\nObject b2 contains character: "<<b2.getData()
        <<"\nObject d contains:\n"<<d<<endl;
    cout<<"Data members of Derived can be accessed in other ways:\n"
        <<"\tInterger:"<<d.Base1::getData()
        <<"\n\tCharacter:"<<d.Base2::getData()
        <<"\n\tReal number:"<<d.getReal()<<endl;

}