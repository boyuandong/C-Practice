#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char *data;
    int size;
    public:
        String(char *s)
        {
            size = strlen(s);
            data = new char(size+1);
            // strcpy(data,s,size+1);
            strncpy(data, s, size+1);
        }
        operator char*()const   //transfer class fun, from string to char
        {return data;}
};
int main()
{
    String sobj = "hell";
    char *svar = sobj;
    cout<<svar<<endl;
}