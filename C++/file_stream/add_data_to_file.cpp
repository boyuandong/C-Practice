// add_data_to_file.cpp
// This is an example of adding data to the end of the file
#include<iostream>
#include<fstream>
using namespace std;
// append data at the end of file
int Append(char * fileName)
{
    char name[30], ch;
    int number, score;
    ofstream outstuf(fileName, ios::app);       // pointer points to the end of the file
    if(!outstuf)
    {
        cerr<<"File could not be open."<<endl;
        return 0;
    }
    cout<<"Do you want append record to "<<fileName<<"?(Y or N)\n";
    cin>>ch;
    while (ch == 'Y' || ch=='y')            
    {
        cout<<"Inut the number, name, and score:\n";
        cin>>number>>name>>score;
        outstuf<<number<<' '<<name<<' '<<score<<'\n';
        cout<<"?(Y or N)";
        cin>>ch;
        if(ch == 'N' || ch == 'n')
            cout<<"Close file.\n";
    }
    outstuf.close();
    return 1;
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
// copyFile
int copyFile(char * destFile, char *srcFile)
{
    char ch;
    ifstream infile(srcFile, ios::in);          // open sorce file
    ofstream outfile(destFile, ios::out);       // open destination file
    if(!infile)
    {
        cerr<<srcFile<<" : File could not be open."<<endl;
        return 0;
    }
    while (infile.get(ch))          // copy and paste all characters
        outfile.put(ch);
    infile.close();
    outfile.close();
    cout<<"finish!\n";
    return 1;
}
int main()
{
    // append student info at the end of file
    char *fileName = new char[30];
    char * copy_file = new char [30];
    // cout << "Please input the file name: \n";
    // cin >> fileName;
    // Append(fileName);
    // browseFile(fileName, 1);
    // copy file
    cout<<"Please input the file name you want to copy: ";
    cin>>fileName;
    cout<<"Please input the file name you want to paste to: ";
    cin>>copy_file;
    copyFile(copy_file, fileName);
    cout<<"Show original file "<<fileName<<endl;
    browseFile(fileName, 0);
    cout<<"Show copied file "<<copy_file<<endl;
    browseFile(copy_file, 0);
}