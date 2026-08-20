from typing import List

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        # Initialize arr1 and arr2 with the first two elements
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        
        # Process the remaining elements based on given conditions
        for i in range(2, len(nums)):
            if arr1[-1] > arr2[-1]:
                arr1.append(nums[i])
            else:
                arr2.append(nums[i])
                
        # Return the concatenated result
        return arr1 + arr2