from collections import deque

class Solution:
    def hasValidPath(self, grid: list[list[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        # Mapping street types to their connectivity offsets (dr, dc)
        # 1: Left-Right, 2: Up-Down, 3: Left-Down, 4: Right-Down, 5: Left-Up, 6: Right-Up
        directions = {
            1: [(0, -1), (0, 1)],
            2: [(-1, 0), (1, 0)],
            3: [(0, -1), (1, 0)],
            4: [(0, 1), (1, 0)],
            5: [(0, -1), (-1, 0)],
            6: [(0, 1), (-1, 0)]
        }
        
        queue = deque([(0, 0)])
        visited = set([(0, 0)])
        
        while queue:
            r, c = queue.popleft()
            
            if r == m - 1 and c == n - 1:
                return True
            
            # Explore valid moves from current street type
            for dr, dc in directions[grid[r][c]]:
                nr, nc = r + dr, c + dc
                
                # Check bounds and visited status
                if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in visited:
                    # Check if the next cell connects back to the current cell
                    # Next cell must have an exit pointing in the opposite direction (-dr, -dc)
                    can_connect_back = False
                    for bdr, bdc in directions[grid[nr][nc]]:
                        if bdr == -dr and bdc == -dc:
                            can_connect_back = True
                            break
                    
                    if can_connect_back:
                        visited.add((nr, nc))
                        queue.append((nr, nc))
                        
        return False