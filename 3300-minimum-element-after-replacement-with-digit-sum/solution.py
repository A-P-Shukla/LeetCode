class Solution:
    def minElement(self, nums: list[int]) -> int:
        def get_digit_sum(n: int) -> int:
            digit_sum = 0
            while n > 0:
                digit_sum += n % 10
                n //= 10
            return digit_sum
        
        # Generator expression to find the minimum digit sum efficiently
        return min(get_digit_sum(num) for num in nums)