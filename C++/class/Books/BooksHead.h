// BooksHead.hs
#include<iostream>
#include<cstring>
using namespace std;
class Books
{
    private:
        string bookname;
        double price;
        static int total_number;
    public:
        int code;
        Books(int n, string pname, double p);
        void display()const;
        void borrow();      // borrow book
        void restore();     // return the book
        static int TotalNumber();
        Books * next;
};
