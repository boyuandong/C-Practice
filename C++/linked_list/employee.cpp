/* This is an employee management system
Having a linked list to store all employees' info:
1. create the linked list and add employess
2. insert employees at the end of linked list
3. count the number of f/m employees
4. delete employee by id
5. delete employee by sex & age
6. Show all employees' info
*/
#include<iostream>
#include<iomanip>
using namespace std;
struct Employee
{
    char name[20];
    unsigned int id;
    unsigned int age;
    char sex;
    Employee * next;
};
int menu();
Employee * Create();                                            // Create/initialize employee list
void ShowList(Employee * head);                                 // Show the list
int Count(Employee *&head, char sex);                           // count the number of employee of one sex
void insert(Employee *& head, Employee * new_e);                 // insert employee to the end of list
void delete_id(Employee *& head);                                // delete employee according to id
Employee * delete_sex_age(Employee *& head);                      // delete employee according to sex & age

int main()
{
    // Employee * head = Create();
    // ShowList(head);
    // delete_id(head);
    // insert(head, Create());     // insert employees
    // ShowList(head);
    // Employee * deleted = delete_sex_age(head);
    Employee * head = NULL;
    while(int option = menu())
    {
        switch (option)
        {
        case 1: //1.create new list   
            head = Create();
            ShowList(head);
            continue;
        case 2: // 2.add new employee    
            insert(head, Create());
            ShowList(head);
            continue;
        case 3:  //3.count employee by sex   
            char sex;
            do{
                cout<<"Count the number of emplpyee (f/m): ";
                cin>>sex;
            }while(sex != 'f' && sex != 'm');
            cout<<"There are "<<Count(head, sex)<<" "<<(sex=='f'?"female":"male")<<" employees in total"<<endl;
            continue;
        case 4:  //4.delete employee by id 
            delete_id(head);
            ShowList(head);
            continue;
        case 5: //5.delete employee by age & sex
            delete_sex_age(head);
            continue;
        case 6: //6.show list 
            ShowList(head);
            continue;

        case 0:
            break;

        default:
            break;
        }
    }
}


int menu()
{
    cout<<"---------------------------------"<<endl;
    cout<<"1.create new list                "<<endl;
    cout<<"2.add new employee               "<<endl;
    cout<<"3.count employee by sex          "<<endl;
    cout<<"4.delete employee by id          "<<endl;
    cout<<"5.delete employee by age & sex   "<<endl;
    cout<<"6.show list                      "<<endl;
    cout<<"0.exit                           "<<endl;
    cout<<"---------------------------------"<<endl;
    int option;
    cin>>option;
    return option;
}


Employee * Create()
{
    // Create a list form the empty start
    // return a head pointer
    Employee * head = NULL, *s;
    char name[20];
    unsigned int id, age;
    char sex;
    Employee *p;
    char add;
    // Keep adding until don't want to
    cout<<"Enter emplyee's info (Y or N): ";
    cin>>add;
    while(add == 'Y' || add == 'y')
    {
        s = new Employee;
        cout<<"name: ";
        cin>>s->name;
        cout<<"id: ";
        cin>>s->id;
        cout<<"age: ";
        cin>>s->age;
        cout<<"sex: ";
        cin>>s->sex;
        s->next = NULL;
        if(!head)
        {
            head = s;
            for(p=head; p->next != NULL; p=p->next);  // p points to the last node in the linked list
        }
        else
            p->next = s;
        p = s;

        cout<<"Enter emplyee's info (Y or N): ";
        cin>>add;
    }

    return head;
}


void ShowList(Employee * head)
{
    // Show the list
    Employee * p;
    cout.setf(std::ios::left);
    // if head is NULL
    if(!head)
    {
        cout<<"Empty"<<endl;
        return;
    }
    for(p=head; p!=NULL; p=p->next)
    {
        cout<<"name: "<<p->name<<setw(5)<<"\tid: "<<p->id<<setw(5)<<"\tage: "<<p->age<<setw(5)<<"\tsex: "<<p->sex<<endl;
    }
}


// count the number of employee of one sex
int Count(Employee *&head, char sex)
{
    // sex can be f/F: female OR m/M: male
    int sum = 0;
    Employee *p = head;
    for(p=head; p!=NULL; p=p->next)
    {
        if(p->sex == sex)
            sum +=1;
    }

    return sum;
}

// insert a new employee OR a list of employee
void insert(Employee *& head, Employee * new_e)
{
    // insert a new employee
    Employee *p;
    //if head is NULL
    if(!head)
    {   
        head = new_e;
        return;
    }
    // if head is not NULL
    for(p=head; p->next; p=p->next);        //p now at the end of list
    p->next = new_e;
    return;
}

// delete a employee according to id
void delete_id(Employee *& head)
{
    int del_id;
    cout<<"Input delete employee id: ";
    cin>>del_id;
    Employee *q, *p;
    // if head is null
    if(!head)
    {
        cout<<"List is NULL."<<endl;
        return;
    }
    // if id is head node
    if(head->id == del_id)
    {
        p = head;
        head = head->next;
        delete p;
        p = NULL;
        return;
    }
    // search id and delete
    for(q=head; q->next != NULL; q=q->next )
    {
        if(q->next->id == del_id)
        {
            p = q->next;
            q->next = p->next;
            delete p;
            p = NULL;
            return;
        }
    }
    // there is no such id
    cout<<"There is no such id"<<endl;
    return;
}

// delete employee accroding to sex & age condition
// and create a deleted list, return
Employee * delete_sex_age(Employee *& head)
{
    Employee * new_head = NULL;
    unsigned int del_age;
    char del_sex;
    // Input conditions
    cout<<"Input delete employee age over: ";
    cin>>del_age;
    cout<<"Input delete employee sex: ";
    cin>>del_sex;
    Employee *q, *p;
    // if head is null
    if(!head)
    {
        cout<<"List is NULL."<<endl;
        return new_head;
    }
    // if is head node
    while(head->sex == del_sex && head->age > del_age)
    {
        p = head;
        head = head->next;
        p->next = NULL;
        insert(new_head, p);
        if(!head)
            goto End;
    }
    // search id and delete
    for(q=head; q->next != NULL; q=q->next )
    {
        while(q->next->sex == del_sex && q->next->age > del_age)
        {
            p = q->next;
            q->next = p->next;
            p->next = NULL;             // clean node next
            insert(new_head, p);        // insert deleted node to new_head
            if(!q->next)                // when search all done the list
                goto End;
        }
    }
    End: cout<<"This is the list after deleted:\n";
    ShowList(head);
    cout<<"This is the deleted employee:\n";
    ShowList(new_head);
    return new_head;
}