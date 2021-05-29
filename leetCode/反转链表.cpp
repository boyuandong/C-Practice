/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList1(ListNode* head) {
        // 迭代法
        ListNode* h = NULL;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = h;
            h = head;
            head = temp;
        }
        return h;
    }
    ListNode* reverseList2(ListNode* head) {
        // 递归法
        // base case
        if(!head || !head->next) return head;
        // h is the head of reverseList head->next
        ListNode *h = reverseList(head->next);
        // need to reverse one more head
        head->next->next = head;
        head->next = NULL;
        return h;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;

        ListNode *first = head;
        ListNode *second = first->next;
        first->next = NULL;
        while(second)
        {
            ListNode *temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }

        return first;
    }
};