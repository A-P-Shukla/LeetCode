class Solution:
    def sumWaviness(self, num1: int, num2: int) -> int:
        total_waviness = 0
        
        for num in range(num1, num2 + 1):
            s = str(num)
            length = len(s)
            if length < 3:
                continue
            
            # Count peaks and valleys
            for i in range(1, length - 1):
                if (s[i] > s[i - 1] and s[i] > s[i + 1]) or (s[i] < s[i - 1] and s[i] < s[i + 1]):
                    total_waviness += 1
                    
        return total_waviness