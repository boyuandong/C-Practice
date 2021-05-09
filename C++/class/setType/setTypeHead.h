// setTypeHead.h
#include<iostream>
using namespace std;
class setType
{
    private:
        unsigned *set;  // a pointer to a array
        unsigned n;     // length of array
        unsigned e;     // number of elements in the set
    public:
        setType(unsigned e = 128);  //instructor
        setType(const setType &B);  // copy
        ~setType();                 // destructor
        setType operator+=(unsigned x); // add element x into set
        setType operator=(setType B);   // assign set
        setType operator()(unsigned x=0); // initialize, there are 0 elements in set, and set is empty
        setType operator+(setType B);   // the Union of sets, A V B 
        setType operator*(setType B);   // the Intersection of sets, A ^ B
        setType operator-(setType B);   // the differ form of two sets, A-B
        bool operator<=(setType B);     // determine if A<=B
        bool operator!();               // determine if set is empty, return true if it's empty, otherwise return false
        friend bool operator<(unsigned x, setType A);   // determine if x belongs to set A
        friend ostream & operator<<(ostream & output, setType &A);   // cout<<A;
        friend istream & operator>>(istream & input, setType &A);    // cin>>A;
};