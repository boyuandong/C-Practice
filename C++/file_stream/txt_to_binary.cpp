// txt_to_binary.cpp
// read data from student_info.txt file and rewrite them into students.dat file
#include<iostream>
#include<fstream>
using namespace std;
struct student                              // define the sturct
{
    int number;
    char name[30];
    int score;
};
const student mark = {0, "noName\0", 0};    // empty record, mark of EOF
int main()
{
    char s[80];
    student stu;
    ifstream instuf("student_info.txt", ios::in);               // read txt file
    ofstream outf("students.dat", ios::out|ios::binary);    // write binary file
    if(!instuf | !outf)
    {
        cerr<<"File could not be open.\n";
        abort();
    }
    instuf.getline(s, 80);                                  // ignore the headline
    // read and get data from txt file
    while (instuf>>stu.number>>stu.name>>stu.score)
    {
        cout<<stu.number<<"\t"<<stu.name<<"\t"<<stu.score<<"\n";
        outf.write((char*)&stu, sizeof(student));           // write into binary .dat file
    }
    outf.write((char*)&mark, sizeof(student));              // write mark of EOF into .dat file
    instuf.close();
    outf.close();
}


