// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
friend istream &operator>>(istream & input, Employee & e);          // input employee info
friend ostream &operator<<(ostream & output, const Employee & e);   // output employee info
protected:
    string id;
    string name;
    int basicSalary;
public:
    Employee(const char* i, const char *n, const int b=2000);
    int pay()const;     // calculate the salary
    void print()const;  // print the salary
};

Employee::Employee(const char* i, const char *n, const int b)
{
    id = i;
    name = n;
    basicSalary = b;
}
int Employee::pay()const
{ return basicSalary; }
void Employee::print()const
{
    cout<<"Salary: "<<pay()<<endl;
}
// input employee info
istream &operator>>(istream & input, Employee & e)
{
    cout<<"Please input the Employee's info:\n";
    cout<<"id: ";
    getline(input, e.id);
    cout<<"name: ";
    getline(input, e.name);
    return input;
}        
// output employee info
ostream &operator<<(ostream & output, const Employee & e)
{
    output<<"Employee:\n";
    output<<"id: "<<e.id<<"\tName: "<<e.name<<"\tSalary: "<<e.pay();
    return output;
}  
#endif