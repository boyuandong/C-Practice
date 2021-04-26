#include<iostream>
using namespace std;
int main()
{
    int nl=0,ng=0;
    char ch;
    cin.get(ch);    //get the first char character
    while(ch!='?')
    {
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') ++nl;
        else if(ch>='0' && ch<='9') ++ng;
        cin.get(ch);
    }
    cout<<"nl="<<nl<<"\t ng="<<ng<<'\n';
    return 0;
}