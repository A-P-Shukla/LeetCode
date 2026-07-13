# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        small = ListNode(0)
        large = ListNode(0)
        smallp = small
        largep = large

        while(head != None):
            if(head.val < x):
                smallp.next = head
                smallp = smallp.next

            else:
                largep.next = head
                largep = largep.next
            
            head = head.next

        smallp.next = large.next
        largep.next = None

        return small.next