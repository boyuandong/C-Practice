//杨辉三角
#include<iostream>
using namespace std;
void yhtriangle(int * const, int);
int main()
{
    int n, *yh;
    do
    {
        cout<<"Please input power:\nn=";        // The number of row
        cin>>n;
    } while (n<0||n>20);
    yh = new int[n+1];                          // dynamic allocate array
    yhtriangle(yh, n);                          //call fun print the yh_tirangle
    delete []yh;                                // release the array
    yh = NULL;
    
}

void yhtriangle(int * const py, int pn)
{
    int i,j,k;
    py[0] = 1;                           // the first row just one elemment 1
    cout<<py[0]<<endl;
    for(i=1;i<pn+1;i++)                 // for each row
    {
        py[i] = 1;                      // the last element is 1
        for(j=i-1; j>0; j--)            // for each col recursive get value (back to front)
            py[j] = py[j-1] + py[j];
        for(k=0; k<=i; k++)             // print row
            cout<<py[k]<<"  ";
        cout<<endl;
    }
}