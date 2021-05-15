// PieceWorker.cpp
#include<iostream>
#include<iomanip>
#include "Employee.h"
#include "PieceWorker.h"
using namespace std;
PieceWorker::PieceWorker(const long k, const char * str, const double w, const int q):Employee(k,str)
{
    setWage(w);
    setQuantity(q);
}
void PieceWorker::setWage(double w)
{ wagePerPiece = w>0? w: 0; }
void PieceWorker::setQuantity(int q)
{ quantity = q>0? q: 0; }
double PieceWorker::earnings()const
{ return quantity * wagePerPiece; }
void PieceWorker::print()const
{
    Employee::print();
    cout<<setw(16)<<"Piece Worker\n";
    cout<<"\twagePerPiece "<<wagePerPiece<<"   Quantity "<<quantity;
    cout<<"   earned $"<<earnings()<<endl;
}