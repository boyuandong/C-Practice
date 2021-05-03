#include<iostream>
using namespace std;
const int N=2;
// Different ways of passing 2d array

//1. Pass by (value) a pointer to the decayed type
void outputAry(int (*x)[N], int N, int k);                        
void inputAry(int (*x)[N], int);

//2. pass by reference
void outputAry_reference(int x[][N], int k);                   
void inputAry_reference(int x[][N]);                   

//3. pass by pointer
void outputAry_pointer(int *x[N], int k);                     
void inputAry_pointer(int *x[N]); 

//4. pass by pointer to a pointer
void outputAry_2_pointer(int **x, int N, int k);        
void inputAry_2_pointer(int **x, int N);

int main()
{
    int ary[N][N], k;
    inputAry(ary, N);
    cout<<"inputer the row number, k=";
    cin>>k;
    outputAry(ary, N, k-1);             //1. pass by value
    cout<<"-------------"<<endl;
    outputAry_reference(ary, k-1);      //2. pass by reference
    cout<<"-------------"<<endl;
    int *array[N];
    for(int i = 0; i < N; i++)
        array[i] = new int[N];
    inputAry_pointer(array);            //3. pass by pointer
    outputAry_pointer(array, k-1); 

    cout<<"-------------"<<endl;
    int **array2;
    array2 = new int *[N];
    for(int i = 0; i <N; i++)
        array2[i] = new int[N];
    inputAry_2_pointer(array2, N);            //4. pass by pointer to a pointer
    outputAry_2_pointer(array2,  N,  k-1); 

    cout<<"-------------"<<endl;

}


//1. Pass by (value) a pointer to the decayed type
void outputAry(int (*x)[N], int n, int k)
{   cout<<"output array by value"<<endl;
    for(int i=0; i<n; i++)
        cout<<x[k][i]<<" ";
    cout<<endl;
}

void inputAry(int (*x)[N], int n)
{   // input the matrix
    cout<<"input array by value"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>x[i][j];
    }
}

//2. pass by reference
void outputAry_reference(int x[][N], int k)
{   cout<<"output array pass by reference"<<endl;
    for(int i=0; i<N; i++)
        cout<<x[k][i]<<" ";
    cout<<endl;
}
void inputAry_reference(int x[][N])
{   cout<<"input array pass by reference"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cin>>x[i][j];
    }
}

//3. pass by pointer
void outputAry_pointer(int *x[N], int k)
{   cout<<"output array pass by pointer"<<endl;
    for(int i=0; i<N; i++)
        cout<<x[k][i]<<" ";
    cout<<endl;
}

void inputAry_pointer(int *x[N])
{   cout<<"input array pass by pointer"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cin>>x[i][j];
    }
}

//4. pass by pointer to a pointer
void outputAry_2_pointer(int **x, int N,  int k)
{   cout<<"output array pass by pointer of pointer"<<endl;
    for(int i=0; i<N; i++)
        cout<<x[k][i]<<" ";
    cout<<endl;
}

void inputAry_2_pointer(int **x, int N)
{   cout<<"input array pass by pointer of pointer"<<endl;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cin>>x[i][j];
    }
}