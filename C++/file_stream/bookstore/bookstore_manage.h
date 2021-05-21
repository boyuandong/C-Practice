// bookstore_manage.h
// This is minic a bookstore management system
// It can add, modify book outline, and update books info according to purchase and sale
#ifndef BOOKSTORE_MANAGE_H
#define BOOKSTORE_MANAGE_H
#include<iostream>
#include<fstream>
using namespace std;
struct bookData
{
    int TP;                 // book TP
    char bookName[40];      // book name
    long balance;           // the number of balance of the book
};
const bookData mark = {0, "noName\0", 0};   // mark of EOF
void Initial(const char *fileDat);          // initialize for Accounting documents
void Append(const char *fileDat);           // 入库
void Sale(const char *fileDat);             // 销售
void Inquire(const char *fileDat);          // 查询
void CreateTxt(const char*fileDat);         // create txt file
bool endMark(bookData book);                 // determine if it's empty EOF mark of file
#endif