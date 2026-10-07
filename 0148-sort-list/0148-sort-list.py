# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

        
    def sortList(self, head: ListNode | None) -> ListNode | None:
        if not head or not head.next:
            return head
        slow=head
        fast=head
        prev=slow
        while fast and fast.next:
            prev=slow
            slow=slow.next
            fast=fast.next.next
        prev.next=None
        left=self.sortList(head)
        right=self.sortList(slow)

        return self.merge(left,right)

    def merge(self,left,right):
        dummy=ListNode(-1)
        newhead=dummy
        while left and right:
            if left.val<right.val:
                newhead.next=left
                newhead=left
                left=left.next
            else:
                newhead.next=right
                newhead=right
                right=right.next
        newhead.next=left if left else right
        return dummy.next
            
    