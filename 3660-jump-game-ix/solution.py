import bisect

class Solution:
    def maxReachableValue(self, nums: list[int]) -> list[int]:
        n = len(nums)
        if n == 0:
            return []

        # Step 1: Precompute Prefix Maximums.
        # P[i] is the maximum value in nums[0...i].
        # From any index i, we can reach P[i] via backward jumps (to larger values on the left).
        P = [0] * n
        P[0] = nums[0]
        for i in range(1, n):
            P[i] = max(P[i-1], nums[i])

        # Step 2: Identify the rightmost occurrence of every unique value.
        last_occurrence = {}
        for idx, val in enumerate(nums):
            last_occurrence[val] = idx
        
        # Step 3: Sort unique values for coordinate compression logic.
        sorted_keys = sorted(last_occurrence.keys())
        m = len(sorted_keys)
        
        # Step 4: Compute prefix maximums of the indices.
        # running_max_idx[k] stores the rightmost index of any value <= sorted_keys[k].
        running_max_idx = [0] * m
        curr_max = -1
        for i in range(m):
            curr_max = max(curr_max, last_occurrence[sorted_keys[i]])
            running_max_idx[i] = curr_max

        ans = [0] * n
        for i in range(n):
            val = nums[i]
            # Use binary search to find values strictly smaller than nums[i].
            # bisect_left returns the first index where sorted_keys[idx] >= val.
            # Thus, indices 0 to idx-1 represent values strictly smaller than val.
            idx = bisect.bisect_left(sorted_keys, val)
            
            j_max = -1
            if idx > 0:
                # The rightmost index of any value strictly smaller than nums[i].
                j_max = running_max_idx[idx - 1]
            
            # The rightmost index reachable is max(i, j_max).
            # The maximum reachable value is the prefix maximum at that point.
            ans[i] = P[max(i, j_max)]
            
        return ans