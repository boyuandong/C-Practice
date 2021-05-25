// div_throw.cpp
// This is an example of throw 0 in exception
// 0 can't be a divisor
#include<iostream>
using namespace std;
double Div(double, double);
int main()
{
    double result;
    try
    {
        result = Div(1,2);
        cout<<1<<"/"<<2<<"="<<result<<endl;
        result = Div(5,0);
        cout<<5<<"/"<<0<<"="<<result<<endl;     // find the exception, go to chatch and handle it
        result = Div(10,3);                     // will be interrupted sice the exception above
        cout<<10<<"/"<<3<<"="<<result<<endl;
    }
    catch(double)       // catch and handle exception
    {
        cout<<"Divided by zero."<<endl;
    }
    cout<<"main function is over."<<endl;
    
}
double Div(double a, double b)
{
    if(b==0)    
        throw 0.0;          // when b == 0 arise an exception
    cout<<"Div function is over:"<<endl;
    return a/b;
}