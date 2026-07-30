class Solution:
    def minimumPushes(self, word: str) -> int:
        total_pushes = 0
        n = len(word)
        for i in range(n):
            total_pushes += (i // 8) + 1
        
        return total_pushes