// function_exception.cpp
// this is when function arise exception
#include<iostream>
using namespace std;
void fun(int, double);
void test(int, double) throw (int, double);     // arise exception 
const int intMax = 100000;
const double floatMax = 1E12;
int main()
{
    fun(102003, 3.14159);
    fun(5000, 1.2e38);
}
void fun(int k, double x)
{
    try
    {
        test(k, x);
    }
    catch(int)
    {
        cout<<"Interger data is too large."<<endl;
    }
    catch(double)
    {
        cout<<"Float data is too large."<<endl;
    }
    
}
void test(int i, double a) throw (int , double)
{
    if(i>intMax) throw i;
    if(a>floatMax) throw a;
}