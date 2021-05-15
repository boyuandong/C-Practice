// This is shows how the nonvirtual and virtual inherit class used as base pointer
#include<iostream>
using namespace std;
class Base
{
    protected:
        char x;
    public:
        Base(char xx)   {x = xx;}
        // void who()  {cout<<"Base class: "<<x<<endl; }
        virtual void who()  {cout<<"Base class: "<<x<<endl; }   // This is a virtual function
};
class First_d : public Base 
{
    protected:
        char y;
    public:
        First_d(char xx, char yy):Base(xx)   {y = yy;}
        void who()  {cout<<"First derived class: "<<x<<","<<y<<endl; }      // When Base is virtual function, then this is also virtual
};

class Second_d : public First_d 
{
    protected:
        char z;
    public:
        Second_d(char xx, char yy, char zz):First_d(xx,yy)   {z = zz;}
        void who()  {cout<<"Second derived class: "<<x<<","<<y<<","<<z<<endl; }    // When Base is virtual function, then this is also virtual
};

int main()
{

    Base B_obj('A');
    Base *p;
    First_d F_obj('T','O');
    Second_d S_obj('E','N','D');
    p = &B_obj;
    p->who();                   // Non-Virtual Base class: A;               Virtual: Base class: A
    p = &F_obj;
    p->who();                   // Non-Virtual: Base class: T;              Virtual: First derived class: T, O
    p = &S_obj; 
    p->who();                   // Non-Virtual: Base class: E;              Virtual: Second derived class: E,N,D
    F_obj.who();                // First derived class: T, O
    ((Second_d *) p)->who();    // Second derived class: E,N,D
    ((First_d *) p)->who();     // Non-Virtual First derived class: E,N;    Virtaul: Second derived class: E,N,D
    ((Base *) p)->who();        // Non-Virtual Base class: E;               Virtaul: Second derived class: E,N,D
}