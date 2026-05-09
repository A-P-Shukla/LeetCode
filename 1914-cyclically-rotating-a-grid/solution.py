class Solution:
    def rotateGrid(self, grid: list[list[int]], k: int) -> list[list[int]]:
        m, n = len(grid), len(grid[0])
        num_layers = min(m, n) // 2
        
        for layer in range(num_layers):
            top, left = layer, layer
            bottom, right = m - 1 - layer, n - 1 - layer
            
            # 1. Extract the current layer elements
            elements = []
            
            # Top row: left to right (excluding last)
            for j in range(left, right):
                elements.append(grid[top][j])
            # Right col: top to bottom (excluding last)
            for i in range(top, bottom):
                elements.append(grid[i][right])
            # Bottom row: right to left (excluding last)
            for j in range(right, left, -1):
                elements.append(grid[bottom][j])
            # Left col: bottom to top (excluding last)
            for i in range(bottom, top, -1):
                elements.append(grid[i][left])
            
            # 2. Calculate effective rotation
            L = len(elements)
            shift = k % L
            
            # Rotation: index i in result list is index (i + shift) % L in original
            # Instead of creating a new list, we can just use a pointer
            idx = 0
            
            # 3. Fill the grid back with rotated elements
            # Top row
            for j in range(left, right):
                grid[top][j] = elements[(idx + shift) % L]
                idx += 1
            # Right col
            for i in range(top, bottom):
                grid[i][right] = elements[(idx + shift) % L]
                idx += 1
            # Bottom row
            for j in range(right, left, -1):
                grid[bottom][j] = elements[(idx + shift) % L]
                idx += 1
            # Left col
            for i in range(bottom, top, -1):
                grid[i][left] = elements[(idx + shift) % L]
                idx += 1
                
        return grid