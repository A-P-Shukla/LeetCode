class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result: List[str] = []

        def backtrack(left: int, right: int, path: List[str]) -> None:
            if left == 0 and right == 0:
                result.append(''.join(path))
                return

            if left > 0:
                path.append('(')
                backtrack(left - 1, right, path)
                path.pop()            

            if right > left:          
                path.append(')')
                backtrack(left, right - 1, path)
                path.pop()            

        backtrack(n, n, [])
        return result