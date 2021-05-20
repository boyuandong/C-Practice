// student_file.cpp
// create a file including student info in "student_info.txt"
// can create other files using this code
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char fileName[30], name[30];
    int number, score;
    ofstream outstuf;       // create output_file_stream object
    cout<<"Please input the name of students file:\n";
    cin>>fileName;          // input the file name
    outstuf.open(fileName, ios::out);   // connect to file and open file for write
                                        // ios::in is for read only
    if(!outstuf)                        // call overload function test stream
    {
        cerr<<"File could not be open."<<endl;
        abort();
    }   
    outstuf<<"This is a file of students\n";                // write the headline title
    cout<<"Input the number, name, and score"<<"(Enter Ctrl+D to end input)\n? ";
    while(cin>>number>>name>>score)
    {
        outstuf<<number<<' '<<name<<' '<<score<<'\n';         // input data for filestream
        cout<<"? ";
    }
    outstuf.close();                                        // close the file
}