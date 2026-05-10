class Solution:
    def maximumJumps(self, nums: list[int], target: int) -> int:
        n = len(nums)
        # dp[i] will store the maximum number of jumps to reach index i.
        # Initialize with -1 to signify that the index is not yet reached.
        dp = [-1] * n
        
        # We start at index 0 with 0 jumps.
        dp[0] = 0
        
        # Iterate through each index from 1 to n-1.
        for j in range(1, n):
            # Check all possible previous indices i from which we can jump to j.
            for i in range(j):
                # If index i is reachable and the jump condition is satisfied.
                if dp[i] != -1 and abs(nums[j] - nums[i]) <= target:
                    # Update dp[j] with the maximum jumps found so far.
                    dp[j] = max(dp[j], dp[i] + 1)
        
        # The answer is the maximum jumps to reach the last index.
        return dp[n - 1]