from typing import List
from collections import Counter

class Solution:
    def maximizeConsecutiveElements(self, nums: List[int]) -> int:
        if not nums:
            return 0
        max_val = max(nums)
        size = max_val + 2                    # extra slot for possible increment
        freq = [0] * size
        for v in nums:
            freq[v] += 1

        ans = cur_len = carry = 0  # carry = elements increased from v-1 to v

        for v in range(1, size):
            supply = freq[v] + carry
            if supply == 0:
                cur_len = 0
                carry = 0
                continue

            cur_len += 1
            if carry > 0:
                # use a carried element, keep all originals for next step
                carry = freq[v]
            else:
                # use an original element, remaining originals become carry
                carry = freq[v] - 1

            ans = max(ans, cur_len)

        return ans