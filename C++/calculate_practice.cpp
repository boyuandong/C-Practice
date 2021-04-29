#include<iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int menu1();
int menu2();
void calculate(int, int);
int random_num(int );
int main()
{
    int level, type;
    level = menu1();
    while(level != 0)
    {
        do
        {
            type = menu2();
            calculate(level, type);
        }while(type!= 0);

        level = menu1();

    }

}


int menu1()
{   int x;
    cout<<"-------------------------"<<endl;
    cout<<"|    Choose the level   |"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|1. easy                |"<<endl;
    cout<<"|2. medium              |"<<endl;
    cout<<"|3. hard                |"<<endl;
    cout<<"|0. quit                |"<<endl;
    cout<<"-------------------------"<<endl;
    cin>>x;
    return x;
    cout<<system("clear");
    // cout << "\033[2J\033[1;1H";

}
int menu2()
{   
    int x;
    cout<<"-------------------------"<<endl;
    cout<<"|    Choose the typle   |"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"|1. +                   |"<<endl;
    cout<<"|2. -                   |"<<endl;
    cout<<"|3. *                   |"<<endl;
    cout<<"|4. /                   |"<<endl;
    cout<<"|0. quit                |"<<endl;
    cout<<"-------------------------"<<endl;
    cin>>x;
    return x;
    cout<<system("clear");
    // cout << "\033[2J\033[1;1H";


}

void calculate(int level, int type)
{
    int x, y;
    int answer;
    x = random_num(level);
    y = random_num(level);
    switch (type)
    {
    case 1:
        do{
            cout << x << "+" << y << "=";
            cin >> answer;
        }while(answer != (x + y));
        cout<<"Correct!\n";
        break;

    case 2:
        do{
            cout << x << "-" << y << "=";
            cin >> answer;
        }while(answer != (x - y));
        cout<<"Correct!\n";
        break;

    case 3:
        do{
            cout << x << "*" << y << "=";
            cin >> answer;
        }while(answer != (x * y));
        cout<<"Correct!\n";
        break;

    case 4:
        do{
            cout << x << "/" << y << "=";
            cin >> answer;
        }while(answer != int (x / y));
        cout<<"Correct!\n";
        break;

    default:
        break;
    }
}

int random_num(int level)
{   
    int multiplier=15273, increment=13849, modulus=65536;
    int ran_num;
    ran_num = (multiplier * rand() + increment ) % modulus;
    return ran_num % (int) pow(10, level);

}