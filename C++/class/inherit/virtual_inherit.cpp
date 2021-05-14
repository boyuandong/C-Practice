// This is an example of virtual inherit
#include<iostream>
using namespace std;
// Base class B
class B
{
    public:
        B() {cout<<"Constructor called: B "<<endl; }
        ~B() { cout<<"Destructor called: B "<<endl; }
        int b;
};
// class B1 inherit B
class B1: virtual public B
{
    public:
        B1() {cout<<"Constructor called: B1 "<<endl; }
        ~B1() { cout<<"Destructor called: B1 "<<endl; }
        int b1;
};
// class B2 inherit B
class B2: virtual public B 
{
    public:
        B2() {cout<<"Constructor called: B2 "<<endl; }
        ~B2() { cout<<"Destructor called: B2 "<<endl; }
        int b2;
};
// class D inherit B1 and B2
class D: public B1, public B2
{
    public:
        D() {cout<<"Constructor called: D "<<endl; }
        ~D() { cout<<"Destructor called: D "<<endl; }
        int d;
};

void test()
{
    D dd;                   // Constructor B, B1, B2, D
    dd.B1::b = 5;           // !!! Notice, b of B1, and b of B2 are the same one
    dd.B2::b = 10;          // There are only one B when inherit, B1 and B2 are inherit the same B
    dd.b1 = 25;
    dd.b2 = 100;
    dd.d = 140;
    cout<<"dd.B1::b="<<dd.B1::b<<"\ndd.B2::b="<<dd.B2::b<<endl;
    cout<<"dd.b1="<<dd.b1<<"\ndd.b2="<<dd.b2<<"\ndd.d="<<dd.d<<endl;
}

int main()
{
    test();                 // Destructor D, B2, B1, B
}
