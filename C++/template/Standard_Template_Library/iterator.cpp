// iterator.cpp
// This is an example of using iterator in vector library
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a[] = {1, 3, 5, 7, 9};
    int *p;
    int n = sizeof(a)/sizeof(*a);
    for(p=a; p<a+n; p++)                        // using pointer to visit every ele in vector
        cout<<*p<<"\t";
    cout<<endl;
    vector<int> L(a, a+n);
    vector<int>::iterator t;
    for(t=L.begin(); t!=L.end(); t++)           // using iterator to visit every ele in vector
        *t += 10;
    cout<<endl;
    // define iterator ct
    vector<int>::const_iterator ct;             // const_iterator, read only
    for(ct=L.begin(); ct!=L.end(); ct++)        // using iterator to visit every ele in vector
        cout<<*ct<<"\t";
    cout<<endl;
}