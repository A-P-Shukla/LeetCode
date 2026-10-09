class Solution:
    def minInsertions(self, s: str) -> int:
        ans = 0          # total insertions performed
        need = 0         # number of ')' still required

        for ch in s:
            if ch == '(':
                need += 2               # '(' needs two ')'
                if need % 2 == 1:       # odd need → insert one ')'
                    ans += 1
                    need -= 1
            else:  # ch == ')'
                need -= 1               # consume one required ')'
                if need == -1:          # extra ')'
                    ans += 1            # insert '(' before it
                    need = 1           # that '(' now expects two ')', one is used

        ans += need   # append missing ')' at the end
        return ans