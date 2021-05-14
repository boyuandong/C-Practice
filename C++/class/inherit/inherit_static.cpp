// visit static value in inherit class
#include<iostream>
using namespace std;
class B
{
    public:
        static void Add()
        { i++; }
        static int i;
        void out()
        {cout<<"static i="<<i<<endl;}
};
int B::i = 0;       // initialize the static value
class D : private B 
{
    public:
        void f();
};
void D::f()
{ 
    i = 5;      // assign i to 5,       i = 5
    Add();      // call for class D function Add() that inherit class B,    i = 6
    B::i++;     // call for value by calss B,   i = 7
    B::Add();   // call for Add() function that from inherit class B,   i = 8
}

int main()
{
    B x;
    D y;
    x.Add();
    x.out();        // static i=1
    y.f();          // i = 8
    cout<<"static i="<<B::i<<endl;         // static i=8
    cout<<"static i="<<x.i<<endl;          // static i=8
    // cout<<"static i="<<y.i<<endl;       // worong !!! i is a private static value of class D, can not call it directally
}