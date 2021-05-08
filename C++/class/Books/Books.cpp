// Books.cpp
#include "BooksHead.h"
int Books::total_number = 0;
// instructor
Books::Books(int n, string pname, double p)
{
    code = n;
    bookname = pname;
    price = p;
    total_number += 1;
}
// get the total number of books
int Books::TotalNumber()
{return Books::total_number;}
// display all books
void Books::display()const
{
    cout<<"No."<<code<<"\tbookname: "<<bookname<<"\tprice: "<<price<<endl;
}
void Books::borrow()
{
    // total number -1
    total_number -= 1;
    cout<<"Now the total number of books is: "<<Books::TotalNumber()<<endl;
}

// restore books
void Books::restore()
{
    // total number +1
    total_number += 1;
    cout<<"Now the total number of books is: "<<Books::TotalNumber()<<endl;
}