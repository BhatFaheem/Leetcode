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
class Solution {
public:
ListNode * rev(ListNode* & head)
{
    ListNode * curr = head;
    ListNode * prev = NULL;
    ListNode * forw = NULL;
    while(curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        head = rev(head);
        ListNode * temp = head;
        ListNode * prev = NULL;
        int prev_val = temp->val;
        while(temp != NULL)
        {
            if(temp->val < prev_val) prev->next = temp->next;
            else
            {
                prev_val = temp->val;
                prev = temp;
            }
            temp = temp->next;
        }
        head = rev(head);
        return head;
    }
};