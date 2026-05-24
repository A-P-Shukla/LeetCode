from typing import List
from functools import lru_cache

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        
        @lru_cache(None)
        def dfs(i: int) -> int:
            max_visited = 1
            
            # Jump to the right
            for j in range(i + 1, min(n, i + d + 1)):
                if arr[j] >= arr[i]:
                    break  # Blocked by an element >= arr[i]
                max_visited = max(max_visited, 1 + dfs(j))
                
            # Jump to the left
            for j in range(i - 1, max(-1, i - d - 1), -1):
                if arr[j] >= arr[i]:
                    break  # Blocked by an element >= arr[i]
                max_visited = max(max_visited, 1 + dfs(j))
                
            return max_visited
            
        # Try starting from each index and get the overall maximum
        return max(dfs(i) for i in range(n))