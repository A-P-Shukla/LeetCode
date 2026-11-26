# 3360. Stone Removal Game
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Math, Simulation |
| Date | 2026-11-26 |
| LeetCode Link | https://leetcode.com/problems/stone-removal-game/ |

## Intuition & Approach
The game forces a *deterministic* decreasing removal sequence:  
- Alice must start by taking **10** stones.  
- Every subsequent move removes exactly one stone fewer than the opponent’s previous move.

Thus the required removal amounts are `10, 9, 8, 7, …`.  
The only decision point is whether the remaining pile can satisfy the next required amount.  
If a player cannot meet the requirement, they lose and the opponent (who made the last successful move) wins.

Because the sequence is fixed, we can simulate it directly:
1. Initialise `required = 10` and a flag indicating whose turn it is (`aliceTurn = true`).  
2. While the pile size `n` is **at least** `required` **and** `required > 0`:  
   - Subtract `required` from `n`.  
   - Decrease `required` by one (the next player must take one stone fewer).  
   - Flip the turn flag.  
3. The loop stops exactly when the player whose turn it is cannot move.  
   - If it is Alice’s turn, she loses → return `false`.  
   - Otherwise Bob cannot move → Alice wins → return `true`.

Given the constraints (`n ≤ 50`), the loop executes at most ten iterations, making the simulation O(1) time and O(1) space. No recursion or memoisation is required.

## Complexity Analysis
- **Time Complexity:** $O(k)$ where $k$ is the number of performed moves. Since `required` starts at 10 and decreases by one each move, $k \le 10$, so the algorithm runs in constant time $O(1)$.
- **Space Complexity:** $O(1)$ auxiliary space; only a few integer variables and a boolean flag are used.