//get a number and print tiangle tower
#include <iostream>
using namespace std;
void print_empty(int e)
{//print empty space
    for(int i=0;i<e;i++)
    {
        cout<<" ";
    }
}

void print_ch(int i, char a)
{//print character
    for(int j=0;j<i;j++)
    {
        cout<<a;
    }
}

int main()
{
    int num;
    char ch;
    cout<<"How many lines? \t";
    cin>>num;
    cout<<"What character? \t";
    cin>>ch;
    //print line by line
    for(int i=1;i<=num;i++)
    {
        print_empty(num-i);
        print_ch(2*i-1,ch);
        print_empty(num-i);
        cout<<endl;
    }
}

