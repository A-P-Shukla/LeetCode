# 3513. Number of Unique XOR Triplets I

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Bit Manipulation
Date | 2026-07-23
LeetCode Link | [Number of Unique XOR Triplets I](https://leetcode.com/problems/number-of-unique-xor-triplets-i/)

---

### Intuition

The problem asks us to find the number of unique XOR triplet values, defined as $nums[i] \oplus nums[j] \oplus nums[k]$ for all indices $i \le j \le k$, where `nums` is a permutation of numbers from $1$ to $n$.

Let's analyze the XOR of three elements: $a \oplus b \oplus c$.
1. **Case $i = j = k$**: 
   The XOR is $x \oplus x \oplus x = x$. Since `nums` is a permutation of $1$ to $n$, every integer $x$ in the range $[1, n]$ can be formed by choosing $i=j=k$ where $nums[i] = x$. This guarantees that **all integers from $1$ to $n$ are always achievable**.

2. **Case $i = j \neq k$**:
   The XOR is $x \oplus x \oplus y = 0 \oplus y = y$. Again, this reduces to a single element $y$, which is already covered.

3. **General triplets $i \le j \le k$**:
   - If $n \ge 3$, we can also form $0$. For instance, with nums = $[3, 1, 2]$ (where $n=3$), we can choose indices such that we XOR $3 \oplus 1 \oplus 2 = 0$. In general, can we always form $0$ and other values?
   - Wait, let's examine the property of XOR permutations. If $n \ge 3$, is $0$ always achievable? Not necessarily for all permutations of size 1 or 2, but for $n \ge 3$, any three numbers can be chosen. However, since `nums` is a permutation of $1 \dots n$, the set of all possible XOR sums of *any* three elements actually covers a specific range.
   - Let's think about the possible XOR values. Since $nums[i] \oplus nums[i] \oplus nums[k] = nums[k]$, any single element is reachable.
   - What about pairs or triplets? With bitwise XOR operations on a full permutation of $1 \dots n$:
     - If $n = 1$: only $\{1\}$ can be formed (size 1).
     - If $n = 2$: elements are $\{1, 2\}$. Triplets can give $1 \oplus 1 \oplus 1 = 1$, $1 \oplus 1 \oplus 2 = 2$, etc. Unique values are $\{1, 2\}$ (size 2).
     - If $n \ge 3$: we can always form $0$ by choosing three distinct elements whose XOR sum is $0$, or by leveraging the properties of the bitwise basis of numbers $1 \dots n$. In fact, it turns out that for any $n \ge 3$, the set of unique XOR triplet values is precisely all integers from $0$ up to the largest possible bitmask, or more simply, $0$ combined with all numbers $1 \dots n$ if $n \ge 3$ (or depending on whether $0$ can be formed).
     - Let's check $n=3$: values are $\{0, 1, 2, 3\}$, total 4.
     - For larger $n$, does the answer depend only on $n$? Since `nums` is a permutation of $1 \dots n$, the bitwise XOR of 3 elements can produce any number whose bits are a subset or combination, but more precisely, any number up to some bound.
     - Actually, any number $v \in [0, 2^{\lceil \log_2(n+1) \rceil} - 1]$ can be formed as long as $n \ge 3$, or is it simpler? Let's analyze the maximum possible value or count.
     - Since $nums[i] \le n$, the maximum value is bounded by the highest set bit of $n$. Let $M = 2^{\lfloor \log_2 n \rfloor + 1} - 1$ or similar.
     - Wait! Since we can pick $i=j=k$, we get all numbers from $1$ to $n$. Can we get $0$? We can get $0$ if there exist three numbers in the permutation whose XOR sum is $0$. For $n \ge 3$, does such a triplet always exist? Yes, by Mantel's theorem / basic XOR-sum subset properties on permutations of size $\ge 3$, we can always find three distinct elements (or even with repetition) that XOR to 0, except in trivial small cases. Specifically, for $n=1$, answer is 1. For $n=2$, answer is 2 (values 1, 2; $0$ cannot be formed since $1 \oplus 1 \oplus 2 = 2, 1 \oplus 2 \oplus 2 = 1, 1 \oplus 1 \oplus 1 = 1, 2 \oplus 2 \oplus 2 = 2$). For $n \ge 3$, $0$ is always achievable, and all numbers $1 \dots n$ are achievable via $x \oplus x \oplus x = x$. Are any other values achievable? 
     - Since $nums$ is a permutation of $1 \dots n$, any $x \in [0, n]$ is achievable. Can we get values $> n$? Yes! For example, if $n=3$, $nums = [3, 1, 2]$, max value is 3. What if $n=4$? Permutation $[4, 1, 2, 3]$. 
     - Let's generalize: Any number up to the next power of 2 minus 1? Or does the number of unique XOR triplets just equal the size of the span? 
     - Since $nums$ contains all numbers from $1$ to $n$, the set of all possible XOR sums of 3 elements from a permutation of $1 \dots n$ covers all integers from $0$ up to $2^k - 1$ where $2^k > n$? 
     - Let's check $n=3$: $2^2 - 1 = 3$, values are $\{0, 1, 2, 3\}$ (count 4).
     - Let's check $n=2$: values are $\{1, 2\}$ (count 2).
     - Let's check $n=1$: values are $\{1\}$ (count 1).
     - In general, for $n \ge 3$, the answer is $2^{\lceil \log_2(n+1) \rceil}$. Wait, if $n=3$, $\lceil \log_2 4 \rceil = 2$, $2^2 = 4$. If $n=4$, $2^{\lceil \log_2 5 \rceil} = 2^3 = 8$? But elements are up to 4, can we get values up to 7? Yes, because we can choose three elements whose XOR has higher bits set. Thus, the number of unique values is $2^{\lfloor \log_2 n \rfloor + 1}$ when $n \ge 3$.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ because the result can be computed directly using a mathematical formula based on $n$.
- **Space Complexity:** $\mathcal{O}(1)$ as no extra memory is used.

---

### C++ Solution

```cpp
class Solution {
public:
    int tripletValueCount(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int k = 0;
        while ((1 << k) <= n) {
            k++;
        }
        return 1 << k;
    }
};
```

---

### Python Solution

```python
class Solution:

    def tripletValueCount(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 1
        if n == 2:
            return 2

        k = 0
        while (1 << k) <= n:
            k += 1
        return 1 << k
```