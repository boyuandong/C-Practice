#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};

void ShowList(Node *& head);        // show a single linked list

void insertList(Node *& head, int num);  // insert to create a sorted linked list

int main()
{
    Node * head = NULL;
    int k;
    cout<<"enter data: ";
    cin>>k;
    while (k != 0)          // create a sorted linked list
    {
        insertList(head, k);
        cout<<"enter data: ";
        cin>>k;
    }
    ShowList(head);         // show the linked list
    
}

// Show the list
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
    // If num is the greatest, then insert to the first to the linked list
    if(s->data > head->data)
    {
        s->next = head;
        head = s;
        return;
    }
    // Search to insert num to a correct position
    for(q=head, p=head->next; p; q=p, p=p->next)
    {
        if(p->data < s->data)
        {
            s->next = p;
            q->next = s;
            return;
        }
    }
    // If num is the smallest, then insert it to the end
    q->next = s;
    return;
}