#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void sort_string(string * name);        // sort the string
void my_replace(string str);             // replace all the char to another
int main()
{
    // 1. Sort string
    string name[5] = {"Li Hua", "He Xiao Ming", "Boyuan Dong", "Alpha Hou", "Zoey Liu"};
    sort_string(name);
    for(int i=0; i<5; i++)
        cout<<"name["<<i<<"]="<<name[i]<<endl;

    cout<<"1.-----------"<<endl;
    
    // 2. replace all the "," to ";"
    string alphabet = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z";
    my_replace(alphabet);
    cout<<"2.-----------"<<endl;
    
    // 3. Change the Date format
    cout<<"Enter the date in American format"<<"(eg., December 25, 2020):\n";
    string Date;
    getline(cin, Date, '\n');            // input the first line of string
    int i= Date.find(" ");              // find the first black space aftering get the month
    string Month = Date.substr(0,i);
    int k= Date.find(",");              // find the "," after the date
    string Day = Date.substr(i+1, k-i-1);
    string Year = Date.substr(k, Date.size()-1);
    string NewDate = Day + " "+ Month + " " + Year;
    cout<<"Original date: "<<Date<<endl;
    cout<<"Converted Date: "<<NewDate<<endl;
    cout<<"3.-----------"<<endl;

    // 4. Convert string to char[]
    string s("StringObject");
    int len = s.length();
    char *ptr1 = new char[len+1];       // new char []
    strcpy(ptr1,  s.data());            //copy string data to char[]
    char *ptr2 = new char[len+1];       // new char []
    strcpy(ptr2,  s.c_str());           //copy string to char[]
    cout<<"string is: "<<s<<endl;
    cout<<"ptr1 is: "<<ptr1<<endl;
    cout<<"ptr2 is: "<<ptr2<<endl;
    delete []ptr1;                      // release char []
    delete []ptr2;                      // release char []
    ptr1 = NULL;
    ptr2 = NULL;
    cout<<"4.-----------"<<endl;

}

void sort_string(string * name)
{
    string s;
    int i,j,k;
    for(i=0; i< 4; i++)
    {
        k=i;
        for(j=i+1; j<5; j++)
        {
            if(name[i]>name[j])
                k=j;
        }
        if(k!=j){
            s = name[k];
            name[k] = name[i];
            name[i] = s;
        }
    }

    return;
}

void my_replace(string str)
{
    int x = str.find(",");
    while(x<string::npos)
    {
        str.replace(x,1,";");
        x = str.find(",", x+1);
    }
    cout<<str<<endl;
    return;
}