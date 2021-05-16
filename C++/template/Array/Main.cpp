// Main.cpp
// test() is for the Array class for different type T
// test2() is for BoundArray class, inherit Array class with check the index safty for different type T
#include<iostream>
#include<stdlib.h>
#include "Array.h"
#include "BoundArray.h"
using namespace std;
template<typename T>                           // Template Name
void Tfun(const Array<T> &x, const int index)   // Having a template funcion call Array object
{cout<<x.Entry(index)<<"\t";}
void test()
{
    // Int type
    Array<int> IntAry(5);
    for(int i=0; i<5; i++)
        IntAry.Enter(i, i);
    cout<<"Integer Array:\n";
    for(int i=0; i<5; i++)
        cout<<IntAry.Entry(i)<<"\t";
    cout<<endl;
    // double type
    Array<double> DouAry(5);
    for (int i = 0; i < 5; i++)
        DouAry.Enter(i, (i+1)*0.35);
    cout<<"Double Array:\n";
    for (int i = 0; i < 5; i++)
        cout<<DouAry.Entry(i)<<"\t";
    cout<<endl;
    // char type
    Array<char> ChaAry(5);
    for(int i=0; i<5; i++)
        ChaAry.Enter(i, i+65);
    cout<<"Char Array:\n";
    for(int i=0; i<5; i++)
        Tfun(ChaAry, i);        // Call the template function
    cout<<endl;    
}

void test2()
{
    int low=1, height=10;
    // Int type
    BoundArray<int> IntB(low, height);
    for(int i=low; i<=height; i++)
        IntB.Enter(i, i*2);
    cout<<"Integer BoundArray:\n";
    for(int i=low; i<=height; i++)
    {
        cout<<"IntB["<<i<<"]="<<IntB.Entry(i)<<"\t";
        if(i%5==0)
            cout<<endl;
    }
    cout<<endl;
    // Char type
    BoundArray<char> ChaB(low, height);
    for(int i=low; i<=height; i++)
        ChaB.Enter(i, i+65);
    cout<<"Char BoundArray:\n";
    for(int i=low; i<=height; i++)
    {
        cout<<"ChaB["<<i<<"]=";
        Tfun(ChaB, i);                      // Call the T template function
        if(i%5==0)  cout<<endl;
    }
    cout<<endl;


}
int main()
{
    // test();
    test2();
}