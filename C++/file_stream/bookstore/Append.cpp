// Append.cpp
// 入库操作
// if new add a new record at the end of file, otherwise add the number of balance
#include "bookstore_manage.h"
extern const bookData mark;
void Append(const char* fileDat)
{
    char choice;
    bookData book;
    int key;
    long num;
    // open the binary file to read and write
    fstream fdat(fileDat, ios::in|ios::out|ios::binary);
    if(!fdat)
    {
        cerr<<"账目文件不存在，请进行初始化操作。\n";
        return;
    }
    // Append bookes to reacard
    cout<<"************* 入库登记 ***************\n";
    while (1)
    {
        cout<<"请输入操作选择\n1: 新书号\t2: 旧书号\tQ: 退出\n";
        cin>>choice;
        switch (choice)
        {
        case '1':   // add new book record
        {
            fdat.seekg(0, ios::beg);            // points to the begining
            do
            {   // read a record once a time until EOF
                fdat.read((char*)&book, sizeof(bookData));
            } while (!endMark(book));
            // put pointer position to insert the new book data
            fdat.seekp(-long(sizeof(bookData)), ios::cur);
            cout<<"书号(TP)，书名，数量：\n?";
            cin>>book.TP;
            cout<<"?";
            cin>>book.bookName;
            cout<<"?";
            cin>>book.balance;
            fdat.write((char*)&book, sizeof(bookData));      // write the record
            fdat.write((char*)&mark, sizeof(bookData));      // EOF
            break;
        }
        case '2':   // found the old book TP, and update the banance
        {
            fdat.seekg(0, ios::beg);
            cout<<"书号(TP) :\n?";
            cin>>key;
            do
            {   // read record one by one uitl end OR the key is found
                fdat.read((char*)&book, sizeof(bookData));
            } while (book.TP != key && !endMark(book));
            if(book.TP == key)
            {
                cout<<book.TP<<"\t"<<book.bookName<<"\t"<<book.balance<<endl;
                cout<<"入库数量: \n";
                cin>>num;
                if(num > 0)
                    book.balance += num;
                else
                {
                    cout<<"输入数量错误！\n";
                    continue;
                }
                fdat.seekp(-long(sizeof(bookData)), ios::cur);
                // write data modified
                fdat.write((char*)&book, sizeof(bookData));
                cout<<"现存库量：\t\t"<<book.balance<<endl;
            }
            else
                cout<<"书号输入错误！\n";
            break;
        }
        case 'Q':   // quite
        case 'q': return;
        }
    }

    fdat.close();

}