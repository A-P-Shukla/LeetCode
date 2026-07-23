class Solution:
    def uniqueXorTriplets(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Base cases
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        # For n >= 3, the answer is 2^(bit_length(n))
        return 1 << n.bit_length()