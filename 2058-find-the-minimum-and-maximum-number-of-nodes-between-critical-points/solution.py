# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from typing import Optional, List

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        # A critical point requires at least 3 nodes in the list.
        if not head or not head.next or not head.next.next:
            return [-1, -1]
        
        prev = head
        curr = head.next
        index = 1
        
        first_critical = -1
        prev_critical = -1
        min_distance = float('inf')
        
        while curr.next:
            is_maxima = curr.val > prev.val and curr.val > curr.next.val
            is_minima = curr.val < prev.val and curr.val < curr.next.val
            
            if is_maxima or is_minima:
                if first_critical == -1:
                    first_critical = index
                else:
                    min_distance = min(min_distance, index - prev_critical)
                prev_critical = index
                
            prev = curr
            curr = curr.next
            index += 1
            
        # If less than two critical points were found
        if min_distance == float('inf'):
            return [-1, -1]
            
        max_distance = prev_critical - first_critical
        return [int(min_distance), max_distance]