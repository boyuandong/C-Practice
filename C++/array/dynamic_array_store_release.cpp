#include<iostream>
using namespace std;
void App(int * & pa, int n);
int main()
{
    int *ary = NULL, *t;
    int i, n;
    cout<<"n=";
    cin>>n;
    App(ary, n);
    for(t=ary; t<ary+n; t++)
        cout<<*t<<"  ";
    cout<<endl;
    for(i=0; i<n; i++)           // dynamic array assignment
        ary[i] = 10+i;
    for(i=0; i< n; i++)
        cout<<ary[i]<<"  ";     // OR cout<<*ary<<"  ";
    cout<<endl;
    delete []ary;               //release the memory
    ary = NULL;
}
void App(int * & pa, int n)
{
    pa = new int[n];            // dynamically allocated array
    if(pa==NULL)
    {
        cout<<"allocation failure";
        return;
    }
    for(int i=0; i<n; i++)       // initialize the array
        pa[i] = 0;
}