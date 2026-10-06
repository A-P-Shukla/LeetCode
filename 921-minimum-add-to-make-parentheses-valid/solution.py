class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        balance = 0      # unmatched '(' count
        additions = 0    # insertions required

        for ch in s:
            if ch == '(':
                balance += 1
            else:  # ch == ')'
                if balance > 0:
                    balance -= 1   # pair with a previous '('
                else:
                    additions += 1 # need an extra '(' before this ')'

        # leftover '(' each need a ')'
        return additions + balance