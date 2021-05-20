// open_read.cpp
// This shows an example to open and read the file, and using the data stored in file.
#include <iostream>
#include <fstream>
using namespace std;
// open and read student.txt and display the heighest, lowest, average score of student
void cal_data()
{
    char name[30], s[80];
    int number, score;
    int n = 0, max, min, total = 0;
    double ave;
    ifstream instuf("student_info.txt", ios::in); // open file, read only
    instuf.seekg(0, ios::beg);                    // stream opinter points to the head of file
    if (!instuf)
    {
        cerr << "File could not be open." << endl;
        abort();
    }
    instuf.getline(s, 80);                    // ignore the headline title in the file
    while (instuf >> number >> name >> score) // read and get data and test
    {
        cout << number << '\t' << name << '\t' << score << '\n';
        if (n == 0)
        {
            max = min = score;
        }
        else
        {
            if (score > max)
                max = score;
            if (score < min)
                min = score;
        }
        total += score;
        n++;
    }
    ave = double(total) / n;
    cout << "maximal is: " << max << "\nminimal is: " << min << "\naverage is: " << ave << '\n';
    instuf.close(); // close file
}
// browseFile
void browseFile(char *fileName, int delLine)
{
    ifstream inf(fileName, ios::in);
    char s[80];
    for (int i = 1; i <= delLine; i++) // ignore first delLine rows
        inf.getline(s, 80);
    while (!inf.eof())
    {
        inf.getline(s, 80); // read row by row
        cout << s << endl;  // display row by row
    }
    inf.close();
}
int main()
{
    // read and using the data of a file
    // cal_data();
    // browse a file with skip first few lines
    char *fileName = new char[30];
    int skip_line;
    cout << "Please input the file name: \n";
    cin >> fileName;
    cout << "Please input the number of skip lines: \n";
    cin >> skip_line;
    browseFile(fileName, skip_line);
}