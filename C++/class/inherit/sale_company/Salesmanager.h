// Salesmanager.h
#ifndef SALESMANAGER_H
#define SALESMANAGER_H
class Salesmanager : public Salesman
{
friend istream &operator>>(istream & input, Salesmanager & e);          // input employee info
friend ostream &operator<<(ostream & output, const Salesmanager & e);   // output employee info
private:
    int jobSalary;
public:
    Salesmanager(const char* i, const char *n, const int s, const int j=3000);
    int pay()const;     // calculate the salary
    void print()const;  // print the salary
};

Salesmanager::Salesmanager(const char* i, const char *n, const int s, const int j): Salesman(i,n,s) 
{
    jobSalary = j;
}
int Salesmanager::pay()const
{ return Salesman::pay() + jobSalary; }
void Salesmanager::print()const
{ cout<<"Salary: "<<pay()<<endl;}

istream &operator>>(istream & input, Salesmanager & e)
{
    cout<<"Please input the Salesmanager's info:\n";
    cout<<"id: ";
    getline(input, e.id);
    cout<<"name: ";
    getline(input, e.name);
    cout<<"sales: ";
    input>>e.sales;
    return input;
}
ostream &operator<<(ostream & output, const Salesmanager & e)
{
    output<<"Salesmanager:\n";
    output<<"id: "<<e.id<<"\tName: "<<e.name<<"\tSalary: "<<e.pay()<<"\tSales: "<<e.sales;
    return output;
}
#endif