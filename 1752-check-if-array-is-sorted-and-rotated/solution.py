class Solution:
    def check(self, nums: list[int]) -> bool:
        count = 0
        n = len(nums)
        
        for i in range(n):
            # Compare current element with the next element (circular array index)
            if nums[i] > nums[(i + 1) % n]:
                count += 1
                
            # If we find more than one inversion, the array cannot be sorted and rotated
            if count > 1:
                return False
                
        return True