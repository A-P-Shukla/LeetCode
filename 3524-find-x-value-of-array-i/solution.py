class Solution:
    def resultArray(self, nums: list[int], k: int) -> list[int]:
        result = [0] * k
        dp = [0] * k

        for num in nums:
            val = num % k
            next_dp = [0] * k
            
            # Single-element subarray starting and ending at current index
            next_dp[val] += 1

            # Extend existing subarrays ending at previous index
            for x in range(k):
                if dp[x] > 0:
                    next_dp[(x * val) % k] += dp[x]

            # Accumulate counts for all valid remainders ending at current index
            for x in range(k):
                result[x] += next_dp[x]

            dp = next_dp

        return result