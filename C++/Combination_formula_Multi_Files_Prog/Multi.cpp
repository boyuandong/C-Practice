#include<iostream>
using namespace std;

int Multi(int m, int n)
{
    if(m == n)
    {
        return n;
    }
    else{
        return m * Multi(m-1, n);
    }
}

// int main()
// {
//     int m,n;
//     cin>>m>>n;
//     cout<<Multi(m, n)<<endl;
// }