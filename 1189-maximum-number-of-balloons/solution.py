from collections import Counter

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        # Count frequency of each character in the input text
        counts = Counter(text)
        
        # Calculate how many of each required character we have
        # For 'l' and 'o', we need 2 of each per word
        b = counts['b']
        a = counts['a']
        l = counts['l'] // 2
        o = counts['o'] // 2
        n = counts['n']
        
        # The maximum number of balloons is limited by the smallest frequency
        return min(b, a, l, o, n)