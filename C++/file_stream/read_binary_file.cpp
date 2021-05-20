// read_binary_file.cpp
// read data from students.dat file and calculate display the data
#include<iostream>
#include<fstream>
using namespace std;
struct student                              // define the sturct
{
    int number;
    char name[30];
    int score;
};
// read and show data from the .dat file
void readBinaryFile()
{
    student stu;
    int n=0, max, min, total=0;
    double ave;
    ifstream instuf("students.dat", ios::in);       // open binary file
    if(!instuf)
    {
        cerr<<"File could not be open.\n";
        abort();
    }
    do
    {
        instuf.read((char*)&stu, sizeof(student));      // read the first record
        if(stu.number!=0)
        {
            cout<<stu.number<<" "<<stu.name<<" "<<stu.score<<"\n";
            if(n==0)
                max = min = stu.score;
            else
            {
                if(stu.score > max) max = stu.score;
                if(stu.score < min) min = stu.score;
            }
            total += stu.score;
            n++;
        }
    }while(instuf && stu.number!=0);
    cout<<"Total people: "<<n<<endl;
    ave = double(total)/n;
    cout<<"max: "<<max<<"\nmin: "<<min<<"\naverage: "<<ave<<endl;
    instuf.close();
}
int main()
{
    // read and show data from the .dat file
    readBinaryFile();
}


