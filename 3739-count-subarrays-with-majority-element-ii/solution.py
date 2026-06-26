class FenwickTree:
    def __init__(self, n):
        self.tree = [0] * (n + 1)

    def add(self, i, delta):
        while i < len(self.tree):
            self.tree[i] += delta
            i += i & (-i)

    def query(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & (-i)
        return s

class Solution:
    def countSubarrays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        # Prefix sum P[i] = count(target) - count(not target)
        # P[j+1] - P[i] > 0  => P[j+1] > P[i]
        p = [0] * (n + 1)
        for i in range(n):
            p[i + 1] = p[i] + (1 if nums[i] == target else -1)
        
        # Offset to handle negative prefix sums. Range is [-n, n]
        offset = n + 1
        ft = FenwickTree(2 * n + 2)
        count = 0
        
        for val in p:
            # Add offset to make values strictly positive for Fenwick Tree
            # Query count of all previous p values < current val
            count += ft.query(val + offset - 1)
            ft.add(val + offset, 1)
            
        return count