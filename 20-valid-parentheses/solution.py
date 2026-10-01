class Solution:
    def isValid(self, s: str) -> bool:
        """
        Use a stack to ensure each opening bracket is closed by the correct
        closing bracket in the proper order.
        """
        stack = []
        # Mapping from closing to opening bracket
        match = {')': '(', ']': '[', '}': '{'}

        for ch in s:
            if ch in "([{":
                stack.append(ch)               # push opening brackets
            else:                               # closing bracket
                if not stack or stack[-1] != match[ch]:
                    return False                # mismatch or extra closing
                stack.pop()                     # pop the matched opening

        return not stack                         # True if all brackets matched