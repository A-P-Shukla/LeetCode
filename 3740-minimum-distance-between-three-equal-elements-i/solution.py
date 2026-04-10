from collections import defaultdict
from typing import List

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        """
        Calculates the minimum distance of a good tuple.
        Formula simplification: abs(i-j) + abs(j-k) + abs(k-i) = 2 * (max(i,j,k) - min(i,j,k))
        """
        # Dictionary to store a list of indices for each number
        pos_map = defaultdict(list)
        for idx, val in enumerate(nums):
            pos_map[val].append(idx)
            
        min_dist = float('inf')
        
        for val in pos_map:
            indices = pos_map[val]
            # We need at least 3 indices to form a good tuple
            if len(indices) >= 3:
                # To minimize the span, check triplets of consecutive occurrences
                for i in range(len(indices) - 2):
                    # distance = 2 * (last_index - first_index)
                    dist = 2 * (indices[i + 2] - indices[i])
                    if dist < min_dist:
                        min_dist = dist
                        
        return int(min_dist) if min_dist != float('inf') else -1