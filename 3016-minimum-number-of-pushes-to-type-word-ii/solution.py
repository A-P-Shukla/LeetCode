from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        # Count frequency of each character
        counts = Counter(word)
        
        # Sort frequencies in descending order
        sorted_freqs = sorted(counts.values(), reverse=True)
        
        total_pushes = 0
        # Calculate push cost based on rank (every 8 characters increment push cost)
        for i, freq in enumerate(sorted_freqs):
            multiplier = (i // 8) + 1
            total_pushes += freq * multiplier
            
        return total_pushes