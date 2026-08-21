# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head

        ptr = head
        hashmap = {}

        while ptr:
            if ptr.val in hashmap:
                hashmap[ptr.val] = 1
            else:
                hashmap[ptr.val] = -1
            ptr = ptr.next
        
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        ptr = head

        while ptr:
            if hashmap[ptr.val] == 1:
                prev.next = ptr.next
            else:
                prev = ptr
            ptr = ptr.next
        
        return dummy.next