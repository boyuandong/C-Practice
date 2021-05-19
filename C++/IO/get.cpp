// get.cpp
// The is an example of using get to IO
/* There are 3 ways of using get
    (1) int get();
    get a character from input (including blank space) and use it to return.
    return EOF when file end.
    (2) istream & get(char &rch);
    get a character and rewrite it into rch. return 0 when end, otherwise return istream&
    (3) istream & get(char *pch, int nCount, char delim='\n');
    read nCount number of character OR read until '\n', and write them into pch and add '\0' at the end.
    * istream& getline(char *pch, int nCount, char delim='\n');
    * istream &read(char *pch, int nCount);
*/
#include<iostream>
using namespace std;
int main()
{
    char c;
    // (1)
    cout<<"Enter first sentence followed by Enter\n";
    while((c = cin.get()) != '\n')
        cout.put(c);
    cout<<endl;
    // (2)
    cout<<"Enter second sentence followed by Enter\n";
    while(cin.get(c))
    {
        if(c=='\n') break;
        cout.put(c);
    }
    cout<<endl;
    // (3) 
    cout<<"Enter third sentence followed by Enter\n";
    char s[80];
    cin.get(s, 10);
    cout<<s<<endl;
}