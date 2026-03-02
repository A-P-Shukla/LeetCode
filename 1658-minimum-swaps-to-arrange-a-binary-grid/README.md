# 1536. Minimum Swaps to Arrange a Binary Grid

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Greedy, Matrix
Date | March 2, 2025
LeetCode Link | [https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)

## Intuition

The problem asks for the minimum number of adjacent row swaps to make all elements above the main diagonal zero. This requirement translates to a specific constraint for each row $i$ (where $0 \le i < n$): the row at index $i$ must end with at least $n - 1 - i$ zeros.

Because we can only swap adjacent rows, this problem is essentially a variation of the logic used in Bubble Sort. To achieve the minimum number of swaps, we should use a **Greedy approach**:
1.  First, calculate the number of trailing zeros for every row in the initial grid.
2.  Iterate through each row position $i$ from $0$ to $n-1$.
3.  For the current position $i$, we need a row that has at least $k = n - 1 - i$ trailing zeros. 
4.  Search the current and subsequent rows (from index $i$ to $n-1$) to find the first row $j$ that satisfies this requirement.
5.  If such a row is found at index $j$, "bubble" it up to index $i$ by performing $j - i$ adjacent swaps. This effectively shifts rows between $i$ and $j-1$ down by one.
6.  If no such row exists for a specific position $i$, it is impossible to satisfy the condition, and we return -1.

The reason searching for the *first* available row is optimal is that moving the closest valid row to the current position minimizes the displacement of other rows, which is characteristic of the inversion counting logic in adjacent swap problems.

## Complexity Analysis

### Time Complexity: $O(n^2)$
- Preprocessing the trailing zeros for $n$ rows takes $O(n \times n) = O(n^2)$.
- The main greedy loop runs $n$ times. In each iteration, we might search up to $n$ rows and perform a shift operation that takes $O(n)$.
- Total complexity is $O(n^2)$, which is well within the limits for $n = 200$.

### Space Complexity: $O(n)$
- we store the count of trailing zeros for each row in a separate vector of size $n$.
