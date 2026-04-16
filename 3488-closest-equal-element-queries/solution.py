from collections import defaultdict

class Solution:
    def closestEqualElement(self, nums: list[int], queries: list[int]) -> list[int]:
        n = len(nums)
        # Group indices by their values
        groups = defaultdict(list)
        for idx, val in enumerate(nums):
            groups[val].append(idx)
        
        # Pre-calculate the result for every index in the array
        # Initialize with -1 for values that appear only once
        ans_at_index = [-1] * n
        
        for val, positions in groups.items():
            k = len(positions)
            if k < 2:
                continue
            
            # Distance between the last and first index across the circular boundary
            wrap_dist = n - (positions[-1] - positions[0])
            
            for i in range(k):
                # Calculate distance to previous occurrence
                if i == 0:
                    dist_prev = wrap_dist
                else:
                    dist_prev = positions[i] - positions[i-1]
                
                # Calculate distance to next occurrence
                if i == k - 1:
                    dist_next = wrap_dist
                else:
                    dist_next = positions[i+1] - positions[i]
                
                # Store the minimum of the two circular neighbors
                ans_at_index[positions[i]] = min(dist_prev, dist_next)
        
        # Map queries to the pre-calculated answers
        return [ans_at_index[q] for q in queries]