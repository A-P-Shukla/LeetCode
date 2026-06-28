class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: list[int]) -> int:
        # Sort the array to process elements in non-decreasing order
        arr.sort()
        
        # Condition: The first element must be 1
        arr[0] = 1
        
        # Iterate through the array to enforce the constraint:
        # abs(arr[i] - arr[i-1]) <= 1
        for i in range(1, len(arr)):
            # If the current element is significantly larger than the previous one,
            # we reduce it to the maximum allowable value (prev + 1).
            if arr[i] > arr[i - 1] + 1:
                arr[i] = arr[i - 1] + 1
        
        # The last element will be the maximum possible value
        return arr[-1]