# 2574. Left and Right Sum Differences

### Metadata Table
Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Prefix Sum
Date | June 6, 2026
LeetCode Link | [https://leetcode.com/problems/left-and-right-sum-differences/](https://leetcode.com/problems/left-and-right-sum-differences/)

### Intuition
To solve this problem efficiently, we can avoid calculating the left and right sums from scratch for every index, which would result in an $O(N^2)$ time complexity. Instead, we can utilize the prefix sum concept.

The sum of all elements in the array is `total_sum`. As we iterate through the array from left to right:
1. We keep track of a running `left_sum`, which is initially `0`.
2. For any element at index `i`, the sum of elements to its right is simply:
   $$\text{right\_sum} = \text{total\_sum} - \text{left\_sum} - \text{nums}[i]$$
3. We compute the absolute difference $|\text{left\_sum} - \text{right\_sum}|$ and store it in our results.
4. Finally, we update `left_sum` by adding the current element `nums[i]` before moving to the next index.

This mathematical relation allows us to compute the answer for each index in $O(1)$ auxiliary time.

### Complexity Analysis
- **Time Complexity:** $O(N)$ where $N$ is the number of elements in `nums`. We make one pass to calculate the total sum of the array, and a second pass to compute the prefix sums and populate the result.
- **Space Complexity:** $O(1)$ auxiliary space (excluding the output array), as we only require a few variables to maintain the running sums.