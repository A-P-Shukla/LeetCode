class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        # Process each query: [l, r, k, v]
        for l, r, k, v in queries:
            # Update nums[idx] starting from l, up to r, jumping by k
            for idx in range(l, r + 1, k):
                nums[idx] = (nums[idx] * v) % MOD
        
        # Compute the final bitwise XOR sum of all elements
        xor_sum = 0
        for val in nums:
            xor_sum ^= val
            
        return xor_sum