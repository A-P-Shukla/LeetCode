class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:

        adj = [[] for _ in range(n)]
        for u, v in invocations:
            adj[u].append(v)
            
        is_suspicious = [False] * n
        queue = deque([k])
        is_suspicious[k] = True
        
        while queue:
            u = queue.popleft()
            for v in adj[u]:
                if not is_suspicious[v]:
                    is_suspicious[v] = True
                    queue.append(v)
                    
        for u, v in invocations:
            if not is_suspicious[u] and is_suspicious[v]:
                return list(range(n))
                
        return [i for i in range(n) if not is_suspicious[i]]