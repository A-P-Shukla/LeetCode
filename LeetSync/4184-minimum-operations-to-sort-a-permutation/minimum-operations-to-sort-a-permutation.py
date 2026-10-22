class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)

        zero_index = nums.index(0)

        def is_sorted_with_step(step: int) -> bool:
            for i in range(1, n):
                prev_pos = (zero_index + (i - 1) * step) % n
                curr_pos = (zero_index + i * step) % n

                if nums[prev_pos] > nums[curr_pos]:
                    return False

            return True

        answer = inf

        if is_sorted_with_step(1):
            answer = min(answer, zero_index)
            answer = min(answer, n - zero_index + 2)

        if is_sorted_with_step(-1):
            answer = min(answer, zero_index + 2)
            answer = min(answer, n - zero_index)

        return -1 if answer == inf else answer