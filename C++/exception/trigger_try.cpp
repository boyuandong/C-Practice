// trigger_try.cpp
// using the trigger function and try to arise exception
// catch the exception and use trigger's function main to arise exception
#include<iostream>
using namespace std;
void trigger()
{
    try
    { throw "WARING";}
    catch(char * msg)
    {
        cout<<"trigger: Catch_"<<msg<<"_to main"<<endl;
        throw;  // arise exception again
    }
    return;
}
int main()
{
    try
    { trigger(); }
    catch(char * msg)
    {
        cout<<"main_"<<msg<<"_from trigger"<<endl;
    }
}