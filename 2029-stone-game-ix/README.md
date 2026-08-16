# 2029. Stone Game IX

Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Math, Greedy, Game Theory
Date | August 16, 2026
LeetCode Link | [https://leetcode.com/problems/stone-game-ix/](https://leetcode.com/problems/stone-game-ix/)

## Intuition

The core of this problem lies in understanding how the sum of removed stones modulo 3 behaves. There are three types of stones based on their value modulo 3:
1.  **Type 0**: $value \equiv 0 \pmod 3$
2.  **Type 1**: $value \equiv 1 \pmod 3$
3.  **Type 2**: $value \equiv 2 \pmod 3$

### Key Observations:
1.  **Type 0 stones are "turn-swappers"**: Adding a Type 0 stone doesn't change the sum modulo 3, but it does change whose turn it is. However, Alice cannot pick a Type 0 stone on her first move because the initial sum is 0, and $0 + 0 = 0$, which is divisible by 3 (making her lose immediately).
2.  **The losing sequences**: Once a starting stone (Type 1 or Type 2) is chosen, the players are forced into a specific alternating pattern to avoid a sum divisible by 3:
    *   If Alice starts with **Type 1**: The sequence must be `1, 1, 2, 1, 2, 1, 2...`
    *   If Alice starts with **Type 2**: The sequence must be `2, 2, 1, 2, 1, 2, 1...`
3.  **The Role of Parity**: Since Type 0 stones only flip the turn, their total count's parity determines if Alice's original strategy still works or if Bob can use the 0s to force her into a losing position.

### Winning Conditions:
*   **Case 1: Even number of Type 0 stones**:
    The 0s effectively cancel each other out. Alice wins if she can pick a path (starting with 1 or 2) that forces Bob to eventually pick a stone that makes the sum divisible by 3. This is possible as long as both Type 1 and Type 2 stones exist (`min(cnt1, cnt2) > 0`).
    
*   **Case 2: Odd number of Type 0 stones**:
    The extra 0 stone allows Bob to flip the turn exactly once. Alice now needs a significant surplus of one type to ensure that even after the turn flip, Bob is the one who runs out of valid moves or is forced to lose. Mathematically, this happens if the difference between Type 1 and Type 2 stones is greater than 2 (`abs(cnt1 - cnt2) > 2`).

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of stones. We iterate through the array once to count the remainders.
- **Space Complexity**: $O(1)$, as we only store three integer counters regardless of the input size.
