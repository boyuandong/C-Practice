// This shows the overload virtaul function properties
#include<iostream>
using namespace std;
class A
{
    public:
        virtual void vf1()
        {cout<<"It is virtaul function vf1() of A."<<endl;};
        virtual void vf2()
        {cout<<"It is virtaul function vf2() of A."<<endl;}
        virtual void vf3()
        {cout<<"It is virtaul function vf3() of A."<<endl;}
        void fun()
        {cout<<"It is common member function A::fun()."<<endl;}
};
class B : public A
{
    public:
        void vf1()          // overload virtual fun
        {cout<<"Virtual function vf1() overloading of B."<<endl;}
        void vf2(int x)     // overload virtual fun with different parameter
        {cout<<"B::vf2() lose virtual character. The parameter is "<<x<<endl;}
        void fun()          // overload non-virtual fun
        {cout<<"It is coommon overloading member function B::fun()."<<endl;}
};

int main()
{
    B b;
    A *Ap = &b;         // Base class pointer points to the inherit class
    Ap->vf1();          // Call B::vf1()
    Ap->vf2();          // Call A::vf2()
    b.vf2(5);           // Call B::vf2()
    Ap->vf3();          // Call A::vf3()
    Ap->fun();          // Call A::fun()
    b.fun();            // Call B::fun()
}