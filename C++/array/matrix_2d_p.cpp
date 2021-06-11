#include<iostream>
#include<iomanip>
using namespace std;
const int M=5;
int ** gen_matrix(int N);       // generate matrix
void print_matrix(int **x, int N);
int ** gen_new_matrix(int ** a, int n);        // generate a new N-2 matrix
int diagonal_sum(int ** a, int N);
int main()
{

    int ** a = gen_matrix(M);
    cout<<"The genrated NxN matrix is:\n";
    print_matrix(a, M);
    cout<<"----------------------------------"<<endl;
    // generate a new N-2 matrix
    int ** new_matr = gen_new_matrix(a, M);    
    cout<<"The generated new N-2 matrix is:\n";
    print_matrix(new_matr, M-2);
    cout<<"----------------------------------"<<endl;
    // get the sum of diagonal of the matrix
    int sum1 = diagonal_sum(a, M);
    cout<<"The diagonal sum of NxN matrix is: "<<sum1<<endl;
    int sum2 = diagonal_sum(new_matr, M-2);
    cout<<"The diagonal sum of N-2 matrix is: "<<sum2<<endl;   

}


int ** gen_matrix(int N)
{
    /* generate a NxN matrix
    1    1    1    1    1
    2    1    1    1    1
    3    2    1    1    1
    4    3    2    1    1
    5    4    3    2    1
    */
    int ** matrix = new int *[N];
    for(int i=0; i<N; i++)
    {
        // for each row
        matrix[i] = new int[N];
        for(int j=0; j<N; j++)
            matrix[i][j] = 1;
        int x = i;
        for(int k=0; x>=0; k++)
        {
            matrix[i][k] += x;
            x--;
        }
    }

    return matrix;
}

void print_matrix(int **x, int N)
{
    // print matrix
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<setw(5)<<x[i][j];
        }
        cout<<endl;
    }
}

int ** gen_new_matrix(int ** a, int N)
{
    // generate a new N-2 matrix
    int ** new_matr = new int *[N-2];
    for(int i=0; i<N-2; i++)
    {
        new_matr[i] = new int[N-2];
        for(int j=0; j<N-2; j++)
        {
            new_matr[i][j] = a[i+1][j+1];
        }
    }
    
    return new_matr;
    
}

int diagonal_sum(int ** a, int N)
{
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i == j)
                sum += a[i][j];
        }
    }

    return sum;
}