// vector.cpp
// This is an example of using vector library
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    unsigned int i;
    vector<int> V(10,0);                            // a int type vector length=10, initialize elements=0
    for(i=0; i<10; i++)             
        V[i] = i;                                   // assign the value to elements by operator[] 
    V.push_back(10);                                // add an element=10 at the end of vector V
    V.insert(V.begin()+3, 33);                      // insert an element=33 at index=3 (the 3rd position)
    cout<<"size of V is: "<<V.size()<<endl;         // output length of vector
    cout<<"The elements of V are: ";
    for(i=0; i<V.size(); i++)                       // output elements
        cout<<V[i]<<" ";
    cout<<endl;
    cout<<"The 6th element is: "<<V.at(5)<<endl;    // output element index=5
    cout<<"The first element(use begin()) is: ";
    cout<<*(V.begin())<<endl;                       // output the 1st element
    cout<<"The last element(use rbegin()) is: ";
    cout<<*(V.rbegin())<<endl;                      // last element
    cout<<"The last element(use end()) is: ";
    cout<<*(V.end()-1)<<endl;                       // last element
    cout<<"The last element(use rend()) is: ";
    cout<<*(V.rend()-1)<<endl;                      // first element
    vector<int> L;
    for(i=0; i<V.size(); i++)                       // assign to an vector
        L.push_back(V[i]);
    if(V==L)                                        // determine if two vectors equal
        cout<<"V==L"<<endl;
    else
        cout<<"V!=L"<<endl;
}