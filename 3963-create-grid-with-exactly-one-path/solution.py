from typing import List

class Solution:
    def constructGrid(self, m: int, n: int) -> List[str]:
        # Fill the matrix with obstacles
        grid = ['#' * n for _ in range(m)]

        # Convert to list of chars for mutability
        grid = [list(row) for row in grid]

        # Downward segment: column 0, rows 0..m-1
        for i in range(m):
            grid[i][0] = '.'

        # Rightward segment: bottom row, columns 1..n-1
        for j in range(1, n):
            grid[m - 1][j] = '.'

        # Convert rows back to strings
        return [''.join(row) for row in grid]