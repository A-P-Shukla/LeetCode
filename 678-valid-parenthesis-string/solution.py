class Solution:
    def checkValidString(self, s: str) -> bool:
        low = high = 0  # min and max possible '(' count

        for ch in s:
            if ch == '(':
                low += 1
                high += 1
            elif ch == ')':
                low -= 1
                high -= 1
            else:  # ch == '*'
                low -= 1     # treat * as ')'
                high += 1    # treat * as '('

            if low < 0:
                low = 0  # we can treat extra * as empty string

            if high < 0:
                return False  # too many ')'

        return low == 0