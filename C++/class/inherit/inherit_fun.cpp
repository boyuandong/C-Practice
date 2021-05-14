// Inherit class with overload function
#include<iostream>
using namespace std;
class A
{
    public:
        int a1, a2;
        A(int i1=0, int i2=0)
        {
            a1 = i1;
            a2 = i2;
        }
        void print()
        {cout<<"a1="<<a1<<"\ta2="<<a2<<endl;}
};
class B: public A 
{
    public:
        int b1, b2;
        B(int j1=1, int j2=1)
        {
            b1 = j1;
            b2 = j2;
        }
        void print()
        {cout<<"b1="<<b1<<"\tb2="<<b2<<endl;}
        void printAB()
        {
            A::print();
            print();
        }
};

int main()
{
    B b;
    b.A::print();       // a1=0    a2=0
    b.print();          // b1=1    b2=1
    b.printAB();        // a1=0    a2=0     b1=1    b2=1
}