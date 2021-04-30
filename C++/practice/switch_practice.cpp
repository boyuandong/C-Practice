#include<iostream>
using namespace std;
double p(int, int);
int main()
{
    int x,n;
    cout<<"n:";
    cin>>n;
    cout<<"x:";
    cin>>x;
    cout<<"p("<<n<<","<<x<<"): "<<p(n,x)<<endl;
}
double p(int n, int x)
{
    switch(n)
    {
        case 0: return 1;
        case 1: return x;
        default: return ((2*n-1)*p(n-1,x) - (n-1)*p(n-1,x))/n;
    }
}