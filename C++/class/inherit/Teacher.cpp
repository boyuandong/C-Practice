// This is making use of inherit to create a Teacher class by inheriting Person
#include<iostream>
#include<cstring>
using namespace std;
// class Person
class Person
{
    private:
        string name;
        string idNumber;
    public:
        Person(const char *n, const char *i)    //Constructor
        {
            name = n;
            idNumber = i;
        }
        void Print()const
        { cout<<"Name: "<<name<<"\n\tidNumber: "<<idNumber<<endl;}
};
// Teacher class
class Teacher : private Person
{
    private:
        string title;
        int wage;
    public:
        Teacher(const char*n, const char *i, const char *t, const int w):Person(n,i)
        {
            title = t;
            wage = w;
        }
        void print()const
        {
            Person::Print();
            cout<<"\tTitle: "<<title<<"\tWage: "<<wage<<endl;
        }
};


int main()
{
    Person p("张少华", "420106196611070538");
    Teacher t("李若山", "420106196611247168", "教授", 5000);
    p.Print();
    t.print();
}
