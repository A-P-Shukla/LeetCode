from typing import List

class Solution:
    def longestEqualProductSubarray(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7]           # only primes that can appear (nums[i] ≤ 10)
        n = len(nums)

        # exponent vectors for each element
        exp: List[List[int]] = []
        for x in nums:
            cur = []
            for p in primes:
                cnt = 0
                while x % p == 0:
                    x //= p
                    cnt += 1
                cur.append(cnt)
            exp.append(cur)

        best = 0
        for l in range(n):
            sum_e = [0] * 4
            max_e = [0] * 4
            min_e = [float('inf')] * 4
            for r in range(l, n):
                for k in range(4):
                    e = exp[r][k]
                    sum_e[k] += e
                    max_e[k] = max(max_e[k], e)
                    min_e[k] = min(min_e[k], e)

                if all(sum_e[k] == max_e[k] + min_e[k] for k in range(4)):
                    best = max(best, r - l + 1)

        return best