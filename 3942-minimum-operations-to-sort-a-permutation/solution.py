from typing import List

class Solution:
    """
    Compute the minimal number of operations (rotate left by one, reverse whole array)
    required to transform a permutation of [0, …, n-1] into the sorted order.
    Returns -1 if impossible.
    """

    def _rotation_cost(self, nums: List[int]) -> int:
        """Return k if nums == rotate_left^k(sorted), else -1."""
        n = len(nums)
        try:
            idx0 = nums.index(0)
        except ValueError:
            return -1
        for j in range(n):
            if nums[(idx0 + j) % n] != j:
                return -1
        return idx0

    def _rev_rotation_cost(self, nums: List[int]) -> int:
        """Return k if nums == rotate_left^k(reversed sorted), else -1."""
        n = len(nums)
        try:
            idx_max = nums.index(n - 1)
        except ValueError:
            return -1
        for j in range(n):
            if nums[(idx_max + j) % n] != n - 1 - j:
                return -1
        return idx_max

    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0

        ans = float('inf')

        rot = self._rotation_cost(nums)
        if rot != -1:
            ans = min(ans, rot)

        rev_rot = self._rev_rotation_cost(nums)
        if rev_rot != -1:
            ans = min(ans, rev_rot + 1)   # one reversal plus rev_rot rotations

        return -1 if ans == float('inf') else ans