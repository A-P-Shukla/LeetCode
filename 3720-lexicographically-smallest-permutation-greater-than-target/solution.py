class Solution:
    def nextPermutation(self, s: str, target: str) -> str:
        n = len(s)
        counts = [0] * 26
        
        # Count frequencies of characters in s
        for char in s:
            counts[ord(char) - ord('a')] += 1
            
        # Find maximum prefix length L of target that s can match
        L = 0
        while L < n and counts[ord(target[L]) - ord('a')] > 0:
            counts[ord(target[L]) - ord('a')] -= 1
            L += 1
            
        # If target was completely matched, adjust L to n - 1 and restore target[n - 1]
        if L == n:
            L -= 1
            counts[ord(target[L]) - ord('a')] += 1
            
        # Try to find the largest index i where we can place a character > target[i]
        for i in range(L, -1, -1):
            target_char_idx = ord(target[i]) - ord('a')
            
            # Look for the smallest available character > target[i]
            replacement_char = -1
            for c in range(target_char_idx + 1, 26):
                if counts[c] > 0:
                    replacement_char = c
                    break
                    
            if replacement_char != -1:
                # Found a valid configuration! Construct the answer string
                res = list(target[:i])
                
                # Place the strictly greater character
                res.append(chr(ord('a') + replacement_char))
                counts[replacement_char] -= 1
                
                # Fill the rest with remaining characters in ascending order
                for c in range(26):
                    while counts[c] > 0:
                        res.append(chr(ord('a') + c))
                        counts[c] -= 1
                        
                return "".join(res)
                
            # Backtrack target[i - 1] for index i - 1
            if i > 0:
                counts[ord(target[i - 1]) - ord('a')] += 1
                
        return ""