// StudentHead.h
#include<iostream>
#include<cstring>
using namespace std;
// Date Class
class Date
{
    private:
        int year, month, day;
    public:
        Date(int y=2000, int m=1, int d=1);
        void SetDate(int y, int m, int d);
        void PrintDate() const;
};
// Student Class
class Student 
{
    private:
        int code;
        char name[20];
        Date birthday;
    public:
        Student(int y, int m, int d, int num, char *pname="no name");
        void SetStudent(int y, int m, int d, int num, char *pname);
        void PrintStudent() const;
};
