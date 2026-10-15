class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        MAXV = 100  

        for i in range(n):
            seen = [False] * (MAXV + 1)
            distinct = 0
            for j in range(i, n):
                if not seen[nums[j]]:
                    seen[nums[j]] = True
                    distinct += 1
                ans += distinct * distinct
        return ans