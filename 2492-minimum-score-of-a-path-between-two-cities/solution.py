from collections import deque, defaultdict

class Solution:
    def minScore(self, n: int, roads: list[list[int]]) -> int:
        # Build adjacency list: node -> list of (neighbor, distance)
        graph = defaultdict(list)
        for u, v, d in roads:
            graph[u].append((v, d))
            graph[v].append((u, d))
            
        min_score = float('inf')
        visited = [False] * (n + 1)
        queue = deque([1])
        visited[1] = True
        
        # BFS to find all reachable nodes and the min edge weight in the component
        while queue:
            curr = queue.popleft()
            
            for neighbor, dist in graph[curr]:
                # Update global minimum score encountered
                min_score = min(min_score, dist)
                
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
                    
        return min_score