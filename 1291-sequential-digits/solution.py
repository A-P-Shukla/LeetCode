class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        result = []
        digits = "123456789"
        
        # A sequential number cannot be longer than 9 digits (1-9)
        # We iterate through all possible lengths (2 to 9)
        for length in range(2, 10):
            # We iterate through all valid start indices for the given length
            for i in range(9 - length + 1):
                # Extract the sequential string
                num = int(digits[i : i + length])
                
                # Check bounds
                if low <= num <= high:
                    result.append(num)
                elif num > high:
                    # Since we iterate lengths and starts in order, 
                    # we can potentially break early if num exceeds high
                    break
        
        # Results are appended in sorted order
        return result