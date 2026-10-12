class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 1_000_000_007

        MAX_BIT = 30
        ans = 0
        minIndices = [0] * MAX_BIT
        optimalNums = [0] * len(nums)

        for num in nums:
            for i in range(MAX_BIT):
                if num >> i & 1:
                    optimalNums[minIndices[i]] |= 1 << i
                    minIndices[i] += 1

        for i in range(k):
            ans += optimalNums[i] ** 2
            ans %= MOD

        return ans
