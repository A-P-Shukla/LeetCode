from collections import Counter

class Solution:
    def isGood(self, nums: list[int]) -> bool:
        # The length of base[n] is n + 1. 
        # Therefore, n = length of nums - 1.
        n = len(nums) - 1
        
        # base[1] = [1, 1], which is the smallest valid array (length 2)
        if n < 1:
            return False
            
        # Count the frequency of each number in the input
        counts = Counter(nums)
        
        # Check values from 1 to n-1: they must appear exactly once
        for i in range(1, n):
            if counts[i] != 1:
                return False
        
        # Check value n: it must appear exactly twice
        if counts[n] != 2:
            return False
            
        # Ensure there are no extra numbers outside the range [1, n]
        # Since we've checked frequencies for 1..n and the total count must match len(nums),
        # checking the size of the counter keys vs the expected n is a good safety check.
        return len(counts) == n