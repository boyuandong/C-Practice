// Main.cpp
#include "BooksHead.h"
// Display all books
void DisplayAll(Books * head);
// BorrowBook according to code, search and delete book from the list
void BorrowBook(Books *head, Books * borrow, int num);
void insertList(Books * borrow, Books * book);     // add a book to borrow list
// RestoreBook according to code, add the book to the front of the list
void RestoreBook(Books * head, Books * borrow);
void deleteList(Books *borrow, Books * p);    // remove from the borrow list


// Display all books
void DisplayAll(Books * head)
{
    Books * p;
    // If there's no books left
    if(!head)
    {
        cout<<"No books left"<<endl;
        return;
    }
    // Otherwise display all of them
    // cout<<"The total number of books is: "<<Books::TotalNumber()<<endl;
    for(p=head; p; p=p->next)
    {
        p->display();
        cout<<"hello";
    }
}
// BorrowBook according to code, search and delete book from the list
void BorrowBook(Books *head, Books * borrow, int num)
{
    Books *q, *p;
    // If no books left
    if(!head)
    {
        cout<<"No books left!"<<endl;
        return;
    }
    // If the head is the borrow book
    if(head->code == num)
    {
        p = head;
        head = head->next;
        cout<<"Borrow this book:\n";
        p->display();
        p->borrow();
        insertList(borrow, p);
        return;
    }
    // Otherwise search and find the books
    for(q=head; q->next; q=q->next)
    {
        if(q->next->code == num)
        {
            p = q->next;
            q->next = p->next;
            cout<<"Borrow this book:\n";
            p->display();
            p->borrow();
            insertList(borrow, p);
            return;
        }
    }
}
// add a book to borrow list
void insertList(Books * head, Books * book)
{
    // if head is null
    if(!head)
    {
        book->next = NULL;
        head = book;
        return;
    }
    //Otherwise insert it to the front of list
    book->next = head->next;
    head = book;
    return;
}
// RestoreBook according to code, add the book to the front of the list
void RestoreBook(Books * head, Books * borrow)
{
    Books *p;
    string bookname;
    int num;
    double price;
    cout<<"Please enter books information: "<<endl;
    cout<<"No.: ";
    cin>>num;
    cout<<"BookName: ";
    cin>>bookname;
    cout<<"price: ";
    cin>>price;
    p = new Books(num, bookname, price);
    p->display();
    // if head is null
    if(!head)
    {
        p->next = NULL;
        head = p;
        p->restore();
        return;
    }
    // Otherwise insert it into the front of the list
    p->next = head->next;
    head = p;
    p->restore();
    return;
    
}
 // remove from the borrow list
void deleteList(Books *borrow, Books * p, Books * head)
{
    // if borrow is null
    if(!borrow)
    {
        cout<<"There is no such a book"<<endl;
        return;
    }
    // if head is the book
    if(borrow->code = p->code)
    {

    }
}  

int main()
{
    Books * head = NULL, *borrow = NULL;
    int choice;
    int num;
    do{
        cout<<"Please choice: "<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.Display all books\n2.Borrow books\n3.Restore books\n0.Over"<<endl;
        cout<<"----------------------"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            DisplayAll(head);
            break;
        }
        case 2:
        {
            cout<<"please input the book code you want to borrow: ";
            cin>>num;
            BorrowBook(head, num);
            break;
        }
        case 3:
        {
            RestoreBook(head);
            break;
        }
        case 0:
            break;
        }
    }while(choice);
}