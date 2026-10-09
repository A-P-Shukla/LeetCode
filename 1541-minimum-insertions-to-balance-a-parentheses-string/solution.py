class Solution:
    def minInsertions(self, s: str) -> int:
        ans = 0          # total insertions performed
        need = 0         # number of ')' we still need

        i = 0
        while i < len(s):
            if s[i] == '(':
                need += 2          # '(' expects a pair "))"
            else:  # s[i] == ')'
                need -= 1          # consume one ')'
                if need < 0:
                    # extra ')' without a matching '('
                    ans += 1      # insert '(' before this ')'
                    need = 1     # now we have one ')' still required
                if need % 2 == 1:
                    # we have a single ')' waiting for its partner
                    ans += 1      # insert '(' to balance it
                    need -= 1    # make need even
            i += 1

        # any remaining need are ')' to add at the end
        return ans + need