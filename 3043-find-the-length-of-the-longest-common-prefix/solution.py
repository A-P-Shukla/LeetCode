class Solution:
    def longestCommonPrefix(self, arr1: list[int], arr2: list[int]) -> int:
        prefixes = set()
        
        # Step 1: Add all possible prefixes from arr1 into the set
        for val in arr1:
            while val > 0:
                prefixes.add(val)
                val //= 10
                
        max_len = 0
        
        # Step 2: Check prefixes from arr2, going from longest to shortest
        for val in arr2:
            length = len(str(val))
            
            # Pruning: skip if the number of digits is already smaller than or equal to max_len
            if length <= max_len:
                continue
                
            while val > 0:
                if val in prefixes:
                    max_len = max(max_len, length)
                    break # First match going downwards is always the longest possible for this number
                
                val //= 10
                length -= 1
                
                # Early exit: no need to search shorter prefixes if they cannot beat max_len
                if length <= max_len:
                    break
                    
        return max_len