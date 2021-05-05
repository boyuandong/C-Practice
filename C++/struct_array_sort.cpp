#include<iostream>
using namespace std;
struct person
{
    char name[10];
    unsigned int id;
    double salary;
};
void Input(person[], const int);
void Sort(person[], const int);            // Sort the array itself
void Output(const person[], const int);     // Output the array itself
void Sort(person*[], const int);            // Sort the index array that stored array's address
void Output(person * [], const int);     // Output the index array that stored array's address
int main()
{
    person allone[100];
    person * index[100];            // get an index array 
    for(int i=0; i<100; i++)        // sort each element address in allone array
    {
        index[i] = allone + i;
    }
    int total;
    cout<<"Please enter the number of employee: ";
    cin>>total;
    cout<<"Please Enter employee's information: \n";
    Input(allone, total);
    cout<<"Sort the employees according to the amount of salary\n";
    Sort(allone, total);
    cout<<"Output the employees' information after sorted\n";
    Output(allone, total);
    cout<<"\nSort the employee's index according to salary: \n";
    Sort(index, total);
    cout<<"Output the employees' information after sorted\n";
    Output(index, total);

}

// Input info for each person
void Input(person all[], const int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<i<<": name: ";
        cin>>all[i].name;
        cout<<"id: ";
        cin>>all[i].id;
        cout<<"salary: ";
        cin>>all[i].salary;
        cout<<endl;
    }
}

// Sort the array itself according to the salary
void Sort(person all[], const int n)
{
    person temp;
    // bubble sort
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(all[j].salary > all[j+1].salary)         // sort according to salary
            {
                temp = all[j];
                all[j] = all[j+1];
                all[j+1] = temp;
            }
        }
    }
}

// Output the sorted array itself
void Output(const person all[], const int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<i<<": name: "<<all[i].name<<" id: "<<all[i].id<<" salary: "<<all[i].salary<<endl;
    }
}

// Sort the index array that stored array's address
void Sort(person * pi[], const int n)
{
    person *temp;               // get a struct pointer store the address while exchanging/sorting
    // bubble sort
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(pi[j]->salary > pi[j+1]->salary)     // sort according to salary, can also use (* pi[j]).salary
            {
                temp = pi[j];
                pi[j] = pi[j+1];
                pi[j+1] = temp;
            }
        }
    }
}

// Output the index array that stored array's address
void Output(person * pi[], const int n)
{
    // !!!
    // notice:  here need to call the pointer address to get data, here pointer cannot be const
    for(int i=0; i<n; i++)
    {
        cout<<i<<": name: "<<pi[i]->name<<" id: "<<pi[i]->id<<" salary: "<<pi[i]->salary<<endl;
    }
}