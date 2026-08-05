from collections import deque
from typing import List

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        # Step 1: Build the directed adjacency list
        adj = [[] for _ in range(n)]
        for u, v in invocations:
            adj[u].append(v)
            
        # Step 2: BFS traversal to find all suspicious methods starting from k
        is_suspicious = [False] * n
        queue = deque([k])
        is_suspicious[k] = True
        
        while queue:
            u = queue.popleft()
            for v in adj[u]:
                if not is_suspicious[v]:
                    is_suspicious[v] = True
                    queue.append(v)
                    
        # Step 3: Check for external invocations into the suspicious group
        for u, v in invocations:
            if not is_suspicious[u] and is_suspicious[v]:
                # Non-suspicious method invokes a suspicious method; return all
                return list(range(n))
                
        # Step 4: Return remaining non-suspicious methods
        return [i for i in range(n) if not is_suspicious[i]]