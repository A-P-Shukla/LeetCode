class Solution:
    def countCommas(self, n: int) -> int:
        total_commas = 0
        threshold = 1000
        
        # Count how many numbers reach each comma threshold (1,000, 1,000,000, etc.)
        while n >= threshold:
            total_commas += (n - threshold + 1)
            threshold *= 1000
            
        return total_commas