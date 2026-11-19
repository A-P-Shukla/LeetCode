from typing import List

class Solution:
    def minimumScore(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 3:
            return 0  # can set all three equal
        nums.sort()
        INF = 10**18
        ans = INF
        # remove two smallest
        ans = min(ans, nums[-1] - nums[2])
        # remove two largest
        ans = min(ans, nums[-3] - nums[0])
        # remove smallest and largest
        ans = min(ans, nums[-2] - nums[1])
        # remove only smallest
        ans = min(ans, nums[-1] - nums[1])
        # remove only largest
        ans = min(ans, nums[-2] - nums[0])
        return ans