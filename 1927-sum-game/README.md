# 1927. Sum Game

### Metadata Table
Property | Value
--- | ---
Difficulty | Medium
Topics | Math, Greedy, Game Theory, String
Date | 2026-08-23
LeetCode Link | https://leetcode.com/problems/sum-game/

### Intuition

The game consists of two players, Alice and Bob, placing digits into missing positions (`'?'`) of a string of even length $N$. Alice aims to make the sum of the first half unequal to the sum of the second half, while Bob aims to make them equal.

Let's break down the mechanics:
1. **Symmetry and Cancellation**: If there are `'?'` characters on both the left and right halves, Bob can mirror Alice's moves. Whenever Alice places a digit $d$ on one side, Bob can place the exact same digit $d$ on the opposite side. This neutralizes one `'?'` from each half without changing the net difference between the two sides. Therefore, we can effectively cancel out $\min(L_q, R_q)$ question marks from both sides.
2. **Remaining Question Marks**: After cancellation, all remaining $q = |L_q - R_q|$ question marks will be on one side (say, the side with more question marks).
3. **Turn Parity**: 
   - If the total number of question marks $(L_q + R_q)$ is odd, Alice gets the final turn. On her final turn, at most one single digit could make the two halves equal. Since Alice has 10 digit choices ($0$ through $9$), she can always pick a digit that makes the sums unequal and wins.
   - If the total number of question marks is even, Bob gets the final turn. For the $q$ remaining question marks on one side (where $q$ is even), Bob can pair his turns with Alice's. Whenever Alice plays a digit $d$, Bob can play $9 - d$ on the same side. This guarantees that every pair of question marks contributes exactly $9$ to that side's sum.
4. **Bob's Winning Condition**:
   - Bob can force the $q$ question marks on the heavier side to sum to $\frac{q}{2} \times 9$.
   - If the initial sum difference between the two halves is not balanced by this exact amount, Alice can exploit it by playing all $0$s (if the difference is too large) or all $9$s (if the difference is too small), rendering it impossible for Bob to equalize the sums.

Thus, Bob wins if and only if:
$$2 \times (L_{sum} - R_{sum}) + 9 \times (L_q - R_q) = 0$$

If this linear equation holds, Bob wins (`false`). Otherwise, Alice wins (`true`). Note that if $L_q + R_q$ is odd, $L_q - R_q$ is also odd, making the equation impossible to satisfy since $2(L_{sum} - R_{sum})$ is even and $9(L_q - R_q)$ is odd.

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ where $N$ is the length of string `num`, because we iterate through the string in a single pass to compute the sums and count of `'?'`.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space as we only use a few integer variables.