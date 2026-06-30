class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # Dictionary to store the frequency of 'a', 'b', and 'c'
        count = {'a': 0, 'b': 0, 'c': 0}
        left = 0
        result = 0
        n = len(s)
        
        for right in range(n):
            # Expand the window by adding the character at 'right'
            count[s[right]] += 1
            
            # While the window contains all three characters
            while count['a'] > 0 and count['b'] > 0 and count['c'] > 0:
                # If s[left...right] is valid, then s[left...right], 
                # s[left...right+1], ..., s[left...n-1] are valid substrings
                # ending at or after 'right'.
                # Actually, the logic is: for a fixed 'right', if the window
                # [left, right] is valid, all substrings starting at 0..left
                # ending at 'right' are valid.
                result += (n - right)
                
                # Shrink the window from the left to find the next valid window
                count[s[left]] -= 1
                left += 1
                
        return result