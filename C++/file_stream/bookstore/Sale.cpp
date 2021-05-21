// Sale.cpp
// sale record. Traverse binary file records according to book TP, if found, update banance
#include "bookstore_manage.h"
void Sale(const char * fileDat)
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
    // sale record
    cout<<"************* 销售登记 ***************\n";
    while (1)
    {
        cout<<"请输入操作选择\n1: 销售登记\tQ: 退出\n";
        cin>>choice;
        switch (choice)
        {
        case '1':   // found the old book TP, and update the banance
        {
            fdat.seekp(0, ios::beg);
            cout<<"书号(TP): \n?";
            cin>>key;
            do
            {   // traverse records
                fdat.read((char*)&book, sizeof(bookData));
            } while (key != book.TP && !endMark(book));
            // if found
            if(key == book.TP)
            {
                cout<<book.TP<<"\t"<<book.bookName<<"\t"<<book.balance<<endl;
                cout<<"销售数量: \n?";
                cin>>num;
                if(num>0 && book.balance >= num)
                {
                    book.balance -= num;
                }
                else
                {
                    cout<<"输入数量错误！\n";
                    continue;
                }
                fdat.seekp(-long(sizeof(bookData)), ios::cur);
                fdat.write((char*)&book, sizeof(bookData));
                cout<<"现存库量\t\t"<<book.balance<<endl;
            }
            else
                cout<<"书号输入错误！\n";
            break;
        }
        case 'Q':
        case 'q': return;
        }
    }
    fdat.close();
}