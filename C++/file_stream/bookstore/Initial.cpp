// Initial.cpp
// initialize the accounting file. create a file with only one empty mark record
#include "bookstore_manage.h"
extern const bookData mark;     // global value
void Initial(const char * fileDat)
{
    // write and create a new file
    fstream fdat(fileDat, ios::out|ios::binary);
    cout<<"若账目文件存在， 将删除原有数据，要进行文件初始化吗？（Y/N）\n";
    char answer;
    cin>answer;
    if(answer == 'Y' || answer == 'y')
    {
        fdat.seekp(0, ios::beg);        // move pointer to the beging
        fdat.write((char*)&mark, sizeof(bookData)); // write in empty mark
        cout<<"文件已经初始化。"<<endl;
    }
    else
        cout<<"取消操作"<<endl;
    fdat.close();
}