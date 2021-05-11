#include<iostream>
#include<cmath>
using namespace std;
class RMB
{
    private:
        int yuan, jiao, fen;
        bool mark;
    public:
        RMB();                              // instructor
        RMB(int y, int j, int f, bool m);   // instructor
        RMB(double x);                      // instructor
        operator double();                  // transfer class to double
        friend ostream & operator<<(ostream & output, const RMB & a);
        friend istream & operator>>(istream & input, RMB & a);
};
// instructor
RMB::RMB()
{yuan = 0; jiao = 0; fen = 0; mark = true;}
// instructor
RMB::RMB(int y, int j, int f, bool m)
{
    yuan = y;
    jiao = j;
    fen = f;
    mark = m;
}
// instructor
RMB::RMB(double x)
{
    if(x>0)   mark = true;
    else    mark = false;
    x = fabs(x);
    int temp = int(x*1e2);
    yuan = temp/100;
    jiao = (temp%100) / 10;
    fen  = temp%10;
}
// transfer class to double
RMB::operator double()
{
    double x=0;
    x += yuan;
    x += jiao * 1e-1;
    x += fen * 1e-2;
    if(mark)    return x;
    else        return -x;
}
ostream & operator<<(ostream & output, const RMB & a)
{
    if(a.mark) output<<"+"<<a.yuan<<"元"<<a.jiao<<"角"<<a.fen<<"分";
    else output<<"-"<<a.yuan<<"元"<<a.jiao<<"角"<<a.fen<<"分";
    return output;
}
istream & operator>>(istream & input, RMB & a)
{
    int y, j, f;
    input>>y;
    input>>j;
    input>>f;
    if(y>0)
    {
        a.mark = true;
        a.yuan = y;
    }
    else
    {
        a.mark = false;
        a.yuan = -y;
    }
    a.jiao = j;
    a.fen = f;
    return input;

}

int main()
{
    RMB a, b;
    double c;
    cout<<"a: \n"; cin>>a;
    cout<<"b: \n"; cin>>b;
    cout<<"c: \n"; cin>>c;
    cout<<"a="<<a<<"\tb="<<b<<"\tc="<<RMB(c)<<endl;
    cout<<"a+c="<<RMB(a+c)<<endl;
    cout<<"a-b="<<RMB(a-b)<<endl;
    cout<<"b*2="<<RMB(b*2)<<endl;
    cout<<"a*0.5="<<RMB(a*0.5)<<endl;
}