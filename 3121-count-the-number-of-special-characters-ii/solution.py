class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        # Track the last occurrence of lowercase letters and first occurrence of uppercase letters
        last_lower = [-1] * 26
        first_upper = [-1] * 26
        
        for i, char in enumerate(word):
            if char.islower():
                last_lower[ord(char) - ord('a')] = i
            else:
                idx = ord(char) - ord('A')
                # We only record the first occurrence of the uppercase letter
                if first_upper[idx] == -1:
                    first_upper[idx] = i
                    
        special_count = 0
        # Check conditions for each of the 26 English letters
        for i in range(26):
            if last_lower[i] != -1 and first_upper[i] != -1 and last_lower[i] < first_upper[i]:
                special_count += 1
                
        return special_count