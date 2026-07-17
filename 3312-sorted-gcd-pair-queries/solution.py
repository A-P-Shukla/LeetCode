from bisect import bisect_right

class Solution:
    def gcdValues(self, nums: list[int], queries: list[int]) -> list[int]:
        max_val = max(nums)
        
        # Count multiples for each potential GCD
        freq = [0] * (max_val + 1)
        for x in nums:
            d = 1
            while d * d <= x:
                if x % d == 0:
                    freq[d] += 1
                    if d * d != x:
                        freq[x // d] += 1
                d += 1
        
        # Calculate exactly how many pairs have gcd == i
        # Using inclusion-exclusion from max_val down to 1
        count = [0] * (max_val + 1)
        for i in range(max_val, 0, -1):
            pairs_with_multiple = (freq[i] * (freq[i] - 1)) // 2
            for j in range(2 * i, max_val + 1, i):
                pairs_with_multiple -= count[j]
            count[i] = pairs_with_multiple
            
        # Build prefix sums to identify rank
        prefix_sum = [0] * (max_val + 1)
        for i in range(1, max_val + 1):
            prefix_sum[i] = prefix_sum[i - 1] + count[i]
            
        # Answer queries using binary search
        results = []
        for q in queries:
            results.append(bisect_right(prefix_sum, q))
            
        return results