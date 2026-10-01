class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)

        # Cyclic sort: place each value v at index v-1 (if 1 <= v <= n)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]

        # First mismatch gives the answer
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        return n + 1
