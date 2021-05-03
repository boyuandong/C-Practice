#include<iostream>
using namespace std;
int main()
{
    char *s = new char[80];     // dynamic allocated string array
    cin>>s;
    cout<<s;
    delete []s;
    s = NULL;
    cout<<"\n1.----------"<<endl;

    char * str = "My name";         // Using the pointer
    for(int i=3; i<7; i++)
        cout<<*(str+i);         // The same as cout<<str[i];
    cout<<"\n2.----------"<<endl;

    char *name[5] = {"Li Hua", "He Xiao Ming", "Boyuan Dong", "Alpha Hou", "Zoey Liu"};
    for(int i=0; i<5; i++)
        cout<<name[i]<<endl;
    cout<<"3.----------"<<endl;

    // String assignment 字符串赋值
    char str1[10] = "computer", str2[10], *sp;
    int i=0;
    while(str1[i]){
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    sp = str1;
    cout<<str1<<endl<<str2<<endl<<sp<<endl;
    sp = "new string";
    cout<<sp<<endl;
    cout<<"4.----------"<<endl;
}