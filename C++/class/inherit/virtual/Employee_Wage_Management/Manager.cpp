// Manager.cpp
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include "Employee.h"
#include "Manager.h"
using namespace std;
Manager::Manager(const long k, const char * str, const double sal):Employee(k,str)
{ setMonthlySalary(sal); }
void Manager::setMonthlySalary(double sal)
{ monthlySalary = (sal>0? sal: 0);}
double Manager::earnings()const
{ return monthlySalary; }
void Manager::print()const
{
    Employee::print();
    cout<<setw(16)<<"Manager\n";
    cout<<setw(20)<<"   earned $"<<earnings()<<endl;
}