// list.cpp
// This is an example of using list library
#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>
using namespace std;
void createList(list<int>&, int);               // create a list in order
void outList(list<int>&);                       // output the list
void inorderMerge(list<int>&, list<int>);       // mege two lists into one
int main()
{
    list<int> L1, L2;
    srand(int(time(0)));                        // given a random start to produce the random numbers
    createList(L1, 10);                         // Create a list length=10
    cout<<"List L1:\n";
    outList(L1);
    createList(L2, 5);
    cout<<"List L2:\n";
    outList(L2);
    inorderMerge(L1, L2);
    cout<<"List L1:\n";
    outList(L1);
}
// create a list in ascending order
void createList(list<int>& orderList, int len)
{
    int k;
    for(int i=0; i<len; i++)
    {
        k = rand()%100;
        orderList.push_back(k);
    }
    orderList.sort();               // sort in ascending order     
}
// output the list
void outList(list<int>& List)
{
    list<int>::iterator p;
    p = List.begin();
    while(p != List.end())
        cout<<*p++<<" ";
    cout<<endl;
}
// mege two lists into one
void inorderMerge(list<int>&L1, list<int>L2)
{
    L1.merge(L2);   // merge L2 into L1, and keep L1 sorted in ascending order
}