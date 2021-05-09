#include<iostream>
using namespace std;
//n 个金片会从A移到C，以B为过渡, 且只能小的在大的上面，一次移动一片
void Move(int n, char a, char b, char c)
{
    if(n==1)//只有一个金片
        cout<<a<<"-->"<<c<<endl;
    else//否则
    {
        Move(n-1, a, c, b);//把n-1个金片从a移到b，以c为过渡
        cout<<a<<"-->"<<c<<endl;//从a移一个金片到c
        Move(n-1, b, a, c);//把n-1个金片从b移到c，以a为过渡
    }
}
int main()
{
    int m;
    cout<<"Input the number of disks:"<<endl;
    cin>>m;
    Move(m,'A','B','C');
}