class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        BASE = 91138233 
        mask = (1 << 64) - 1

        pref = [0] * (n + 1)
        power = [1] * (n + 1)
        for i, v in enumerate(nums):
            pref[i + 1] = (pref[i] * BASE + (v + 1)) & mask
            power[i + 1] = (power[i] * BASE) & mask

        def has_unique(length: int) -> bool:
            cnt = {}
            for i in range(n - length + 1):
                h = (pref[i + length] - (pref[i] * power[length] & mask)) & mask
                cnt[h] = cnt.get(h, 0) + 1
            return any(c == 1 for c in cnt.values())

        lo, hi, ans = 1, n, n
        while lo <= hi:
            mid = (lo + hi) // 2
            if has_unique(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return ans