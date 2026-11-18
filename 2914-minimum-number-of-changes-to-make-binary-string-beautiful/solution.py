class Solution:
    def minChanges(self, s: str) -> int:
        """
        Count mismatched adjacent pairs in an even‑length binary string.
        Each mismatched pair requires exactly one character flip.
        """
        changes = 0
        # iterate over even indices
        for i in range(0, len(s), 2):
            if s[i] != s[i + 1]:
                changes += 1
        return changes