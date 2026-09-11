# 2094. Finding 3-Digit Even Numbers

### Metadata Table
| Property | Value |
| --- | --- |
| **Difficulty** | Easy |
| **Topics** | Array, Hash Table, Counting, Enumeration |
| **Date** | 2026-09-11 |
| **LeetCode Link** | [Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/) |

---

### Intuition

The task requires us to find the total number of **distinct** three-digit even numbers that can be formed using a given set of digits. Each digit in the input array can be used at most once per formed number, and the formed number cannot have a leading zero.

Instead of generating all possible permutations of 3 digits from the input array—which requires managing duplicates, leading zeros, and evenness checks—we can reverse our perspective:
1. **Fixed Search Space**: A valid three-digit even number must lie strictly in the range $[100, 998]$ and must end in an even digit. There are only $450$ such numbers.
2. **Frequency Matching**: We can build a frequency map of the given digits. Then, for each number from $100$ to $998$ (stepping by 2), we check if its constituent digits can be supplied by our available frequency count.
3. **Uniqueness**: Iterating directly through candidate numbers in range $[100, 998]$ naturally guarantees that each formed number is evaluated exactly once, eliminating the need for a set to deduplicate results.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the size of the `digits` array.
  - Frequency counting of the input digits takes $\mathcal{O}(N)$ time.
  - Iterating through candidate numbers from $100$ to $998$ takes $\mathcal{O}(1)$ time, as there are at most 450 iterations and each check takes $\mathcal{O}(1)$ constant operations.
  - Total Time Complexity: $\mathcal{O}(N)$ (or $\mathcal{O}(1)$ since $N \le 10$).

- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
  - The frequency table for available digits requires a fixed array/hash map of size 10 (for digits 0 through 9).

---