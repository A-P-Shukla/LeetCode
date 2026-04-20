class Solution:
    def maxDistance(self, colors: list[int]) -> int:
        n = len(colors)
        max_dist = 0
        
        # Scenario 1: Fix the first house, look for the furthest different color from the right
        for j in range(n - 1, 0, -1):
            if colors[j] != colors[0]:
                max_dist = max(max_dist, j)
                break
                
        # Scenario 2: Fix the last house, look for the furthest different color from the left
        for i in range(n - 1):
            if colors[i] != colors[n - 1]:
                max_dist = max(max_dist, (n - 1) - i)
                break
                
        return max_dist