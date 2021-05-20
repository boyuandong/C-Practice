// modify_binary.cpp
// This is an example of create, modify, and output the binary data files
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int i,j;
    fstream f;                                          // declare stream object
    // create file, and open it to write
    f.open("DATA.dat", ios::out|ios::binary);
    for(i=1; i<=10; i++)
        f.write((char *)&i, sizeof(int));               // wirte the i value into file
    f.close();
    // modify file, open it to read/write 
    f.open("DATA.dat", ios::in|ios::out|ios::binary);
    // traverse 10 data in file
    for(i=0; i<10; i++)
    {
        f.seekg(long(sizeof(int) * i));                 // moving the pointer
        f.read((char *)&j, sizeof(int));                // read data that pointer point to, and write it into j
        if(j%2)                                         // if j is odd number
        {
            j += 10;                                    // change the value of j
            f.seekp(-long(sizeof(int)), ios::cur);      // stream pointer point to the position
            f.write((char *)&j, sizeof(int));           // write it into new data
        }
    }
    f.seekg(long(sizeof(int)*10));                      // moving pointer to the EOF
    for(i=91; i<=95; i++)                               // adding 5 more data
        f.write((char *)&i, sizeof(int));               // write i value into file
    // output file data
    f.seekg(0, ios::beg);                               // move pointer to the head of file
    for(i=0; i<15; i++)
    {
        f.read((char*)&j, sizeof(int));                 // read the data and write the value to j
        cout<<j<<" ";                                   // show the value of j
    }
    cout<<endl;
    f.close();
    // output: 11 2 13 4 15 6 17 8 19 10 91 92 93 94 95 
}