// Main.cpp
#include<iostream>
#include<cstring>
using namespace std;
#include "Employee.h"
#include "Salesman.h"
#include "Salesmanager.h"
void test()
{
    Employee e("1011568237383201","Li Hua", 2000);
    cout<<e<<endl;
    Salesman s("1011500015383201", "Zhang Qiang",10000);
    cout<<s<<endl;
    Salesmanager m("1011500015012801", "Liu lili", 20000);
    cout<<m<<endl;
}
int main()
{
    test();
}