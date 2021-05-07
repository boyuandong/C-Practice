/* Friend Class
If Class F is a friend of Class A, then all member functions in F are friend of A
*/
#include<iostream>
using namespace std;
class A     //class A
{
    friend class B; // Class B is a friend class of A
    friend class C; // Class C is a friend class
    public:
        void Display() {cout<<X<<endl;}
    private:
        int X;
};

// B having an object of class A
class B     // Class B is a friend of A, can call all properties of A
{
    public:
        void Set(int i)
        {
            Aobject.X = i;
        }
        void Display()
        {
            Aobject.Display();
        }
    private:
        A Aobject;  // A is a private properties of B
};

// C does not need have an object of A to be a friend class of A 
class C
{
    public:
        // Need a A object assignment
        void Set(A & Aobject, int i) {Aobject.X = i;}
        void Display(A & Aobject) {Aobject.Display();}
};

int main()
{
    B Bobject;
    Bobject.Set(100);   // Call Aobject.X
    Bobject.Display(); // Call Aobject.Display()

    C Cobject;
    A Aobject;
    Cobject.Set(Aobject, 200);
    Cobject.Display(Aobject);
}