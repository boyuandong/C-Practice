// Non-Virtual desturctor VS. Virtaul destructor
#include<iostream>
using namespace std;
class A
{
    public:
        // ~A()
        virtual ~A()
        {cout<<"A::~A() is called."<<endl;}
};
class B : public A
{
    public:
        ~B()
        {cout<<"B::~B() is called."<<endl;}
};

int main()
{
    A *Ap = new B;
    B *Bp = new B;
    cout<<"delete first object:"<<endl;
    delete Ap;
    Ap = NULL;
    cout<<"delete second object:"<<endl;
    delete Bp;
    Bp = NULL;
    /*
    Non-Virtual:
    delete first object:
    A::~A() is called.
    delete second object:
    B::~B() is called.
    A::~A() is called.
    Virtual:
    delete first object:
    B::~B() is called.
    A::~A() is called.
    delete second object:
    B::~B() is called.
    A::~A() is called.
    */

}
