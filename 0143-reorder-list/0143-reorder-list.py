# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        arr = []
        temp = head
        while temp != None:
            arr.append(temp.val)
            temp = temp.next
        temp = head
        i = 0
        j = len(arr) - 1
        while temp != None:
            temp.val = arr[i]
            i += 1
            temp = temp.next
            if temp != None:
                temp.val = arr[j]
                j -=1
                temp = temp.next
        