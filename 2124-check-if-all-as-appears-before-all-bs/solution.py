class Solution:
    def checkString(self, s: str) -> bool:
        """
        Return True if every 'a' appears before every 'b' in s.
        Linear scan with a flag indicating whether a 'b' has been seen.
        """
        seen_b = False
        for ch in s:
            if ch == 'b':
                seen_b = True
            else:  # ch == 'a'
                if seen_b:
                    return False
        return True