// Inquire.cpp
// search
#include "bookstore_manage.h"
void Inquire(const char * fileDat)
{
    char choice;
    bookData book;
    int key;
    // open the binary file to read and write
    fstream fdat(fileDat, ios::in|ios::out|ios::binary);
    if(!fdat)
    {
        cerr<<"账目文件不存在，请进行初始化操作。\n";
        return;
    }
    // search
    cout<<"*************** 查询 *****************\n";
    while (1)
    {
        cout<<"请输入操作选择\n1: 按书号查询\t2: 浏览\tQ: 退出\n";
        cin>>choice;
        switch (choice)
        {
        case '1':
        {
            fdat.seekg(0, ios::beg);
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
            }
            else
            {
                cout<<"书号输入错误！\n";
                continue;
            }
            break;
        }
        case '2':
        {
            fdat.seekg(0, ios::beg);
            do
            {
                fdat.read((char*)&book, sizeof(bookData));
                if(!endMark(book))
                    cout<<book.TP<<"\t"<<book.bookName<<"\t"<<book.balance<<endl;
            } while (!endMark(book));
            break;
        }
        case 'Q':
        case 'q': return;
        }
    }
    fdat.close();
}