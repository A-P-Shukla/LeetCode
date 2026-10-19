class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        left = bisect_left(nums, target)
        if left == len(nums) or nums[left] != target:
            return []
        right = bisect_right(nums, target)
        return list(range(left, right))