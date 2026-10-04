# 678. Valid Parenthesis String

Metadata Table:
Property | Value
--- | ---
Difficulty | Medium
Topics | String, Dynamic Programming, Stack, Greedy, Bracket Sequences
Date | 2026-10-04
LeetCode Link | https://leetcode.com/problems/valid-parenthesis-string/

Intuition
The character ‘*’ can behave as ‘(’, ‘)’ or an empty string, which means the exact number of open parentheses is not fixed while scanning the string.  
Instead of tracking a single count of unmatched ‘(’, maintain a **range** `[low, high]` representing the minimal and maximal possible number of open '(' at the current position:

- When we see ‘(’, both `low` and `high` increase by 1 because any interpretation adds one open parenthesis.
- When we see ‘)’, both `low` and `high` decrease by 1 because a right parenthesis must close a previously opened one.
- When we see ‘*’, it can be ‘(’, ‘)’, or empty, so `low` can decrease by 1 (treat it as ‘)’), and `high` can increase by 1 (treat it as ‘(’). `low` is never allowed to go below 0 because we cannot have a negative number of unmatched '('.

If at any point `high` becomes negative, there are more mandatory ‘)’ than possible ‘(’, so the string is invalid. After processing the whole string, the string is valid if the minimal possible open count `low` is 0 – meaning there exists an interpretation that balances all parentheses.

Complexity Analysis
- Time Complexity: O(n), where n is the length of the string, because we scan it once.
- Space Complexity: O(1), only two integer variables are used regardless of input size.