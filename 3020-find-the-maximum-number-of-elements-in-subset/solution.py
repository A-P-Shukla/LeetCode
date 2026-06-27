from collections import Counter
import math

class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        counts = Counter(nums)
        max_len = 1
        
        # Handle base 1
        if 1 in counts:
            ones = counts[1]
            if ones % 2 == 0:
                ones -= 1
            max_len = max(max_len, ones)
            
        # Handle bases > 1
        for x in counts:
            if x == 1:
                continue
            
            curr = x
            current_len = 0
            
            # Count pairs for each power
            while counts.get(curr, 0) >= 2:
                current_len += 2
                curr *= curr
            
            # Check if we can add a middle element
            if counts.get(curr, 0) >= 1:
                current_len += 1
            else:
                # If we couldn't form the last pair, remove the overshoot
                current_len -= 1
            
            max_len = max(max_len, current_len)
            
        return max_len