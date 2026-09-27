class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        partner = [-1] * n           # partner[i] = matching parenthesis index
        stack = []                    # indices of '('

        # Build matching pairs
        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)
            elif ch == ')':
                j = stack.pop()
                partner[i] = j
                partner[j] = i

        res = []
        i, step = 0, 1                # start scanning forward

        while i < n:
            if s[i] in '()':
                i = partner[i]       # jump to the matching bracket
                step = -step          # reverse traversal direction
            else:
                res.append(s[i])
            i += step

        return ''.join(res)