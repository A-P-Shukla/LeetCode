class Solution:
    def checkDivisibility(self, n: int) -> bool:
        digit_sum = 0
        digit_product = 1
        temp = n

        # Extract digits and calculate sum and product
        while temp > 0:
            digit = temp % 10
            digit_sum += digit
            digit_product *= digit
            temp //= 10

        total = digit_sum + digit_product

        # Check divisibility
        return n % total == 0