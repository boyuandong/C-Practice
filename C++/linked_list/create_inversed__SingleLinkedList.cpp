#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};

void CreateList(Node *& head);      // create a single linked list in a reversed order
void ShowList(Node *& head);        // show a single linked list

int main()
{
    Node * head = NULL;
    CreateList(head);
    ShowList(head);
}



void CreateList(Node *& head)
{
    // inverse created a linked list
    Node * s;
    s = new Node;
    cout<<"enter data: ";
    cin>>s->data;
    while(s->data != 0)
    {
        if(head == NULL)    // If head is empty
            s->next = NULL;
        else                // Otherwise
            s->next = head;
        head = s;     
        s = new Node;
        cout<<"enter data: ";
        cin>>s->data;
    }
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