class Solution:
    def totalNumbers(self, digits: list[int]) -> int:
        freq = Counter(digits)
        distinct_count = 0
        
        for num in range(100, 1000, 2):
            hundred = num // 100
            ten = (num // 10) % 10
            unit = num % 10
            
            num_freq = Counter([hundred, ten, unit])
            
            if all(num_freq[d] <= freq[d] for d in num_freq):
                distinct_count += 1
                
        return distinct_count