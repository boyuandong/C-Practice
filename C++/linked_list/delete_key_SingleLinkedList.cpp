#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};

void ShowList(Node *& head);        // show a single linked list

void insertList(Node *& head, int num);  // insert to create a sorted linked list

void deleteKey(Node *& head, int key); // delete node that data is key

int main()
{
    Node * head = NULL;
    int k;
    int del;
    cout<<"enter data: ";
    cin>>k;
    while (k != 0)          // create a sorted linked list
    {
        insertList(head, k);
        cout<<"enter data: ";
        cin>>k;
    }
    // cout<<head<<"1-------"<<endl;
    ShowList(head);         // show the linked list
    // cout<<head<<"2-------"<<endl;
    cout<<"enter a delete key: ";
    cin>> del;
    while(del !=0 ){
        // cout<<"enter a delete key: ";
        // cin>> del;
        deleteKey(head, del);
        ShowList(head);
        cout<<"enter a delete key: ";
        cin>> del;
    }
    
}

// Show the list
// !!! NOTICE
// Should use a copy instead of using the *head itself
void ShowList(Node *& head)
{
    cout<<"now the items of node are: \n";
    Node *p = head;
    while(p) // while head is not NULL
    {
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
    return;
}

// insert to create a linked list
void insertList(Node *& head, int num)
{
    Node * s, *p, *q;
    s = new Node;
    s->data = num;
    s->next = NULL;
    // If head is empty than insert to create a linked list
    if(head == NULL)
    {
        head = s;
        return;
    }
    // If num is the smallest, then insert to the first to the linked list
    if(s->data < head->data)
    {
        s->next = head;
        head = s;
        return;
    }
    // Search to insert num to a correct position
    for(q=head, p=head->next; p; q=p, p=p->next)
    {
        if(p->data > s->data)
        {
            s->next = p;
            q->next = s;
            return;
        }
    }
    // If num is the greatest, then insert it to the end
    q->next = s;
    return;
}

// delete node that data is key
void deleteKey(Node *& head, int key)
{
    Node *p;
    // If head is empty
    // cout<<head<<"3-------"<<endl;
    if(!head)
    {
        cout<<"List is null!"<<endl;
        return;
    }
    // If key is the head node
    if(head->data == key)
    {
        p = head;
        head = head->next;
        delete p;
        p = NULL;
        cout<<key<<" the head of list have been deleted.\n";
        return;
    }
    // Find the key and delete
    for(Node *q=head; q->next; q=q->next)
    {
        if(q->next->data == key)
        {
            p = q->next;
            q->next = p->next;
            delete p;
            p = NULL;
            cout<<key<<" have been deleted.\n";
            return;
        }
    }
    // there is no key
    cout<<" there is not key: "<<key<<endl;
    return;
}