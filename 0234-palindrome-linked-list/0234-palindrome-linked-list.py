# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        def rev(head : ListNode) -> ListNode:
            curr = head
            prev = None
            while curr != None:
                forward = curr.next
                curr.next = prev
                prev = curr
                curr = forward
            return prev
        def middle_node(head : ListNode) ->ListNode:
            slow = fast = head
            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
            return slow
        if not head or not head.next : return True
        mn = middle_node(head)
        rev_head = rev(mn)
        while rev_head:
            if rev_head.val != head.val:return False
            rev_head = rev_head.next
            head = head.next
        return True

        