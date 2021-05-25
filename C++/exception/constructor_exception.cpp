// constructor_exception.cpp
// Array object constructor arise exception
#include<iostream>
using namespace std;
const int maxSize = 1000;
template<typename T>
class Array
{
protected:
    int size;
    T * element;
public:
    Array(int s);
    virtual ~Array();
};
template<typename T>
Array<T>::Array(int s)
{
    if(s<1 || s>maxSize) throw s;
    else element = new T[size];
}
template<typename T>
Array<T>::~Array()
{
    size = 0;
    delete []element;
}
// a function to catch and handle the exception
void create()
{
    int size;
    try
    {
        cout<<"Input the size of Array: ";
        cin>>size;
        Array<int> IntAry(size);        // using the Int type as an example
    }
    catch(int s)
    {
        cout<<"Size Error!"<<endl;
    }
    
}

int main()
{
    create();
}
