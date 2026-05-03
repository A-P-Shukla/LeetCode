class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        """
        Determines if s can become goal after some number of shifts.
        
        A rotation of s means goal must have the same length as s,
        and goal must be a substring of s concatenated with itself.
        """
        # Step 1: Check if lengths match. If not, rotation is impossible.
        if len(s) != len(goal):
            return False
        
        # Step 2: Check if goal is a substring of s + s.
        # Python's 'in' operator uses a highly optimized string matching algorithm.
        return goal in (s + s)