// This is a safe calculator/counter
// using the operator of class ++, --, and ()
#include<cstdlib>
#include<iostream>
using namespace std;
class Calculator
{
    private:
        unsigned int value;
    public:
        Calculator() {value = 0;}
        void operator++();
        void operator--();
        unsigned int operator()()const;
};
void Calculator::operator++()
{
    if(value<65535)
        ++value;
    else
    {
        cout<<"\nData overflow !"<<endl;
        abort();
    }
}
void Calculator::operator--()
{
    if(value>0) --value;
    else{
        cout<<"\nData overflow !"<<endl;
        abort();
    }
}
unsigned int Calculator::operator()()const
{
    return value;
}

int main()
{
    Calculator Counter;
    int i;
    for(i=0; i<5; i++)
    {
        ++Counter;
        cout<<"\nCounter = "<<Counter();
    }
    cout<<endl;
    for(i=0; i<=5; i++)
    {
        --Counter;
        cout<<"\nCounter = "<<Counter();
    }
}