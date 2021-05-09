// Access 2-d array
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int i,j,total=0;
    int *p, (*pary)[4];                         // pary is a pointer that points 1-d array contating 4 elements
    for(p=a[0];p<a[0]+12;p++)                   // access 2-d array by accessing 1-d array
    {
        total+=*p;
    }
    cout<<"total = "<<total<<endl;
    for(i=0;i<3;i++)
    {   
        pary = a+i;                             // access row by row
        for(j=0;j<4;j++)
        {
            cout<<setw(4)<<*(*pary+j);          // accesss 2-d array by access pointer (column by column)
        }
        cout<<endl;
        
    }
}