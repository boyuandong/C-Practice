// generate a random array to sort
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "sort_head.h"
using namespace std;
int main()
{
    int N=10;
    int i, a[N];
    srand(int(time(0)));
    for(i=0;i<N;i++)
        a[i] = rand()%100;      // initialize the array
    for(i=0;i<N;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    sort(a, N);
    cout<<"Order:"<<endl;
    for(i=0;i<N;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    
}