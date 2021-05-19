// string_stream.cpp
// This is how concatenate the IO to strings
#include<iostream>
#include<sstream>
#include<strstream>
using namespace std;
// using <sstream>
void test(double x, double y)
{
    ostringstream Output;
    Output<<x<<"*"<<y<<"="<<x*y<<endl;      // insert the data
    cout<<Output.str();                     // Output a string
}
// using <strstream>
void test2(double x, double y)
{
    char buf[80];
    ostrstream Output(buf, sizeof(buf));
    Output<<x<<"*"<<y<<"="<<x*y<<endl;      // insert the data
    cout<<buf<<endl;                     // Output a string
}
int main()
{
    double x, y;
    cout<<"Input x: ";
    cin>>x;
    cout<<"Input y: ";;
    cin>>y;
    test(x, y);     // using <sstream>
    test2( x,  y);    // using <strstream>
}