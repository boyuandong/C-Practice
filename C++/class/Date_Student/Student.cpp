// Student.cpp
#include "StudentHead.h"
// initialize by class constructor, can initialize birthday directly
Student::Student(int y, int m, int d, int num, char *pname):birthday(y,m,d)
{
    code = num;
    strncpy(name, pname, sizeof(name));
    name[sizeof(name)-1] = '\0';
}
// SetStudent function 
void Student::SetStudent(int y, int m, int d, int num, char *pname)
{
    code = num;
    strncpy(name, pname, sizeof(name));
    name[sizeof(name)-1] = '\0';
    birthday.SetDate(y, m, d);
    cout<<name<<'\n';
}
// PrintStudent function, read only
void Student::PrintStudent()const
{
    cout<<"No.: "<<code<<"\tname: "<<name<<"\tbirthday: ";
    birthday.PrintDate();
    cout<<endl;
}