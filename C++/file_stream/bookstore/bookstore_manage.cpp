// bookstore_manage.cpp
// create main menu and choos option
#include "bookstore_manage.h"
const char *fileDat = "booksFile.dat";
int main()
{
    char choice;
    while(1)
    {
        cout<<"************ 书库管理 *************\n请输入操作选择\n"
            <<"1: 入库\t2: 售出\t3: 查询\t4:  建立文本\t0: 初始化\tQ: 退出\n";
        cin>>choice;
        switch (choice)
        {
        case '1':
            Append(fileDat);
            break;
        case '2':
            Sale(fileDat);
            break;
        case '3':
            Inquire(fileDat);
            break;
        case '4':
            CreateTxt(fileDat);
            break;
        case '0':
            Initial(fileDat);
            break;
        case 'q':
        case 'Q':
            cout<<" 退出系统\n";
            return 0;
        default:
            cout<<"输入错误， 请再输入\n";
        }
    }
}