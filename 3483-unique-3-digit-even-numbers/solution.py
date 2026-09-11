from collections import Counter

class Solution:
    def countEvenNumbers(self, digits: list[int]) -> int:
        # Step 1: Count available digit frequencies
        freq = Counter(digits)
        distinct_count = 0
        
        # Step 2: Iterate through all valid 3-digit even numbers
        for num in range(100, 1000, 2):
            hundred = num // 100
            ten = (num // 10) % 10
            unit = num % 10
            
            num_freq = Counter([hundred, ten, unit])
            
            # Step 3: Check if available digits can construct this number
            if all(num_freq[d] <= freq[d] for d in num_freq):
                distinct_count += 1
                
        return distinct_count