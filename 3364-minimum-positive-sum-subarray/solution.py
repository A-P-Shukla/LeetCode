from typing import List

class Solution:
    def minPositiveSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        # Prefix sums: pref[i] = sum of first i elements, pref[0] = 0
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]

        INF = 10 ** 18
        answer = INF

        # j is the exclusive end index of the subarray
        for j in range(l, n + 1):
            max_len = min(r, j)          # length cannot exceed j
            for length in range(l, max_len + 1):
                i = j - length           # start index (inclusive)
                cur_sum = pref[j] - pref[i]
                if cur_sum > 0 and cur_sum < answer:
                    answer = cur_sum

        return -1 if answer == INF else answer