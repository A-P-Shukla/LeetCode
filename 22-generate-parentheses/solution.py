from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        """
        Backtracking generation of all well‑formed parentheses strings.
        """
        result: List[str] = []

        def backtrack(left: int, right: int, path: List[str]) -> None:
            # left  -> '(' remaining
            # right -> ')' remaining
            if left == 0 and right == 0:
                result.append(''.join(path))
                return

            if left > 0:
                path.append('(')
                backtrack(left - 1, right, path)
                path.pop()            # backtrack

            if right > left:          # ensures validity
                path.append(')')
                backtrack(left, right - 1, path)
                path.pop()            # backtrack

        backtrack(n, n, [])
        return result