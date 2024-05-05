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
    void deleteNode(ListNode* node) {
       ListNode * temp = node->next;
        while(temp != NULL)
        {
            node->val = temp->val;
            if(temp->next != NULL)
            {
                node = temp;
               temp = temp->next;
            }
            else
            {
                 break;
            }
            
        }
        node->next = NULL;
    }
};