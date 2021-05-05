#include<iostream>
#include<iomanip>
using namespace std;
struct Jonse
{
    int code;
    Jonse * next;
};
Jonse *Create(int);         // create a Jonse circle
void ShowList(Jonse *);     // show the circle list
void Out(Jonse *, int, int);

int main()
{
    Jonse *head;
    int num, val, beg;
    cout<<"\nPlease input the number of total:\n";
    cin>>num;
    head = Create(num);
    ShowList(head);
    cout<<"\nPlease input the code of begin:\n";
    cin>>beg;
    cout<<"\nPlease input interval of counting:\n";
    cin>>val;
    cout<<"The new list is:\n";
    Out(head, beg, val);
}

Jonse *Create(int n)
{
    Jonse *h, *p;
    h = new Jonse;
    p = h;
    for(int i=1; i<=n; i++)
    {
        p->code = i;
        if(i<n)
        {
            p->next = new Jonse;
            p = p->next;
        }
    }
    p->next = h;            // the last one points to the head, make it a circle
    return h;
}

void ShowList(Jonse * h)
{
    Jonse *p=h;
    do{
        cout<<p->code<<"\t";
        p = p->next;
    }while(p!=h);                // keep print the list while not circle end
    cout<<endl;
}

//
void Out(Jonse *h, int i, int d)
{
    Jonse *p=h, *q;
    // q is the ahead pointer, points to the last node created
    for(q=h; q->next !=h; q=q->next);
    // find the begining count position
    for(int k=1; k<i; k++)  
    {
        q = p;
        p = p->next;
    }

    while(p != p->next)         // keeping out, until there is one node left
    {
        for(int k=1; k<d; k++)
        {
            q = p;
            p = p->next;
        }
        cout<<p->code<<"\t";    // Out counted to interval
        q->next = p->next;
        delete p;
        p = NULL;
        p = q->next;
    }

    cout<<p->code<<endl;    // Out the last one node
    delete p;
    p = NULL;

}