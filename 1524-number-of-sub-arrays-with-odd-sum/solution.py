from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 1_000_000_007
        cnt_even = 1   # empty prefix sum = 0 (even)
        cnt_odd = 0
        ans = 0
        parity = 0     # 0 -> even, 1 -> odd

        for v in arr:
            parity ^= (v & 1)          # toggle if v is odd
            if parity:
                ans = (ans + cnt_even) % MOD
                cnt_odd += 1
            else:
                ans = (ans + cnt_odd) % MOD
                cnt_even += 1

        return ans