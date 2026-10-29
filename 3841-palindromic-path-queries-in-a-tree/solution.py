from typing import List
import sys
sys.setrecursionlimit(1 << 25)


class HLD:
    def __init__(self, n: int):
        self.n = n
        self.adj: List[List[int]] = [[] for _ in range(n)]
        self.parent = [-1] * n
        self.depth = [0] * n
        self.heavy = [-1] * n
        self.head = [0] * n
        self.pos = [0] * n
        self.sz = [0] * n
        self.timer = 0

    def add_edge(self, u: int, v: int) -> None:
        self.adj[u].append(v)
        self.adj[v].append(u)

    def _dfs(self, v: int, p: int) -> int:
        self.parent[v] = p
        self.sz[v] = 1
        max_sub = 0
        for to in self.adj[v]:
            if to == p:
                continue
            self.depth[to] = self.depth[v] + 1
            sub = self._dfs(to, v)
            self.sz[v] += sub
            if sub > max_sub:
                max_sub = sub
                self.heavy[v] = to
        return self.sz[v]

    def _decompose(self, v: int, h: int) -> None:
        self.head[v] = h
        self.pos[v] = self.timer
        self.timer += 1
        if self.heavy[v] != -1:
            self._decompose(self.heavy[v], h)
        for to in self.adj[v]:
            if to != self.parent[v] and to != self.heavy[v]:
                self._decompose(to, to)

    def init(self, root: int = 0) -> None:
        self._dfs(root, -1)
        self._decompose(root, root)


class SegTree:
    def __init__(self, data: List[int]):
        n_ = len(data)
        self.n = 1
        while self.n < n_:
            self.n <<= 1
        self.tree = [0] * (2 * self.n)
        for i, val in enumerate(data):
            self.tree[self.n + i] = val
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.tree[i << 1] ^ self.tree[i << 1 | 1]

    def point_update(self, idx: int, val: int) -> None:
        i = idx + self.n
        self.tree[i] = val
        i >>= 1
        while i:
            self.tree[i] = self.tree[i << 1] ^ self.tree[i << 1 | 1]
            i >>= 1

    def range_query(self, l: int, r: int) -> int:  # inclusive
        res = 0
        l += self.n
        r += self.n + 1
        while l < r:
            if l & 1:
                res ^= self.tree[l]
                l += 1
            if r & 1:
                r -= 1
                res ^= self.tree[r]
            l >>= 1
            r >>= 1
        return res


class Solution:
    def palindromicPathQueries(self, n: int, edges: List[List[int]],
                               s: str, queries: List[str]) -> List[bool]:
        hld = HLD(n)
        for u, v in edges:
            hld.add_edge(u, v)
        hld.init(0)

        base = [0] * n
        for i, ch in enumerate(s):
            mask = 1 << (ord(ch) - ord('a'))
            base[hld.pos[i]] = mask

        seg = SegTree(base)

        ans: List[bool] = []
        for line in queries:
            parts = line.split()
            if parts[0] == "update":
                u = int(parts[1])
                c = parts[2]
                new_mask = 1 << (ord(c) - ord('a'))
                seg.point_update(hld.pos[u], new_mask)
            else:  # query
                u = int(parts[1])
                v = int(parts[2])
                xor_mask = 0
                while hld.head[u] != hld.head[v]:
                    if hld.depth[hld.head[u]] < hld.depth[hld.head[v]]:
                        u, v = v, u
                    head_u = hld.head[u]
                    xor_mask ^= seg.range_query(hld.pos[head_u], hld.pos[u])
                    u = hld.parent[head_u]
                l = min(hld.pos[u], hld.pos[v])
                r = max(hld.pos[u], hld.pos[v])
                xor_mask ^= seg.range_query(l, r)
                ans.append((xor_mask & (xor_mask - 1)) == 0)
        return ans