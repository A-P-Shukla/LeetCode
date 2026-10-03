class Solution:
    """
    Longest Valid Parentheses – O(n) time, O(n) space using a stack.
    The stack holds indices that act as boundaries for the current
    valid substring. A sentinel -1 is used to simplify length calculation.
    """
    def longestValidParentheses(self, s: str) -> int:
        max_len = 0
        stack = [-1]                       # sentinel index

        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)            # potential start of a valid block
            else:  # ch == ')'
                stack.pop()                # try to match with a '('
                if not stack:
                    stack.append(i)        # no match, new sentinel
                else:
                    max_len = max(max_len, i - stack[-1])

        return max_len