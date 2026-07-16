# 3867. Sum of GCD of Formed Pairs

| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Two Pointers, Sorting, Simulation, Number Theory |
| Date | 2026-07-16 |
| LeetCode Link | [Sum of GCD of Formed Pairs](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/) |

### Intuition

To solve this problem, we need to break the process down into two distinct phases: transformation and aggregation.

1.  **Transformation (Constructing `prefixGcd`):**
    We iterate through the input array while maintaining the running maximum of elements seen so far. At each index `i`, the value to store in our `prefixGcd` array is `gcd(nums[i], running_max)`. Since we only need the running maximum, this phase can be completed in $O(n)$ time using a simple loop.

2.  **Aggregation (Pairing and Summing):**
    Once we have the `prefixGcd` array, the problem dictates a specific pairing strategy: sort the array and pair the smallest with the largest, moving inward.
    - Sorting the `prefixGcd` array takes $O(n \log n)$.
    - After sorting, we use a two-pointer approach (one at the start `left`, one at the end `right`) to form pairs. While `left < right`, we calculate `gcd(prefixGcd[left], prefixGcd[right])`, add it to our running total, and increment `left` while decrementing `right`.

The core logic relies on the properties of the GCD function (Euclidean algorithm) and efficient array manipulation. By separating the construction and the processing, the implementation remains clean and performant.

### Complexity Analysis

*   **Time Complexity:** $O(n \log n + n \log(\max(\text{nums})))$.
    - Constructing `prefixGcd` takes $O(n \cdot \log(\max(\text{nums})))$ due to the GCD calculation at each step.
    - Sorting takes $O(n \log n)$.
    - The two-pointer pairing takes $O(n \cdot \log(\max(\text{nums})))$ due to the GCD of each pair.
    - Overall, the $O(n \log n)$ term dominates if the values are reasonable, otherwise the GCD operations are the bottleneck.
*   **Space Complexity:** $O(n)$.
    - We require $O(n)$ space to store the `prefixGcd` array.