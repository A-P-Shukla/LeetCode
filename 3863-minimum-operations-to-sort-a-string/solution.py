from typing import List

class Solution:
    def minimumOperations(self, s: str) -> int:
        n: int = len(s)
        t: str = ''.join(sorted(s))
        if s == t:
            return 0                           # already sorted
        if n == 2:
            return -1                          # cannot sort the whole string

        # locate first and last mismatching positions
        L: int = 0
        while L < n and s[L] == t[L]:
            L += 1
        R: int = n - 1
        while R >= 0 and s[R] == t[R]:
            R -= 1

        # if the mismatching segment is a proper substring, one operation works
        if L > 0 or R < n - 1:
            return 1
        # otherwise exactly two operations are sufficient
        return 2