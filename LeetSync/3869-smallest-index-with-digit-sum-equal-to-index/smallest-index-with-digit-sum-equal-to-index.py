class Solution:
    def smallestIndex(self, nums: list[int]) -> int:
        def get_digit_sum(n: int) -> int:
            total = 0
            while n > 0:
                total += n % 10
                n //= 10
            return total

        for i, num in enumerate(nums):
            if get_digit_sum(num) == i:
                return i

        return -1