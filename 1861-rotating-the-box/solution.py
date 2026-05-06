class Solution:
    def rotateTheBox(self, boxGrid: list[list[str]]) -> list[list[str]]:
        m = len(boxGrid)
        n = len(boxGrid[0])

        # 1. Simulate gravity row by row
        for row in boxGrid:
            # empty_pos points to the rightmost available cell where a stone can land
            empty_pos = n - 1
            for j in range(n - 1, -1, -1):
                if row[j] == '*':
                    # Obstacle found, the next stone must land to the left of it
                    empty_pos = j - 1
                elif row[j] == '#':
                    # Stone found, move it to the rightmost available position
                    row[j], row[empty_pos] = '.', '#'
                    empty_pos -= 1
        
        # 2. Rotate the matrix 90 degrees clockwise
        # New dimensions: n x m
        # (r, c) in original becomes (c, (m-1) - r) in rotated
        rotated_box = [['' for _ in range(m)] for _ in range(n)]
        
        for r in range(m):
            for c in range(n):
                rotated_box[c][m - 1 - r] = boxGrid[r][c]
                
        return rotated_box