// Base1.h
#ifndef BASE1_H
#define BASE1_H
class Base1
{
protected:
    int value;
public:
    Base1(int x)
    { value = x;}
    int getData()const
    { return value; }
};
#endif