class Solution:
    def getMinDistance(self, nums: list[int], target: int, start: int) -> int:
        """
        Finds the minimum absolute distance |i - start| such that nums[i] == target.
        
        :param nums: List of integers.
        :param target: Integer value to search for.
        :param start: Starting index for distance calculation.
        :return: The minimum absolute distance.
        """
        # Initialize min_dist with a value larger than any possible distance in the array
        min_dist = float('inf')
        
        for i, num in enumerate(nums):
            if num == target:
                # Calculate the absolute difference
                current_dist = abs(i - start)
                
                # Update minimum if a smaller distance is found
                if current_dist < min_dist:
                    min_dist = current_dist
                
                # Optimization: if we find distance 0, we can return immediately
                if min_dist == 0:
                    return 0
                    
        return int(min_dist)