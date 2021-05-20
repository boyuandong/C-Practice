// Append.cpp
// 入库操作
// if new add a new record at the end of file, otherwise add the number of balance
#include "bookstore_manage.h"
extern const bookData mark;
void Append(const char* fileDat)
{
    char choic;
    bookData book;
    int key;
    long num;
    fstream fdat(fileDat, ios::in|ios::out|ios::binary);
    if(!fdat)
    {
        cerr<<""
    }
}