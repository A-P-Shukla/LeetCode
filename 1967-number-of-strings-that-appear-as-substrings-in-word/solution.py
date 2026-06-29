class Solution:
    def numOfStrings(self, patterns: list[str], word: str) -> int:
        count = 0
        
        # Iterate through each pattern in the list
        for pattern in patterns:
            # The 'in' operator in Python efficiently checks 
            # if a substring exists within a string.
            if pattern in word:
                count += 1
                
        return count