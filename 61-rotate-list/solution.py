# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Handle edge cases: empty list, single node, or no rotation needed
        if not head or not head.next or k == 0:
            return head
        
        # 1. Determine the length of the list and locate the tail
        tail = head
        length = 1
        while tail.next:
            tail = tail.next
            length += 1
            
        # 2. Calculate the effective number of rotations
        k = k % length
        if k == 0:
            return head
            
        # 3. Connect the tail to the head to form a cycle
        tail.next = head
        
        # 4. Find the node that will become the new tail
        # The new head is at index (length - k), so the new tail is at (length - k - 1)
        # Moving (length - k) steps from the current tail reaches the new tail
        steps_to_new_tail = length - k
        new_tail = tail
        for _ in range(steps_to_new_tail):
            new_tail = new_tail.next
            
        # 5. Establish the new head and break the circular connection
        new_head = new_tail.next
        new_tail.next = None
        
        return new_head