class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            if self.rank[root_i] < self.rank[root_j]:
                self.parent[root_i] = root_j
            elif self.rank[root_i] > self.rank[root_j]:
                self.parent[root_j] = root_i
            else:
                self.parent[root_i] = root_j
                self.rank[root_j] += 1
            return True
        return False

class Solution:
    def containsCycle(self, grid: list[list[str]]) -> bool:
        rows = len(grid)
        cols = len(grid[0])
        uf = UnionFind(rows * cols)

        for r in range(rows):
            for c in range(cols):
                # We only need to check right and down neighbors to cover all edges
                # without processing the same edge twice.
                
                # Check Right Neighbor
                if c + 1 < cols and grid[r][c] == grid[r][c + 1]:
                    u = r * cols + c
                    v = r * cols + (c + 1)
                    if uf.find(u) == uf.find(v):
                        return True
                    uf.union(u, v)
                
                # Check Down Neighbor
                if r + 1 < rows and grid[r][c] == grid[r + 1][c]:
                    u = r * cols + c
                    v = (r + 1) * cols + c
                    if uf.find(u) == uf.find(v):
                        return True
                    uf.union(u, v)
        
        return False