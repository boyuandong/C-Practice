/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> reversePrint1(ListNode *head)
    {
        // Soution 1:
        vector<int> ans;
        for (ListNode *p = head; p; p = p->next)
        {
            ans.insert(ans.begin(), p->val);
        }
        return ans;
    }
    void recursion(vector<int> &ans, ListNode *head)
    {
        if (head == NULL)
            return;
        recursion(ans, head->next);
        ans.push_back(head->val);
    }

    vector<int> reversePrint2(ListNode *head)
    {
        // Solution 2: use the recursive
        // running more quickly
        vector<int> ans;
        recursion(ans, head);
        return ans;
    }
    vector<int> reversePrint3(ListNode *head)
    {
        // Solution 3: use vector back to front
        // The quickest
        int num = 0;
        for (ListNode *p = head; p; p = p->next)
            num++;
        vector<int> ans(num, 0);
        ListNode *p = head;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            ans[i] = p->val;
            p = p->next;
        }
        return ans;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    Solution s;
    vector<int> sol = s.reversePrint1(head);
    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
    sol = s.reversePrint2(head);
    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
    sol = s.reversePrint3(head);
    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;

}