class Solution:
    def countSubarrays(self, nums: list[int], target: int) -> int:
        """
        Calculates the number of subarrays where target is the majority element.
        Uses an O(N^2) approach suitable for N <= 1000.
        """
        n = len(nums)
        valid_subarrays = 0
        
        for i in range(n):
            count_target = 0
            for j in range(i, n):
                if nums[j] == target:
                    count_target += 1
                
                length = j - i + 1
                # Majority condition: count_target > length / 2
                # Equivalent to 2 * count_target > length
                if 2 * count_target > length:
                    valid_subarrays += 1
                    
        return valid_subarrays