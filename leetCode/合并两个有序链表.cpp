/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例 1：

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // !!!!!!!!!!! IMPORTANT !!!!!!!!!!
        ListNode head=NULL;
        ListNode *p = &head;
        // !!!!!!!!!!!  IMPORTANT !!!!!!!!!!
        while(l1 || l2)
        {
            // cout<<l1->val<<"\t"<<l2->val<<endl;
             if(!l1 && l2)
            {
                // cout<<"1"<<endl;
                p->next = l2;
                break;
            }
            if(!l2 && l1)
            {
                // cout<<"2"<<endl;
                p->next = l1;
                break;
            }
            if(l1->val < l2->val)
            {
                // cout<<"3"<<endl;
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                // cout<<"4"<<endl;
                p->next = l2;
                l2 = l2->next;
            }
           
            // if(!l1 && l2)
            // p->next = nullptr;
            p = p->next;
        }

        return head.next;
    }
};
void printList( ListNode *& head)
{
    cout<<"Output List:\n";
    if(head == nullptr)
    {
        cout<<"[]"<<endl;
        return;
    }
    cout<<"[";
    for(ListNode *p=head; p; p=p->next)
        cout<<p->val<<" ";
    cout<<"]"<<endl;
    // cout<<endl;
}
int main()
{
    cout<<"test:\n";
    ListNode *L1 = new ListNode(1);
    L1->next = new ListNode(2);
    L1->next->next = new ListNode(4);
    printList(L1);
    ListNode *L2 = new ListNode(1);
    L2->next = new ListNode(3);
    L2->next->next = new ListNode(4);
    printList(L2);
    Solution s;
    ListNode *test = s.mergeTwoLists(L1, L2);
    printList(test);

    // ListNode head = NULL;
    // cout<<"This is a null test: "<<head.val<<" "<<head.next<<endl;
    // printList(head.next);

    cout<<"test1:\n";
    ListNode *L3=nullptr;
    ListNode *L4=nullptr;
    printList(L3);
    printList(L4);
    ListNode *test2 = s.mergeTwoLists(L3, L4);
    printList(test2);

    cout<<"test2:\n";
    ListNode *L5 = new ListNode(0);
    printList(L3);
    printList(L5);
    ListNode *test3 = s.mergeTwoLists(L3, L5);
    printList(test3);
}