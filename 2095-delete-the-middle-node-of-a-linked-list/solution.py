# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Handle the edge case where the list has only one node.
        if not head.next:
            return None
        
        # Initialize slow and fast pointers.
        # We also need to keep track of the node before the slow pointer (prev).
        slow = head
        fast = head
        prev = None
        
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
            
        # 'slow' is now at the middle, 'prev' is the node before it.
        # Remove the middle node by linking 'prev' to the node after 'slow'.
        prev.next = slow.next
        
        return head