from collections import defaultdict

class Solution:
    def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
        # Build adjacency list
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        visited = [False] * n
        complete_count = 0
        
        def dfs(u, component):
            visited[u] = True
            component.append(u)
            for v in adj[u]:
                if not visited[v]:
                    dfs(v, component)
                    
        for i in range(n):
            if not visited[i]:
                component = []
                dfs(i, component)
                
                # Check if component is complete
                # V * (V - 1) / 2 edges needed
                v_count = len(component)
                e_count = 0
                for node in component:
                    e_count += len(adj[node])
                
                # Each edge is counted twice in adj list
                if e_count // 2 == v_count * (v_count - 1) // 2:
                    complete_count += 1
                    
        return complete_count