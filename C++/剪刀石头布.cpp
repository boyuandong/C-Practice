#include<iostream>
using namespace std;
//s 剪刀， r 石头， p 布
int win(char p1, char p2)
{
    if(p1=='s')
    {
        switch(p2)
        {
            case 's': return 0;//even
            case 'r': return 2;//p2 win
            case 'p': return 1;//p1 win
        }
    }
    else if(p1=='r')
    {
        switch(p2)
        {
            case 's': return 1;//p1 win
            case 'r': return 0;//even
            case 'p': return 2;//p2 win
        }
    }
    else if(p1=='p')
    {
        switch(p2)
        {
            case 's': return 2;//p2 win
            case 'r': return 1;//p1 win
            case 'p': return 0;//even
        }
    }
    return 3;
}

int main()
{
    char player1,player2;
   do {
        cout<<"player1: \n";
        cin>>player1;
        cout<<"player2: \n";
        cin>>player2;
        switch(win(player1,player2))
        {
            case 1: cout<<"player1 is the winner"<<endl; continue;
            case 2: cout<<"player2 is the winner"<<endl; continue;
            case 0: cout<<"The game is even"<<endl; continue;
            default: cout<<"Error"<<endl; continue;
        }
    }while(player1 && player2);
    
}