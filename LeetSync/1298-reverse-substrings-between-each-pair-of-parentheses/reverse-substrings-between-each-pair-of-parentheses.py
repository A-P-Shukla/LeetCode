class Solution:
    def reverseParentheses(self, s: str) -> str:
        n = len(s)
        partner = [-1] * n           
        stack = []                   
        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)
            elif ch == ')':
                j = stack.pop()
                partner[i] = j
                partner[j] = i

        res = []
        i, step = 0, 1                

        while i < n:
            if s[i] in '()':
                i = partner[i]       
                step = -step          
            else:
                res.append(s[i])
            i += step

        return ''.join(res)