// passing an array to a function by its address
#include<iostream>
#include<iomanip>
using namespace std;
void fun(int [], int);
void fun2(int [], int);
int main()
{
    int i, a[]={1,2,3};
    cout<<"one:";
    for(i=0;i<3;i++)
        cout<<setw(4)<<a[i];
    cout<<endl;
    //fun(a, sizeof(a)/sizeof(int));          //sizeof(a)/sizeof(int) is the length of elements in the array
    fun2(a, sizeof(a)/sizeof(int));   
    cout<<"three:";
    for(i=0;i<3;i++)
        cout<<setw(4)<<a[i];
    cout<<endl;
}
void fun(int x[], int num)
{
    int i;
    for(i=0;i<num;i++)
        x[i]++;
    cout<<"two:";
    for(i=0;i<num;i++)
        cout<<setw(4)<<x[i];
    cout<<endl;
    return;
}

void fun2(int x[], int num)
{
    int i;
    for(i=0;i<num;i++)
        (*x)++, x++;            // the same as x[i]++
    cout<<"two:";
    x = x-num;                  // moving the pointer back to the begining of the array/ first element of array.
    for(i=0;i<num;i++)
        cout<<setw(4)<<*x++;
    cout<<endl;
    return;
}