// different_IO_formate.cpp
#include<iostream>
using namespace std;
// define the width of output
void test()
{
    char *s = "Hello";
    cout.fill('*');                 // define fill character
    cout.width(10);                 // define output length
    cout.setf(ios::left);           // left justifying
    cout<<s<<endl;
    cout.width(15);
    cout.setf(ios::right, ios::left);   // clear left justify flag, make it right justify
    cout<<s<<endl;
}
// differnt cardinal number IO
void test2()
{
    int a, b, c;
    cout<<"please input a in decimal: ";        // decimal-10
    cin>>a;
    cout<<"please input b in hexadecimal: ";
    cin.setf(ios::hex, ios::basefield);         // define hex-16 input
    cin>>b;
    cout<<"please input c in octal: ";          
    cin.setf(ios::oct, ios::basefield);         // define octal-8 input
    cin>>c;
    cout.setf(ios::dec, ios::basefield);
    cout<<"Output in decimal:\n";
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
    cout.setf(ios::hex, ios::basefield);        // output as hex base
    cout<<"Output in hexadecimal: \n";
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
    cout.setf(ios::oct, ios::basefield);        // output as oct base
    cout<<"Output in octal: \n";
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
}
// formatting float(decimals) numbers
void test3()
{
    double x = 22.0/7;
    int i;
    cout<<"output in fixed: \n";
    cout.setf(ios::fixed | ios::showpos);       // cout at fixed position, show "+"
    for(i=1; i<5; i++)                          // show in differnt precision
    {
        cout.precision(i);
        cout<<x<<endl;
    }
    cout<<"output inscientific:\n";
    cout.setf(ios::scientific, ios::fixed|ios::showpos);
    // clear above define, and cout in scientific format
    for(i=1; i<5; i++)          // show in different precision
    {
        cout.precision(i);
        cout<<x*1e5<<endl;
    }
}
int main()
{
    // different format of output
    test();
    // IO numbers in different base
    // test2();
    // formatting float(decimals) numbers
    test3();
}