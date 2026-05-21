class Solution:
    def findLengthOfLongestCommonPrefix(self, arr1: list[int], arr2: list[int]) -> int:
        prefixes = set()
        
        # Step 1: Store all prefixes of elements in arr1
        for x in arr1:
            while x > 0:
                prefixes.add(x)
                x //= 10
        
        max_length = 0
        
        # Step 2: Find the longest prefix for each element in arr2
        for y in arr2:
            while y > 0 and y not in prefixes:
                y //= 10
            if y > 0:
                max_length = max(max_length, len(str(y)))
                
        return max_length