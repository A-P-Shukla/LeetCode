class Solution:
    def concatenateNonZeroDigitsAndMultiplyBySum(self, n: int) -> int:
        # Convert n to string to easily iterate over digits
        s = str(n)
        
        # Extract non-zero digits
        x_str = "".join([digit for digit in s if digit != '0'])
        
        # If no non-zero digits, result is 0
        if not x_str:
            return 0
            
        x = int(x_str)
        
        # Calculate sum of digits of x
        digit_sum = sum(int(digit) for digit in x_str)
        
        return x * digit_sum