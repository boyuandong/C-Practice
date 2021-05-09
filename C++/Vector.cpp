// This is a vector class
// practice for operator
#include<iostream>
using namespace std;
class Vector
{
    private:
        int *v;
        int len;
    public:
        Vector(int =1);             // initial len
        Vector(const int *, int);   //instructor by using array
        Vector(const Vector&);      //copy instructor fun
        ~Vector();                  //destructor
        // Overloaded operator
        int & operator[](int i)const;
        int operator()()const;
        Vector & operator=(const Vector &);
        bool operator==(const Vector &)const;
        bool operator!=(const Vector &)const;
        friend Vector operator+(const Vector &, const Vector &);
        friend ostream & operator<<(ostream &output, const Vector &);
        friend istream & operator>>(istream &input, const Vector &);
};
// instructor len of vector, and initial to be 0
Vector::Vector(int size)
{
    if(size<=0 || size>100)
    {
        cout<<"The size of "<<size<<" is fail!\n";
        exit(0);
    }
    v = new int[size];
    for(int i=0; i<size; i++)
        v[i] = 0;
    len = size;
}
// instructor and initialize with an array
Vector::Vector(const int * B, int size)
{
    if(size<=0 || size>100)
    {
        cout<<"The size of "<<size<<" is fail!\n";
        exit(0);
    }
    v = new int[size];
    len = size;
    for(int i=0; i<size; i++)
        v[i] = B[i];
}
// instructor by copy
Vector::Vector(const Vector & A)
{
    len = A();
    v = new int[len];
    for(int i=0; i<len; i++)
        v[i] = A[i];
}
// destructor
Vector::~Vector()
{
    delete []v;
    v = NULL;
    len = 0;
}
// return vector
int & Vector::operator[](int i)const
{
    if(i>=0 && i<len) return v[i];
    cout<<"The subscript "<<i<<" is outside!\n";
    exit(0);
}
// return vector len
int Vector::operator()()const
{
    return len;
}
// assign vector
Vector & Vector::operator=(const Vector & B)
{
    if(len == B())
    {
        for(int i=0; i<len; i++)
            v[i] = B.v[i];
        return *this;
    }
    else
    {
        cout<<"Operator=fail!\n";
        exit(0);
    }
}
// deteremine two vectors equal
bool Vector::operator==(const Vector & B)const 
{
    if(len == B.len)
    {
        for(int i=0; i<len; i++)
        {
            if(v[i] != B.v[i])
                return false;
        }
    }
    else    
        return false;
    return true;
}
// determine two vectors not equal
bool Vector::operator!=(const Vector & B)const 
{
    return !(*this == B);
}
// add two vectors
Vector operator+(const Vector & A, const Vector & B)
{
    int size = A();
    int *T = new int[size];
    if(size == B())
    {
        for(int i=0; i<size; i++)
            T[i] = A.v[i] + B.v[i];
        return Vector(T, size);
    }
    else
    {
        cout<<"Operator+ fail!\n";
        exit(0);
    }
}
// cout vector
ostream & operator<<(ostream &output, const Vector & A)
{
    for(int i=0; i<A(); i++)
        output<<A.v[i]<<" ";        // using the "<<" operator of the system
    return output;
}
// cin vector
istream & operator>>(istream &input, const Vector & A)
{
    for(int i=0; i<A(); i++)
        input>>A.v[i];              // using the ">>" operator of the system
    return input;
}



int main()
{
    int k;
    cout<<"Input the length of Vector: \n";
    cin>>k;
    Vector A(k), B(k), C(k);        // instruct object by length
    cout<<"Input the elements of Vector A:\n";
    cin>>A;
    cout<<"Input the elements of Vector B:\n";
    cin>>B; 
    if(A == B)
    {
        for(int i=0; i<A(); i++)
            C[i] = A[i] * 2;
    }   
    else    C = A + B;
    cout<<" ["<<A<<"]\n+["<<B<<"]\n=["<<C<<"]\n";

}