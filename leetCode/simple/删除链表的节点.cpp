
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p;
        // head is null
        if(!head)
            return head;
        // need to delete head node
        if(head->val == val)
        {
            p = head;
            head = head->next;
            // delete p;
            // p = NULL;
            return head;
        }
        // otherwise
        for(ListNode *q=head; q->next; q=q->next)
        {
            if(q->next->val == val)
            {
                p = q->next;
                q->next = p->next;
                // delete p;
                // p = NULL;
                return head;
            }
        }

        return head;
    }
};