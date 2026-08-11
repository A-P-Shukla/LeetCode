class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        sum_val = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                sum_val += nums[i]
            else:
                break
        
        num_set = set(nums)
        
        while sum_val in num_set:
            sum_val += 1
            
        return sum_val