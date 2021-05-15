// Employee.cpp
#include<iostream>
#include<cstring>
#include<iomanip>
#include "Employee.h"
using namespace std;
Employee::Employee(const long k, const char * str)
{
    number = k;
    strncpy(name, str, 20);
}
Employee::~Employee()
{ name[0]='\0';}
const char * Employee::getName()const
{ return name;}
const long Employee::getNumber()const
{ return number;}
void Employee::print()const
{cout<<number<<setw(20)<<name;}