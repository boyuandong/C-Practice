// There are 4 ways to access the array in C++
#include<iostream>
using namespace std;
int main()
{
    int a[]={1,3,5,7,9}, i, *p;
    for(i=0;i<5;i++)
    {
        cout<<"a["<<i<<"]="<<a[i]<<"\t"; // 1. using the index to access the array.
    }
    cout<<endl;
    for(p=a,i=0;i<5;i++)
    {
        cout<<"a["<<i<<"]="<<p[i]<<"\t"; // 2. using the pointer index the access the array.
    }
    cout<<endl;
    for(i=0;i<5;i++)
    {
        cout<<"a["<<i<<"]="<<*(a+i)<<"\t"; // 3. using the pointer to access the array.
    }
    cout<<endl;
    for(p=a;p<a+5;p++)
    {
        cout<<"a["<<(p-a)<<"]="<<*p<<"\t"; // 4. using the pointer variable to access the array.
    }
    cout<<endl;
}