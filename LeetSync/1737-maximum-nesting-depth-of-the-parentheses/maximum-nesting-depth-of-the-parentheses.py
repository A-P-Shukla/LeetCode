class Solution:
    def maxDepth(self, s: str) -> int:
        cur = best = 0
        for ch in s:
            if ch == '(':
                cur += 1
                if cur > best:
                    best = cur
            elif ch == ')':
                cur -= 1   
        return best