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
ListNode * rev(ListNode * head)
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
    ListNode* doubleIt(ListNode* head) {
        ListNode * rev_head = rev(head);
        int carry = 0;
        ListNode * temp = rev_head;
        ListNode * prev_temp = temp;
        while(temp != NULL)
        {
            int num = (temp->val) * 2 + carry;
            temp->val = num %10;
            carry = num/10;
            prev_temp = temp;
            temp = temp->next;
        }
        if(carry != 0) prev_temp->next = new ListNode(carry);
        return rev(rev_head);
    }
};