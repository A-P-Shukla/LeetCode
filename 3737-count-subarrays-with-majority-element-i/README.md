# 3737. Count Subarrays With Majority Element I

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, Counting, Prefix Sum |
| Date | 2026-06-25 |
| LeetCode Link | [https://leetcode.com/problems/count-subarrays-with-majority-element-i/](https://leetcode.com/problems/count-subarrays-with-majority-element-i/) |

### Intuition

The problem asks us to find the number of subarrays where a specific `target` value appears strictly more than half the time. 

For a subarray of length $L$, let $c$ be the count of the `target` element. The condition "majority element" means $c > L/2$, which is equivalent to $2c > L$. We can rewrite this as $2c - L > 0$.

Let's transform the array `nums` into a new array `A` where:
- $A[i] = 1$ if `nums[i] == target`
- $A[i] = -1$ if `nums[i] != target`

Now, the sum of any subarray in $A$ from index $i$ to $j$ is $(count\_of\_target) - (count\_of\_others)$. 
Let $c$ be the count of `target` and $o$ be the count of other elements. 
The length $L = c + o$. 
The subarray sum is $c - o$. 
Since $o = L - c$, the sum is $c - (L - c) = 2c - L$.

The condition $2c - L > 0$ translates exactly to the subarray sum being strictly greater than $0$. Given the constraint $N \le 1000$, an $O(N^2)$ approach is perfectly acceptable. We can iterate through all possible starting positions $i$ and for each start, iterate through all ending positions $j$, maintaining the running sum of the transformed values.

### Complexity Analysis

- **Time Complexity**: $O(N^2)$, where $N$ is the length of `nums`. We use two nested loops to check all $N(N+1)/2$ possible subarrays.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to keep track of counts and sums, without requiring extra data structures relative to the input size.