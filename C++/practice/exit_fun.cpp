#include<iostream>
using namespace std;

#include<cstdlib>
int main()
{
    int ch;
    puts("Yes or no?");
    ch = getchar();
    puts("\n");
    if(toupper(ch)=='Y')
    {
        puts("Yes.\n");
        exit(1);
    }else{
        puts("No.\n");
        exit(0);
    }
}