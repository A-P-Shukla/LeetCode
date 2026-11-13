from collections import deque
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        """
        Sliding window with monotonic segments.
        segs stores (value, cnt) where 'value' is the constant prefix maximum
        for a contiguous block of length 'cnt'.
        """
        segs: deque[tuple[int, int]] = deque()
        sum_nums: int = 0          # ordinary sum of the window
        sum_max: int = 0           # sum of prefix maxima inside the window
        ans: int = 0
        l: int = 0

        for r, x in enumerate(nums):
            sum_nums += x
            merged_len = 1

            # Merge previous segments whose max <= x
            while segs and segs[-1][0] <= x:
                val, cnt = segs.pop()
                sum_max -= val * cnt
                merged_len += cnt

            segs.append((x, merged_len))
            sum_max += x * merged_len

            # Shrink from the left while required operations exceed k
            while sum_max - sum_nums > k:
                sum_nums -= nums[l]
                val, cnt = segs[0]
                sum_max -= val               # remove contribution of leftmost element
                if cnt == 1:
                    segs.popleft()
                else:
                    segs[0] = (val, cnt - 1)
                l += 1

            ans += r - l + 1

        return ans