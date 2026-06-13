class Solution:
    def weightedWordMapping(self, words: list[str], weights: list[int]) -> str:
        result = []
        
        for word in words:
            # Calculate total weight of the word
            total_weight = sum(weights[ord(char) - ord('a')] for char in word)
            
            # Map the weight modulo 26 to a char in reverse alphabetical order
            # 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            remainder = total_weight % 26
            mapped_char = chr(ord('z') - remainder)
            
            result.append(mapped_char)
            
        return "".join(result)