# 3612. Process String with Special Operations I

| Property | Value |
| :--- | :--- |
| Difficulty | Medium |
| Topics | String, Simulation |
| Date | 2026-06-16 |
| LeetCode Link | [Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/) |

### Intuition

The problem asks us to simulate a sequence of operations on a string. Since the constraints are very small (`s.length <= 20`), we do not need to worry about the efficiency of operations like string concatenation, reversal, or duplication. A direct simulation using a mutable string structure is sufficient.

1.  **Lowercase English Letters:** Simply append the character to our current working string.
2.  **`*` (Remove):** If the string is not empty, remove the last character. This acts like a `pop_back` operation in a stack.
3.  **`#` (Duplicate):** Append the entire current string to itself. This effectively doubles the size of the string.
4.  **`%` (Reverse):** Reverse the characters in the current string.

By processing the input string `s` from left to right and applying these rules to a mutable buffer (like `std::string` in C++ or a list of characters/string in Python), we can reach the final state easily.

### Complexity Analysis

*   **Time Complexity:** O(N * L), where N is the length of `s` and L is the maximum length the `result` string reaches during the simulation. Since L can grow exponentially with `#` operations, but N is limited to 20, the maximum length remains small enough that this simulation performs well within the time limits.
*   **Space Complexity:** O(L), where L is the length of the resulting string, required to store the state of the `result` string.