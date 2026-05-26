class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        # Sets to store unique lowercase and uppercase characters
        lowers = set()
        uppers = set()
        
        for char in word:
            if char.islower():
                lowers.add(char)
            else:
                uppers.add(char.lower())
                
        # The number of special letters is the size of the intersection
        return len(lowers.intersection(uppers))