#include<iostream>
using namespace std;
// Three ways transfer the value through function
int tripleByValue(int x){return 3*x;}
int tripleByReference(int & x){return 3*x;} 
int tripleByPointer(int * x ){return 3*(*x);}
// Three ways transfer the value through function By changing the value itself
int PlusByValue(int x){return x++;}             //will only make a copy of the value, not change the value itself
int PlusByReference(int & x){return x++;}       //will change the value itself
int PlusByPointer(int * x ){return (*x)++;}     //will change the value itself
int main()
{ 
    int x;
    cout<<"Please enter an integer:";
    cin>>x;
    cout<<"tripleByValue(x): "<<tripleByValue(x)<<"\t x:"<<x<<endl;
    cout<<"tripleByReference(x): "<<tripleByReference(x)<<"\t x:"<<x<<endl;
    cout<<"tripleByPointer(&x): "<<tripleByPointer(&x)<<"\t x:"<<x<<endl;
    cout<<"\n";
    cout<<"PlusByValue(x): "<<PlusByValue(x)<<"\t x:"<<x<<endl;
    cout<<"PlusByReference(x): "<<PlusByReference(x)<<"\t x:"<<x<<endl;
    cout<<"PlusByPointer(&x): "<<PlusByPointer(&x)<<"\t x:"<<x<<endl;
}