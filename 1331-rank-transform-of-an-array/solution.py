from typing import List

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return []
        
        # 1. Get unique elements and sort them
        # Sorting unique elements creates the foundation for ranking
        sorted_unique = sorted(set(arr))
        
        # 2. Map each value to its rank
        # Dictionary comprehension for O(N) map creation
        rank_map = {val: i + 1 for i, val in enumerate(sorted_unique)}
        
        # 3. Build result by looking up the rank of each original element
        return [rank_map[x] for x in arr]