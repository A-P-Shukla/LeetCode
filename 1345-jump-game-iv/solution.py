from collections import defaultdict, deque

class Solution:
    def minJumps(self, arr: list[int]) -> int:
        n = len(arr)
        if n <= 1:
            return 0
        
        # Map values to their indices
        indices_of_value = defaultdict(list)
        for i, val in enumerate(arr):
            indices_of_value[val].append(i)
            
        queue = deque([0])
        visited = {0}
        steps = 0
        
        while queue:
            # Process current level
            for _ in range(len(queue)):
                i = queue.popleft()
                
                # Check if we reached the end
                if i == n - 1:
                    return steps
                
                # Potential next indices
                next_indices = [i - 1, i + 1]
                
                # Add jumps to indices with same value
                if arr[i] in indices_of_value:
                    next_indices.extend(indices_of_value[arr[i]])
                    # Important: Clear the entry to prevent redundant checks
                    # and ensure O(N) time complexity.
                    del indices_of_value[arr[i]]
                
                for next_i in next_indices:
                    if 0 <= next_i < n and next_i not in visited:
                        visited.add(next_i)
                        queue.append(next_i)
            
            steps += 1
            
        return -1