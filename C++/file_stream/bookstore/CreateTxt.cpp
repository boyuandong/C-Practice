// CreateTxt.cpp
// read data from binary file and write them into the booksFile.txt file
// create a txt file, easy to read and print
#include "bookstore_manage.h"
const char * fileTxt = "booksFile.txt";
void CreateTxt(const char * fileDat)
{
    fstream fdat(fileDat, ios::in|ios::binary);
    fstream ftxt(fileTxt, ios::out);
    fdat.seekp(0, ios::beg);
    bookData book;
    cout<<"************* 建立文本文件 ***************\n";
    do
    {
        fdat.read((char*)&book, sizeof(bookData));
        // write the record into txt file
        if(!endMark(book))
            ftxt<<book.TP<<"\t"<<book.bookName<<"\t"<<book.balance<<"\n";
    } while (!endMark(book));
    ftxt.close();
    cout<<"文本文件已经建立，要浏览文件吗？（Y/N）\n";
    char answer, s[80];
    cin>>answer;
    if(answer == 'Y' || answer == 'y')
    {
        ftxt.open(fileTxt, ios::in);
        while (!ftxt.eof())
        {
            ftxt.getline(s, 80);
            cout<<s<<endl;
        }
        ftxt.close();
    }
    fdat.close();
}
