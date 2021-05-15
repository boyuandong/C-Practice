// Main.cpp
// test() is to test the classes objs
// test2() create a list combined with different types of objects by making using the base pointer
// test3() can create a linked list
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
#include "Employee.h"
#include "Manager.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"
void test()
{
    cout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2);
    Manager m1(10135,"Cheng ShaoHua", 1200);
    Manager m2(10201, "Yan HaiFeng");
    m2.setMonthlySalary(5300);
    HourlyWorker hw1(30712, "Zhao XiaoMing", 5, 8*20);
    HourlyWorker hw2(30649, "Gao DongSheng");
    hw2.setWage(4.5);
    hw2.setHours(10*30);
    PieceWorker pw1(20382, "Xiu LiWei", 0.5, 2850);
    PieceWorker pw2(20469, "Huang Donglin");
    pw2.setWage(0.75);
    pw2.setQuantity(1850);
    // Using the pointer, call derive class functions
    Employee *basePtr;
    basePtr = &m1;
    basePtr->print();
    basePtr = &m2;
    basePtr->print();
    basePtr = &hw1;
    basePtr->print();
    basePtr = &hw2;
    basePtr->print();
    basePtr = &pw1;
    basePtr->print();
    basePtr = &pw2;
    basePtr->print();
}

// can also create a lst that connected different class by making using of the Base Pointer
void test2()
{
    
    Employee * employee[6];
    employee[0] = new Manager(10135,"Cheng ShaoHua", 1200);
    employee[1] = new Manager(10201, "Yan HaiFeng", 5300);
    employee[2] = new HourlyWorker(30712, "Zhao XiaoMing", 5, 8*20);
    employee[3] = new HourlyWorker(30649, "Gao DongSheng");
    ((HourlyWorker*) employee[3])->setWage(4.5);
    ((HourlyWorker*) employee[3])->setHours(10*30);
    employee[4] = new PieceWorker(20382, "Xiu LiWei", 0.5, 2850);
    employee[5] = new PieceWorker(20469, "Huang Donglin",0.75, 1850);
    cout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2);
    for(int i=0; i<6; i++)
        employee[i]->print();
    for(int i=0; i<6; i++)
        cout<<employee[i]->getName()<<" "<<employee[i]->earnings()<<endl;
}
// A helper function when create linked list
void AddFront(Employee * &head, Employee * &t)
{
    // This can insert element from the fornt of linked list
    t->next = head;
    head = t;
}
// Can create a linked lists
void test3()
{
    Employee * empHead = NULL, *ptr;
    ptr = new Manager(10135,"Cheng ShaoHua", 1200);
    AddFront(empHead, ptr);
    ptr = new HourlyWorker(30712, "Zhao XiaoMing", 5, 8*20);
    AddFront(empHead, ptr);
    ptr = new PieceWorker(20382, "Xiu LiWei", 0.5, 2850);
    AddFront(empHead, ptr);
    ptr = new PieceWorker(20469, "Huang Donglin");
    AddFront(empHead, ptr);             // can add first then set value, Or set value first then add to the linked list
    ((PieceWorker *)ptr)->setWage(0.75);
    ((PieceWorker *)ptr)->setQuantity(1850);
    // AddFront(empHead, ptr);
    ptr = empHead;
    while(ptr)
    {
        ptr->print();
        ptr = ptr->next;
    }
    ptr = empHead;
    while(ptr)
    {
        cout<<ptr->getName()<<" "<<ptr->earnings()<<endl;
        ptr = ptr->next;
    }
}
int main()
{
    // test();
    // test2();
    test3();
}