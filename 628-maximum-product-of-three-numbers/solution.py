class Solution:
    def maximumProduct(self, nums: list[int]) -> int:
        # Track three largest elements
        max1 = max2 = max3 = float('-inf')
        # Track two smallest elements
        min1 = min2 = float('inf')

        for n in nums:
            # Update the top 3 maximums
            if n > max1:
                max3, max2, max1 = max2, max1, n
            elif n > max2:
                max3, max2 = max2, n
            elif n > max3:
                max3 = n

            # Update the top 2 minimums
            if n < min1:
                min2, min1 = min1, n
            elif n < min2:
                min2 = n

        # Compare the product of 3 largest vs. 2 smallest and 1 largest
        return max(max1 * max2 * max3, min1 * min2 * max1)