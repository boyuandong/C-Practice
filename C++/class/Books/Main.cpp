// Main.cpp
#include "BooksHead.h"
// Display all books
void DisplayAll(Books *& head);
// BorrowBook according to code, search and delete book from the list
void BorrowBook(Books *& head, Books *& borrow, int num);
void insertList(Books *& head, Books *& book);     // add a book to borrow list
// RestoreBook according to code, add the book to the front of the list
void RestoreBook(Books *& head, Books *& borrow, int num);
Books * deleteList(Books *& head, int num);    // remove from the list


// Display all books
void DisplayAll(Books *& head)
{
    Books * p;
    // If there's no books left
    if(!head)
    {
        cout<<"No books left!"<<endl;
        return;
    }
    // Otherwise display all of them
    // cout<<"The total number of books is: "<<Books::TotalNumber()<<endl;
    for(p=head; p; p=p->next)
    {
        p->display();
    }
    return;
}
// BorrowBook according to code, search and delete book from the list
void BorrowBook(Books *& head, Books *& borrow, int num)
{
   Books * p = deleteList(head, num);   // search delete the book from the book list
   if(p)   
   {
        p->next = NULL;
        insertList(borrow, p);   // insert it into borrow book list
        p->borrow();
        p->display();
        return;
   }
   //Otherwise there is no such a book
   cout<<"There is no such a book!"<<endl;
   return;

}
// add a book to borrow list
void insertList(Books *& head, Books *& book)
{
    // if head is null
    if(!head)
    {
        book->next = NULL;
        head = book;
        return;
    }
    //Otherwise insert it to the front of list
    book->next = head;
    head = book;
    return;
}
// RestoreBook according to code, add the book to the front of the list
void RestoreBook(Books *& head, Books *& borrow, int num)
{
    // delete the book from the borrow list 
    Books * p = deleteList(borrow, num);
    // if p is exist in borrow list
    if(p)
    {
        p->next = NULL;
        // insert the book into the book list
        insertList(head, p);
        p->restore();
        return;
    }
    // Otherwise add the new book
    int n;
    
    double price;
    string pname, dummy;
    cout<<"This is the new book to add in the book list:\n";
    cout<<"Book code: ";
    cin>>n;
    getline(cin,dummy);
    cout<<"Book name: ";
    getline(cin, pname);
    /* Notice !!!
    without getline(cin, dummy);
    The name did not print because the getline saw the newline character \n left 
    from the cin>> as whitespace and stopped reading any further.
    Method 1: avoid put getline after cin>>
    Method 2:   getline(cin, dummy);
    Consume the trailing newline character from the cin>> before calling getline, 
    by "grabbing" it and putting it into a "dummy" variable.
    OR
    Method 3:   cin.ignore(100,'\n');
    skips up to 100 characters stopping after it finds and "grabs" \n
    */
    cout<<"Book price: ";
    cin>>price;
    Books * s  = new Books(n, pname, price);
    s->next = NULL;
    insertList(head, s);
    return;

}
 // remove from the linked list, and remove the book pointer
Books * deleteList(Books *& head, int num)
{
    Books * p = NULL;
    // if head is null
    if(!head)
    {
        cout<<"There is no such a book!\n";
        return p;
    }
    // if head is the book
    if(head->code == num)
    {
        p = head;
        head = head->next;
        return p;
    }
    // Otherwise search and delete the node
    for(Books * q=head; q->next; q=q->next)
    {
        if(q->next->code == num)
        {
            p = q->next;
            q->next = p->next;
            return p;
        }
    }

    return p;
}  

int main()
{
    Books * head = NULL, * borrow = NULL;
    int choice;
    int num;
    do{
        cout<<"Please choice: "<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.Display all books\n2.Borrow books\n3.Restore books\n4.Show total nuber of books\n5.Show lend books\n0.Over"<<endl;
        cout<<"----------------------"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1: // Display books in library
        {
            DisplayAll(head);
            continue;
        }
        case 2: // borrow a book by its code
        {
            cout<<"please input the book code you want to borrow: ";
            cin>>num;
            BorrowBook(head, borrow, num);
            continue;
        }
        case 3: // restore a book by its code
        {
            cout<<"please input the book code you want to restore: ";
            cin>>num;
            RestoreBook(head, borrow, num);
            continue;
        }
        case 4: // check the number of books in library
            cout<<"There are in total "<<Books::TotalNumber()<<" books left in library."<<endl;
            continue;
        case 5: // display books lended
            DisplayAll(borrow);
            continue;
        case 0: // exit
            break;
        }
    }while(choice);
}