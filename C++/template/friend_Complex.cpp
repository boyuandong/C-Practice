// This is a usage of template for friend functions in class Complex
#include<iostream>
using namespace std;
template<typename T>
class Complex
{
    private:
        T Real, Image;
    public:
        Complex(T r=0, T i=0);
    // friend functions
    // template<typename T> 
    friend Complex<T> operator+(const Complex<T> c1, const Complex<T> c2);
    // template<typename T> 
    friend Complex<T> operator-(const Complex<T> & c1, const Complex<T> & c2);
    // template<typename T> 
    friend Complex<T> operator-(const Complex<T> & c);
    // template<typename T> 
    friend ostream operator<<(ostream & output, const Complex<T> & c);
};
template<typename T>
Complex<T>::Complex(T r, T i)
{
    Real = r;
    Image = i;
}
template<typename T>
Complex<T> operator+(const Complex<T> c1, const Complex<T> c2)
{
    T r = c1.Real + c2.Real;
    T i = c1.Image + c2.Image;
    return Complex<T>(r, i);
}
template<typename T>
Complex<T> operator-(const Complex<T> & c1, const Complex<T> & c2)
{
    T r = c1.Real - c2.Real;
    T i = c1.Image - c2.Image;
    return Complex<T>(r, i);
}
template<typename T>
Complex<T> operator-(const Complex<T> & c)
{
    return Complex<T>(-c.Real, -c.Image);
}
template<typename T> 
ostream operator<<(ostream & output, const Complex<T> & c)
{
    output<<"("<<c.Real<<","<<c.Image<<")";
    return output;
}

int main()
{
    Complex<double> c1(2.5, 3.7), c2(4.2, 6.5);
    cout<<"c1="<<c1<<"\nc2="<<c2<<endl;
    cout<<"c1+c2="<<c1+c2<<endl;
    cout<<"c1-c2="<<c1-c2<<endl;
    cout<<"-c1="<<-c1<<endl;
}