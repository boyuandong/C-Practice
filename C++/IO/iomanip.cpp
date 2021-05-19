// iomanip.cpp
// This shows the use of <iomanip>
#include<iostream>
#include<iomanip>
using namespace std;
// simiallar to differentIOformate, show numbers in different base
void test()
{
    int a, b, c;
    cout<<"please input a in decimal: ";
    cin>>dec>>a;
    cout<<"please input b in hexadecimal: ";
    cin>>hex>>b;
    cout<<"please input c in octal: ";
    cin>>oct>>c;
    cout<<"Output in decimal:\n";
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
    cout<<"Output in hexadecimal:\n";
    cout<<hex<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
    cout<<"Output in octal:\n";
    cout<<oct<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
}
// formating output of integer
void test2()
{
    const int k=618;
    cout<<setw(10)<<setfill('#')<<setiosflags(ios::right)<<k<<endl;
    cout<<setw(10)<<setbase(8)<<setfill('*')<<resetiosflags(ios::right)<<setiosflags(ios::left)<<k<<endl;
}
// formatting float(decimals) numbers
void test3()
{
    double x=22.0/7;
    int i;
    cout<<"output in fiexed:\n";
    cout<<setiosflags(ios::fixed|ios::showpos);
    for(i=1; i<5; i++)
        cout<<setprecision(i)<<x<<endl;
    cout<<"output in scientific:\n";
    cout<<resetiosflags(ios::fixed|ios::showpos)<<setiosflags(ios::scientific);
    for(i=1; i<5; i++)
        cout<<setprecision(i)<<x<<endl;
}
int main()
{
    // IO numbers in different base
    // test();
    // formating output of integer
    test2();
    // formatting float(decimals) numbers
    test3();
}