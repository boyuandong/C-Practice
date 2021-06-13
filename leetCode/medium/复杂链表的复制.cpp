/* 复杂链表的复制.cpp
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：

输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList1(Node *head)
    {
        // 哈希表，空间和时间都是O(n)
        // save and create nodes into map
        map<Node *, Node *> Map;
        for (Node *p = head; p; p = p->next)
        {
            Map[p] = new Node(p->val);
        }
        // copy new nodes into one node list
        for (Node *p = head; p; p = p->next)
        {
            Map[p]->next = Map[p->next];
            Map[p]->random = Map[p->random];
        }
        return Map[head];
    }
    Node *copyRandomList(Node *head)
    {
        // 原地修改，空间复杂度为O(1)
        if (!head)
            return NULL;
        // copy next only first
        //将拷贝节点放到原节点后面，例如1->2->3这样的链表就变成了这样1->1'->2->2'->3->3'
        for (Node *p = head, *copy = NULL; p; p = p->next->next)
        {
            copy = new Node(p->val);
            copy->next = p->next;
            p->next = copy;
        }
        // then copy random try to connect them
        // remember the next one in the loop always is the new copied one
        // 1->1'->2->2'->3->3'
        for (Node *p = head; p; p = p->next->next)
        {
            if (p->random)
                p->next->random = p->random->next;
        }
        //分离拷贝节点和原节点，变成1->2->3和1'->2'->3'两个链表，后者就是答案
        Node *new_h = head->next;
        for (Node *p = head, *temp = NULL; p && p->next;)
        {
            temp = p->next;
            p->next = temp->next;
            p = temp;
        }
        return new_h;
    }
};
