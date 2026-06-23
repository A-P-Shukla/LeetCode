class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        n = len(nums)
        pivot = -1

        # Step 1: find rightmost ascending pair
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                pivot = i
                break

        if pivot == -1:
            nums.reverse()
            return

        # Step 2: swap pivot with rightmost element greater than it
        for j in range(n - 1, pivot, -1):
            if nums[j] > nums[pivot]:
                nums[j], nums[pivot] = nums[pivot], nums[j]
                break

        # Step 3: reverse suffix after pivot
        nums[pivot + 1:] = nums[pivot + 1:][::-1]
