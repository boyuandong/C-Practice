// Salesman.h
#ifndef SALESMAN_H
#define SALESMAN_H
class Salesman : public Employee
{
friend istream &operator>>(istream & input, Salesman & e);          // input employee info
friend ostream &operator<<(ostream & output, const Salesman & e);   // output employee info
protected:
    int sales;
public:
    static double commrate;
    Salesman(const char* i, const char *n, const int s);
    int pay()const;     // calculate the salary
    void print()const;  // print the salary
};
double Salesman::commrate = 0.005;
Salesman::Salesman(const char* i, const char *n, const int s):Employee(i,n)
{
    sales = s;
}
int Salesman::pay()const
{ return Employee::pay() + sales * commrate; }
void Salesman::print()const
{ cout<<"Salary: "<<pay()<<endl; }
istream &operator>>(istream & input, Salesman & e)
{
    cout<<"Please input the Salesman's info:\n";
    cout<<"id: ";
    getline(input, e.id);
    cout<<"name: ";
    getline(input, e.name);
    cout<<"sales: ";
    input>>e.sales;
    return input;
}
ostream &operator<<(ostream & output, const Salesman & e)
{
    output<<"Salesman:\n";
    output<<"id: "<<e.id<<"\tName: "<<e.name<<"\tSalary: "<<e.pay()<<"\tSales: "<<e.sales;
    return output;
}
#endif
