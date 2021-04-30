#include<iostream>
#include "Combination_formula.h"
using namespace std;
// run below to compile:
// g++ main.cpp Fabricate.cpp Multi.cpp
int main()
{
    int m, n;
    cout<<"try to calculate the number of combinations pick m out of n"<<endl;
    cout<<"m:\t";
    cin>>m;
    cout<<"n:\t";
    cin>>n;
    cout<<"There are total "<<Fabricate(m,n)<<" different combinations."<<endl;
}