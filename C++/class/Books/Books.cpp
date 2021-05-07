// Books.cpp
#include "BooksHead.h"
int Books::total_number = 0;
// instructor
Books::Books(int n, string name, double p)
{
    code = n;
    bookname = name;
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
// void Books::display(Books * head)const
// {
//     Books * p;
//     // If having no books
//     if(Books::TotalNumber() == 0)
//     {
//         cout<<"No books"<<endl;
//     }
//     else    // Otherwise
//     {
//         cout<<"The total number of books: "<<Books::TotalNumber()<<endl;
//         for(p=head; p; p=p->next)
//         {
//             cout<<"No.: "<<p->code<<"\tbook name: "<<p->bookname<<"\tprice: "<<p->price<<endl;
//         }
//     }
// }
// borrow books
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