class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        """
        Scan the string while tracking the current nesting depth.
        Keep a character only when it is not the outermost '(' or ')'
        of its primitive block.
        """
        result = []
        depth = 0

        for ch in s:
            if ch == '(':
                if depth > 0:          # inner opening bracket
                    result.append(ch)
                depth += 1
            else:  # ch == ')'
                depth -= 1
                if depth > 0:          # inner closing bracket
                    result.append(ch)

        return ''.join(result)