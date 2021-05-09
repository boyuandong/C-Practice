//Main.cpp
#include "setTypeHead.h"
int main()
{
    setType setA, setB, setC;
    unsigned x;
    cout<<"Input the elements of setA, 1-128, until input 0:\n";
    cin>>setA;
    cout<<"Input the elements of setB, 1-128, until input 0:\n";
    cin>>setB;
    cout<<"setA="<<setA<<endl;
    cout<<"setB="<<setB<<endl;
    cout<<"Input x: ";
    cin>>x;
    setA += x;
    cout<<"Put "<<x<<" in setA="<<setA<<endl;
    setC = setA + setB;
    cout<<"setC = setA + setB = "<<setC<<endl;
    setC = setA * setB;
    cout<<"setC = setA * setB = "<<setC<<endl;
    setC = setA - setB;
    cout<<"setC = setA - setB = "<<setC<<endl;
    if(setA<=setB)
        cout<<"setA <= setB\n";
    else
        cout<<"not setA <= setB\n";
    cout<<"Input x: ";
    cin>>x;
    if(x<setA)
        cout<<x<<" in"<<setA<<"\n";
    else    
        cout<<x<<" not in"<<setA<<"\n";
    setC = setA + setB + setC;
    cout<<"setC = setA + setB + setC = "<<setC<<endl;
    setC();
    cout<<"setC ="<<setC<<endl;
}