from functools import lru_cache
from typing import List

class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + stoneValue[i]

        def get_sum(l: int, r: int) -> int:
            return prefix_sum[r + 1] - prefix_sum[l]

        @lru_cache(maxsize=None)
        def solve(i: int, j: int) -> int:
            if i == j:
                return 0

            max_score = 0
            for k in range(i, j):
                left_sum = get_sum(i, k)
                right_sum = get_sum(k + 1, j)

                if left_sum < right_sum:
                    max_score = max(max_score, left_sum + solve(i, k))
                elif left_sum > right_sum:
                    max_score = max(max_score, right_sum + solve(k + 1, j))
                else:
                    take_left = left_sum + solve(i, k)
                    take_right = right_sum + solve(k + 1, j)
                    max_score = max(max_score, take_left, take_right)

            return max_score

        return solve(0, n - 1)