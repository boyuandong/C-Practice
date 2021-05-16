// Array.h
// This is an example of using the template
// Having a class Array of different types
#ifndef ARRAY_H
#define ARRAY_H
template<typename T>        // define the template
class Array
{
protected:
    int size;
    T *element;             // element is T type pointer
public:
    Array(int s);
    virtual ~Array();
    virtual const T & Entry(int index)const;            // get the value of index
    virtual void Enter(int index, const T & value);     // assign element[index] = value
};

template<typename T>Array<T>::Array(int s)  // member function is template function of T type
{
    if(s>1) size = s;
    else    size = 1;
    element = new T[size];
}
template<typename T>Array<T>::~Array()
{
    delete []element;
}
template<typename T>const T&Array<T>::Entry(int index)const
{
    return element[index];
}
template<typename T>void Array<T>::Enter(int index, const T&value)
{
    element[index] = value;
}

#endif