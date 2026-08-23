class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        half = n // 2
        
        left_sum = 0
        left_q = 0
        for char in num[:half]:
            if char == '?':
                left_q += 1
            else:
                left_sum += int(char)
                
        right_sum = 0
        right_q = 0
        for char in num[half:]:
            if char == '?':
                right_q += 1
            else:
                right_sum += int(char)
                
        # Bob wins if and only if 2 * (left_sum - right_sum) + 9 * (left_q - right_q) == 0.
        # Return True if Alice wins, False if Bob wins.
        return 2 * (left_sum - right_sum) + 9 * (left_q - right_q) != 0