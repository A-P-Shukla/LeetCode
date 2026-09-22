from typing import List

class SegmentTree:
    def __init__(self, nums: List[int], k: int):
        self.n = len(nums)
        self.k = k
        self.tree_prod = [1] * (4 * self.n)
        self.tree_cnt = [[0] * k for _ in range(4 * self.n)]
        self._build(1, 0, self.n - 1, nums)

    def _merge(self, left_idx: int, right_idx: int, parent_idx: int):
        l_prod = self.tree_prod[left_idx]
        r_prod = self.tree_prod[right_idx]
        self.tree_prod[parent_idx] = (l_prod * r_prod) % self.k

        l_cnt = self.tree_cnt[left_idx]
        r_cnt = self.tree_cnt[right_idx]
        p_cnt = self.tree_cnt[parent_idx]

        for i in range(self.k):
            p_cnt[i] = l_cnt[i]

        for j in range(self.k):
            if r_cnt[j] > 0:
                rem = (l_prod * j) % self.k
                p_cnt[rem] += r_cnt[j]

    def _build(self, node: int, l: int, r: int, nums: List[int]):
        if l == r:
            v = nums[l] % self.k
            self.tree_prod[node] = v
            self.tree_cnt[node][v] = 1
            return
        mid = (l + r) // 2
        self._build(2 * node, l, mid, nums)
        self._build(2 * node + 1, mid + 1, r, nums)
        self._merge(2 * node, 2 * node + 1, node)

    def update(self, node: int, l: int, r: int, idx: int, val: int):
        if l == r:
            v = val % self.k
            self.tree_prod[node] = v
            for i in range(self.k):
                self.tree_cnt[node][i] = 0
            self.tree_cnt[node][v] = 1
            return
        mid = (l + r) // 2
        if idx <= mid:
            self.update(2 * node, l, mid, idx, val)
        else:
            self.update(2 * node + 1, mid + 1, r, idx, val)
        self._merge(2 * node, 2 * node + 1, node)

    def query(self, node: int, l: int, r: int, ql: int, qr: int, running_prod: int, target_x: int) -> tuple:
        ans = 0
        if ql <= l and r <= qr:
            node_cnt = self.tree_cnt[node]
            for j in range(self.k):
                if node_cnt[j] > 0:
                    if (running_prod * j) % self.k == target_x:
                        ans += node_cnt[j]
            running_prod = (running_prod * self.tree_prod[node]) % self.k
            return ans, running_prod

        mid = (l + r) // 2
        if ql <= mid:
            add_ans, running_prod = self.query(2 * node, l, mid, ql, qr, running_prod, target_x)
            ans += add_ans
        if qr > mid:
            add_ans, running_prod = self.query(2 * node + 1, mid + 1, r, ql, qr, running_prod, target_x)
            ans += add_ans

        return ans, running_prod


class Solution:
    def countKConstraintSubarrays(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        seg_tree = SegmentTree(nums, k)
        n = len(nums)
        results = []

        for idx, val, start, target_x in queries:
            seg_tree.update(1, 0, n - 1, idx, val)
            ans, _ = seg_tree.query(1, 0, n - 1, start, n - 1, 1 % k, target_x)
            results.append(ans)

        return results