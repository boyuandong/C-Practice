// Base2.h
#ifndef BASE2_H
#define BASE2_H
class Base2
{
protected:
    char letter;
public:
    Base2(char c)
    { letter = c;}
    char getData()const
    { return letter; }
};
#endif