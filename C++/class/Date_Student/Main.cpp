// Main.cpp
#include "StudentHead.h"
int main()
{
    Student stu(1985,10,1,1001,"Zhang Hua");
    stu.PrintStudent();     // No.: 1001       name: Zhang Hua birthday: 1985/10/1
    int y, m, d, num;
    char name[20];
    cout<<"modify/set member\nbirthday:";
    cin>>y;
    cout<<"month: ";
    cin>>m;
    cout<<"day: ";
    cin>>d;
    cout<<"code: ";
    cin>>num;
    cout<<"name: ";
    cin>>name;
    stu.SetStudent(y, m, d, num, name);
    stu.PrintStudent(); // No.: num       name: new_name birthday: y/m/d

    Date new_date;
    new_date.PrintDate();   // 2000/1/1

    Student new_stu(2001,01,02,3);
    new_stu.PrintStudent(); // No.: 3  name: no name   birthday: 2001/1/2
}