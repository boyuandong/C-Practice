// password.cpp
// handle multiple exceptions for the password
#include<iostream>
using namespace std;
int test(char *p, double e, int a)
{
    int f=1;        // error flag
    try
    {
        if(*p>='0'&& *p<='9') throw char (*p);      // first character in password can't be number
        if(e<0 || e>20000) throw e;                 // earnings must be 0~20000
        if(a<18 || a>70) throw a;                   // age must be 18~70
    }
    catch(char s)       // catch error for password
    {
        f = 0;
        cout<<"password error: "<<s<<endl;
    }
    catch(double e)     // catch error for earnings
    {
        f = 0;
        cout<<"earnings error: "<<e<<endl;
    }
    catch(int a)        // catch error for age
    {
        f = 0;
        cout<<"age error: "<<a<<endl;
    }
    catch(...)          // catch any type error
    {
        f = 0;
        cout<<"error!"<<endl;
    }
    return f;
}

int main()
{
    char password[8];
    double earnings;
    int age;
    cout<<"input password, earnings, age:\n";
    cin>>password>>earnings>>age;
    if(test(password, earnings, age))
        cout<<password<<" "<<earnings<<" "<<age<<endl;
}