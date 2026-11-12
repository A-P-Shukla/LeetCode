class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 1

        inc_len = dec_len = 1  
        ans = 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                inc_len += 1
            else:
                inc_len = 1

            if nums[i] < nums[i - 1]:
                dec_len += 1
            else:
                dec_len = 1

            ans = max(ans, inc_len, dec_len)

        return ans