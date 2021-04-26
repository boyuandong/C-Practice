#include<iostream>
using namespace std;
int main()
{
    for(int i=100;i<=200;i++)
    {
        if(i%3==2 && i%5==3 && i%7==2)
            cout<<i<<endl;
    }
}