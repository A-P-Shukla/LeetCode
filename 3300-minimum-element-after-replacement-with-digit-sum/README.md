# 3300. Minimum Element After Replacement With Digit Sum


Property | Value
--- | ---
Difficulty | Easy
Topics | Array, Math
Date | May 29, 2026
LeetCode Link | [Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)

### Intuition
The problem asks us to transform each number in the array `nums` into its digit sum and then find the minimum of these resulting sums. 

To solve this efficiently:
1. We can process each number in the array one by one.
2. For each number, we compute the sum of its digits. The digit sum of a positive integer $n$ can be calculated by repeatedly summing its last digit ($n \pmod{10}$) and then discarding it ($n \leftarrow \lfloor n / 10 \rfloor$) until the number becomes $0$.
3. We maintain a running minimum of these digit sums and return the overall minimum at the end.

This approach is highly optimal as it processes each element in constant time relative to the number of digits (which is at most 5 digits since $nums[i] \le 10^4$).

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N \log_{10}(M))$, where $N$ is the number of elements in `nums` and $M$ is the maximum value of an element in `nums`. Since $M \le 10^4$, each number has at most 5 digits, meaning the digit sum is calculated in $\mathcal{O}(1)$ operations. Thus, the overall time complexity is $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, as we only need a few variables to track the minimum value and individual digit sums.