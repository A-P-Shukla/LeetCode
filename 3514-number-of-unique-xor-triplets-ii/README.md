# 3514. Number of Unique XOR Triplets II

### Metadata Table
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Math, Bit Manipulation, Enumeration |
| Date | July 24, 2026 |
| LeetCode Link | [Number of Unique XOR Triplets II](https://leetcode.com/problems/number-of-unique-xor-triplets-ii/) |

---

### Intuition

The problem asks for the number of unique values produced by $nums[i] \oplus nums[j] \oplus nums[k]$ for all valid index triplets $(i, j, k)$ such that $i \le j \le k$.

Key insights:
1. **Index order does not restrict values**: Since XOR is commutative ($a \oplus b = b \oplus a$), for any set of 3 values chosen from $nums$, we can always order their original indices as $i \le j \le k$. Therefore, the order condition $i \le j \le k$ simply means we can select any 3 elements from $nums$ (with replacement).
2. **Duplicate values in `nums` add no new XOR values**: The set of achievable XOR sums depends only on the set of unique numbers present in $nums$. Let $U$ be the set of unique values in $nums$.
3. **Small range of values**: The constraints guarantee $1 \le nums[i] \le 1500$. Since $1500 < 2^{11} = 2048$, any XOR combination of values will also be strictly less than $2048$.

Instead of evaluating $O(|U|^3)$ triplets, we can build the answer iteratively in stages:
- **Pair XORs ($S_2$)**: Compute all distinct XOR results of pairs $(x, y)$ for $x, y \in U$. The size of $S_2$ is at most $2048$.
- **Triplet XORs ($S_3$)**: Compute all distinct XOR results of $w \oplus z$ for $w \in S_2$ and $z \in U$. The size of $S_3$ will also be at most $2048$.

By building $S_2$ and $S_3$ step-by-step, we reduce the problem to at most $O(|U|^2 + |S_2| \cdot |U|)$ operations, which executes in a fraction of a millisecond.

---

### Complexity Analysis

- **Time Complexity**: 
  - Extracting unique values $U$: $O(N)$, where $N = \text{nums.length} \le 1500$.
  - Generating $S_2$: $O(|U|^2)$ pair combinations, where $|U| \le 1500$.
  - Generating $S_3$: $O(|S_2| \cdot |U|)$ combinations, where $|S_2| \le 2048$ and $|U| \le 1500$.
  - Total Time Complexity: $O(N + |U|^2 + |S_2| \cdot |U|)$. With $|U| \le 1500$, total operations are capped around $4 \times 10^6$, easily running within time limits.

- **Space Complexity**: $O(MAX\_VAL)$ auxiliary space to track distinct XOR values, where $MAX\_VAL = 2048$. Thus, the auxiliary space is $O(1)$ relative to input size limits.

---