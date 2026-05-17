class Solution:
    def canReach(self, arr: list[int], start: int) -> bool:
        """
        Determines if an index with value 0 is reachable from the start index 
        using Depth-First Search.
        """
        # Boundary check and cycle detection (visited check)
        # We mark visited indices by making their value negative.
        if not (0 <= start < len(arr)) or arr[start] < 0:
            return False
        
        # Target condition
        if arr[start] == 0:
            return True
        
        # Capture jump distance
        jump = arr[start]
        
        # Mark as visited
        arr[start] = -arr[start]
        
        # Explore both directions: i + arr[i] and i - arr[i]
        # Using boolean OR short-circuiting to stop as soon as True is found
        return self.canReach(arr, start + jump) or self.canReach(arr, start - jump)

# Alternative BFS implementation if preferred for iterative approach:
# from collections import deque
# class SolutionBFS:
#     def canReach(self, arr: list[int], start: int) -> bool:
#         q = deque([start])
#         visited = {start}
#         while q:
#             i = q.popleft()
#             if arr[i] == 0: return True
#             for next_i in (i + arr[i], i - arr[i]):
#                 if 0 <= next_i < len(arr) and next_i not in visited:
#                     visited.add(next_i)
#                     q.append(next_i)
#         return False