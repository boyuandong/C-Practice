/* C = AxB
A: m x p matrix
B: p x n matrix
C: m x n matrix
*/
#include<iostream>
#include<iomanip>
using namespace std;
const int M=3, P=3, N=2;
int a[M][P], b[P][N], c[M][N] = {0};
bool multimatrix(const int a[M][P], int arow, int acol, const int b[P][N], int brow, int bcol, int c[M][N], int crow, int ccol );
int main()
{
    int i,j;
    cout<<"Please input A:\n";
    for(i=0;i<M;i++)
        for(j=0;j<P;j++)
            cin>>a[i][j];
    cout<<"\nPlease input B:\n";
    for(i=0;i<P;i++)
        for(j=0;j<N;j++)
            cin>>b[i][j];   
    if(multimatrix(a, M, P, b, P, N, c, M, N))
    {
        cout<<"Output C:\n";
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
                cout<<setw(5)<<c[i][j];
            cout<<endl;
        }

    }
    else{
        cout<<"illegal matrix multiply.\n";
    }
}
bool multimatrix(const int a[M][P], int arow, int acol, const int b[P][N], int brow, int bcol, int c[M][N], int crow, int ccol )
{
    if(arow != crow) return false;
    if(acol != brow) return false;
    if(bcol != ccol) return false;
    for(int i=0; i<crow; i++)
    {
        for(int j=0; j< ccol; j++)
        {
            for(int k=0; k<acol; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return true;
}