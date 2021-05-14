// Derived.h
#ifndef DERIVED_H
#define DERIVED_H
class Derived: public Base1, public Base2
{
friend ostream & operator<<(ostream & output, const Derived & d);
protected:
    double real;
public:
    Derived(int, char, double); // instructor
    double getReal()const;
};
// instructor
Derived::Derived(int i, char c, double f):Base1(i), Base2(c), real(f) {}
double Derived::getReal()const
{ return real; }
ostream & operator<<(ostream & output, const Derived & d)
{
    output<<"\tInterger:"<<d.value<<"\n\tCharacter:"<<d.letter<<"\n\tReal number:"<<d.real;
    return output;
}
#endif