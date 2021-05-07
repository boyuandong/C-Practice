/* Friend Private Function
Friend of class can caccess all properties of the class, including private member.
*/ A Friend can be a function, a class member function, or another class
#include<iostream>
using namespace std;
class A
{
    private:
        int i;
        friend void FriendFun(A*, int);     // a friend function
    public:
        void MemberFun(int);
};
void FriendFun(A * ptr, int x)          // Friend function access private member of class by pointer 
{
    ptr->i = x;
}

void A::MemberFun(int x)            // Member function access private member by this.pointer 
{
    i = x;
}

int main()
{
    A Aobj;
    FriendFun(&Aobj, 5);        // Call friend function
    Aobj.MemberFun(6);          // call member function
}