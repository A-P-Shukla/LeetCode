class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        """
        Compute the score using a stack.
        0 is used as a marker for '('.
        """
        stack = []
        for ch in s:
            if ch == '(':
                stack.append(0)               # marker
            else:  # ')'
                if stack and stack[-1] == 0:   # "()"
                    stack[-1] = 1
                else:
                    inner = 0
                    while stack and stack[-1] != 0:
                        inner += stack.pop()
                    # pop the '(' marker
                    if stack:
                        stack.pop()
                    stack.append(2 * inner)
        return sum(stack)