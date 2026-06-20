class Solution:
    def maxBuilding(self, n: int, restrictions: list[list[int]]) -> int:
        restrictions.append([1, 0])
        restrictions.sort()
        
        m = len(restrictions)
        
        # Left to right pass: ensure h[i] <= h[i-1] + dist
        for i in range(1, m):
            restrictions[i][1] = min(restrictions[i][1], 
                                     restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]))
            
        # Right to left pass: ensure h[i] <= h[i+1] + dist
        for i in range(m - 2, -1, -1):
            restrictions[i][1] = min(restrictions[i][1], 
                                     restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]))
            
        max_h = 0
        # Calculate max height between adjacent tightened restrictions
        for i in range(m - 1):
            d = restrictions[i+1][0] - restrictions[i][0]
            h1, h2 = restrictions[i][1], restrictions[i+1][1]
            max_h = max(max_h, (h1 + h2 + d) // 2)
            
        # Check range after the last restriction to n
        max_h = max(max_h, restrictions[-1][1] + (n - restrictions[-1][0]))
        
        return max_h