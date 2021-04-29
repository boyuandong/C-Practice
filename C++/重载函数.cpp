#include<iostream>
using namespace std;
//重载函数 overloaded function
void display(double x){cout<<"a double: "<<x<<"\n";}
void display(int x){cout<<"a int: "<<x<<"\n";}
void display(char x){cout<<"a char: "<<x<<"\n";}
int main()
{
    double a=3.14;
    int b =2;
    char c = 'A';

    cout<<"display(double): \t";
    display(a);
    cout<<"display(int): \t";
    display(b);
    cout<<"display(char): \t";
    display(c);

}