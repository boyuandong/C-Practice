// HourlyWorker.cpp
#include<iostream>
#include<iomanip>
#include "Employee.h"
#include "HourlyWorker.h"
using namespace std;
HourlyWorker::HourlyWorker(const long k, const char * str, double w, int h):Employee(k,str)
{
    setWage(w);
    setHours(h);
}
void HourlyWorker::setWage(double w)
{ wage = (w>0? w: 0); }
void HourlyWorker::setHours(int h)
{ hours =  h>=0&&h<=16*31? h: 0;}
double HourlyWorker::earnings()const
{
    if(hours <= 8*22)                                           // basic salary
        return wage*hours;
    else
        return wage * (8*22) + (hours - 8*22) * wage * 1.5;     // extra earning
}
void HourlyWorker::print()const
{
    Employee::print();
    cout<<setw(16)<<"Hours Worker\n";
    cout<<"\twagePerHour "<<wage<<"   Hours "<<hours;
    cout<<"   earned $"<<earnings()<<endl;
}