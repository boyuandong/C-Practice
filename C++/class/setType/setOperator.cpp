// setOperator.cpp
#include "setTypeHead.h"
//instructor
setType::setType(unsigned e)
{
    n = (e+31)/32;
    set = new unsigned[n];
    for(unsigned i=0; i<n; i++)
        set[i] = 0;
}
//copy
setType::setType(const setType & B)
{
    n = B.n;
    e = 32*n;
    set = new unsigned[n];
    for(unsigned i=0; i <n; i++)
        set[i] = B.set[i];
}
//destructor
setType::~setType()
{
    delete []set;
    n = 0;
    e = 0;
}
// add element x into set
setType setType::operator+=(unsigned x)
{
    unsigned bitMask = 1;
    bitMask <<= ((x-1)%32 );
    set[(x-1)/32] |= bitMask;
    return *this;
}

// assign set
setType setType::operator=(setType B)
{
    for(unsigned i=0; i<n; i++)
        set[i] = B.set[i];
    return *this;
}
// initialize, there are 0 elements in set, and set is empty
setType setType::operator()(unsigned x)
{
    unsigned bitMask = 1;
    for(unsigned i=0; i<n; i++)
        set[i] = 0;
    if(x)
    {
        bitMask<<=((x-1)%32);
        set[(x-1)%32] |= bitMask;
    }
    return *this;
}
// the Union of sets, A V B 
setType setType::operator+(setType B)
{
    setType T(32*n);
    for(unsigned i=0; i<n; i++)
        T.set[i] = set[i] | B.set[i];
    return T;
}
// the Intersection of sets, A ^ B
setType setType::operator*(setType B)
{
    setType T(32*n);
    for(unsigned i=0; i<n; i++)
        T.set[i] = set[i] & B.set[i];
    return T;   
}
// the differ form of two sets, A-B
setType setType::operator-(setType B)
{
    setType T(32*n);
    for(unsigned i=0; i<n; i++)
        T.set[i] = set[i] & (~(set[i] & B.set[i]));
    return T;   
} 
// determine if A<=B
bool setType::operator<=(setType B)
{
    for(unsigned i=0; i<n; i++)
    {
        if( (set[i] | B.set[i]) != B.set[i])
            return false;
    }
    return true;
}    
// determine if set is empty, return true if it's empty, otherwise return false
bool setType::operator!()
{
    for(unsigned i=0; i<n; i++)
    {
        if(set[i])
            return false;
    }
    return true;
}              
// determine if x belongs to set A
bool operator<(unsigned x, setType A)
{
    unsigned bitMask = 1;
    bitMask <<=((x-1)%32);
    if(A.set[(x-1)/32] & bitMask)
        return true;
    return false;
}
// cout<<A;
ostream & operator<<(ostream & output, setType & A)
{
    unsigned c, i;
    unsigned bitMask;
    if(!A)
    {
        output<<"{ }";
        return output;
    }
    output<<"{";
    for(i=0; i<A.n; i++)
    {
        bitMask = 1;
        for(c=1; c<=32; c++)
        {
            if(A.set[i] & bitMask)
                output<<i*32+c<<", ";
            bitMask<<=1;
        }
    }
    output<<"\b\b }";
    return output;
}
// cin>>A;
istream & operator>>(istream & input, setType & A)
{
    unsigned x;
    input>>x;
    while(x){
        A += x;
        input>>x;
    }
    return input;
} 
