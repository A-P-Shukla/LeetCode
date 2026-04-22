class Solution:
    def wordsWithinTwoEdits(self, queries: list[str], dictionary: list[str]) -> list[str]:
        ans = []
        
        for query in queries:
            # Check this query against every word in the dictionary
            for word in dictionary:
                diff_count = 0
                # All words have same length, so we can iterate by index
                for char_q, char_w in zip(query, word):
                    if char_q != char_w:
                        diff_count += 1
                    
                    # Optimization: stop comparing if we exceed 2 edits
                    if diff_count > 2:
                        break
                
                # If the Hamming distance is 2 or less, the query is valid
                if diff_count <= 2:
                    ans.append(query)
                    break
                    
        return ans