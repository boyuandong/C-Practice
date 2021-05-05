#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};

void CreateList(Node *& head);      // create a single linked list
void ShowList(Node *& head);        // show a single linked list

int main()
{
    Node * head = NULL;
    CreateList(head);
    ShowList(head);
}



void CreateList(Node *& head)
{
    Node * s, * p;
    s = new Node;
    cout<<"enter data: ";
    cin>>s->data;
    while(s->data != 0)
    {
        if(head == NULL)    // If head is empty
            head = s;       // head points to the new Node 
        else                // Otherwise
            p->next = s;    
        p = s;              // p points to the new Node
        s = new Node;
        cout<<"enter data: ";
        cin>>s->data;
    }
    p->next = NULL;
    delete s;
    s = NULL;
}


void ShowList(Node *& head)
{
    cout<<"now the items of node are: \n";
    while(head) // while head is not NULL
    {
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<endl;
}