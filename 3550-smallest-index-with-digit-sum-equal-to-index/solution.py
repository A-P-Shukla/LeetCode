class Solution:
    def smallestIndex(self, nums: list[int]) -> int:
        def get_digit_sum(n: int) -> int:
            total = 0
            while n > 0:
                total += n % 10
                n //= 10
            return total

        for i, num in enumerate(nums):
            # Check if the sum of digits equals the current index
            if get_digit_sum(num) == i:
                return i  # Return immediately as enumerate iterates in increasing order

        return -1  # No valid index found