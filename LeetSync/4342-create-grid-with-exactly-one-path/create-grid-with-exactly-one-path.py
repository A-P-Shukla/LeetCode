class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = ['#' * n for _ in range(m)]
        grid = [list(row) for row in grid]
        for i in range(m):
            grid[i][0] = '.'

        for j in range(1, n):
            grid[m - 1][j] = '.'

        return [''.join(row) for row in grid]