class Solution:
    def minAbsoluteDistance(self, nums: list[int]) -> int:
        # last_seen_rev maps: reverse(nums[i]) -> index i
        last_seen_rev = {}
        min_dist = float('inf')
        
        for j, val in enumerate(nums):
            # Check if current value matches a previously reversed number
            if val in last_seen_rev:
                min_dist = min(min_dist, j - last_seen_rev[val])
            
            # Calculate the reverse of the current number for future lookups
            # The definition of reverse(120) = 21 is naturally handled by int(str[::-1])
            # or by mathematical digit extraction.
            rev_val = self.reverse_int(val)
            
            # Update the map with the current index. 
            # We overwrite previous indices because we want the minimum distance (closest i).
            last_seen_rev[rev_val] = j
            
        return int(min_dist) if min_dist != float('inf') else -1

    def reverse_int(self, n: int) -> int:
        rev = 0
        while n > 0:
            rev = rev * 10 + (n % 10)
            n //= 10
        return rev