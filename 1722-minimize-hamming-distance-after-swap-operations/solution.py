from typing import List
from collections import defaultdict, Counter

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        
    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    
    def unite(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            self.parent[root_i] = root_j

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        uf = UnionFind(n)
        
        # Build components
        for a, b in allowedSwaps:
            uf.unite(a, b)
            
        # Group source elements by component root
        # key: root index, value: Counter of elements in that component
        groups = defaultdict(Counter)
        for i in range(n):
            root = uf.find(i)
            groups[root][source[i]] += 1
            
        matches = 0
        # Calculate how many target elements can be satisfied within each component
        for i in range(n):
            root = uf.find(i)
            val = target[i]
            if groups[root][val] > 0:
                matches += 1
                groups[root][val] -= 1
                
        return n - matches