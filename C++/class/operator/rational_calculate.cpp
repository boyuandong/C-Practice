#include<iostream>
using namespace std;
class Rational
{
    private:
        int Numberator, Denominator;
    public:
        Rational();                 // instructor
        Rational(int n, int d=1);   // instructor
        Rational(double x);         // instructor
        operator double();          // transfer class to double
        friend Rational operator+(const Rational &, const Rational &);      // overload +
        friend ostream & operator<<(ostream &, const Rational &);           // overload <<
};
int gcd(int a, int b);  // 求最大公约数
// instructor
Rational::Rational()
{Numberator = 0; Denominator = 0;}
// instructor
Rational::Rational(int n, int d)
{
    int g;
    if(d==1)        //分母等于1
    {
        Numberator = n;
        Denominator = d;
    }
    else            //分母不等于1的有理数
    {
        g = gcd(n,d);       //求分子分母最大公约数
        Numberator = n/g;   //约分  
        Denominator = d/g;
    }
}
// instructor
Rational::Rational(double x)
{
    int a,b,g;
    a = int(x*1e5);
    b = int(1e5);
    g = gcd(a,b);
    Numberator = a/g;
    Denominator = b/g;
}
// transfer class to double
Rational::operator double()
{return double(Numberator)/double(Denominator);}
// overload +
Rational operator+(const Rational & r1, const Rational & r2)
{
    int n, d;
    n = r1.Numberator*r2.Denominator + r1.Denominator*r2.Numberator;
    d = r1.Denominator*r2.Denominator;
    return Rational(n, d);
}
// overload <<
ostream & operator<<(ostream & output, const Rational & x)
{
    output<<x.Numberator;
    if(x.Denominator!=1) output<<"/"<<x.Denominator;
    return output;
}
// 求最大公约数
int gcd(int a, int b)
{
    int g;
    if(b==0) g=a;
    else g=gcd(b,a%b);
    return g;
}

int main()
{
    Rational a(2,4);
    Rational b=0.3;
    Rational c = a+b;
    cout<<double(a)<<"+"<<double(b)<<"="<<double(c)<<endl;
    cout<<a<<"+"<<b<<"="<<c<<endl;
    double x = b;
    c = x + 1 + 0.6;
    cout<<x<<"+"<<1<<"+"<<0.6<<"="<<double(c)<<endl;
    cout<<Rational(x)<<"+"<<Rational(1)<<"+"<<Rational(0.6)<<"="<<c<<endl;

}