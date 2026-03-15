# 1622. Fancy Sequence

Property | Value
--- | ---
Difficulty | Hard
Topics | Math, Design, Segment Tree
Date | March 15, 2026
LeetCode Link | [https://leetcode.com/problems/fancy-sequence/](https://leetcode.com/problems/fancy-sequence/)

### Intuition
The problem asks us to maintain a sequence where we can add elements and perform range updates (addition and multiplication) on all existing elements. A naive approach of updating every element in the array for every `addAll` or `multAll` operation would lead to $O(N^2)$ time complexity, which is too slow given the $10^5$ constraints.

The key observation is that any sequence of linear operations (addition and multiplication) can be compressed into a single linear transformation of the form $f(x) = (a \cdot x + b) \pmod M$. 

1.  **Global State:** We maintain two variables, `multiplier` ($a$) and `increment` ($b$), representing the cumulative transformation applied to the sequence since the beginning.
2.  **Appending:** When we append a value $v$ at a time when the global transformation is $f(x) = ax + b$, we need to store a "normalized" value $x_i$ such that when the current transformation is applied, it results in $v$. This is solved by:
    $a \cdot x_i + b \equiv v \pmod M \implies x_i \equiv (v - b) \cdot a^{-1} \pmod M$
3.  **Modular Inverse:** Since $M = 10^9 + 7$ is prime, we can find the modular multiplicative inverse $a^{-1}$ using Fermat's Little Theorem: $a^{M-2} \pmod M$.
4.  **Retrieval:** To get the value at index `idx`, we simply apply the *current* global $a$ and $b$ to the stored normalized value: $result = (a \cdot x_{idx} + b) \pmod M$.

### Complexity Analysis
- **Time Complexity:**
    - `append(val)`: $O(\log M)$ to calculate the modular inverse using binary exponentiation.
    - `addAll(inc)`: $O(1)$ to update the global increment.
    - `multAll(m)`: $O(1)$ to update the global multiplier and increment.
    - `getIndex(idx)`: $O(1)$ to perform the linear transformation.
- **Space Complexity:** $O(N)$ where $N$ is the number of elements appended, to store the normalized values.