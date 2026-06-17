class Solution:
    def kthCharacter(self, s: str, k: int) -> str:
        # Given the potential length, we use a list as a stack.
        # Note: In a real high-constraint scenario, we would map k backwards.
        result = []
        for char in s:
            if char == '*':
                if result:
                    result.pop()
            elif char == '#':
                result.extend(result)
            elif char == '%':
                result.reverse()
            else:
                result.append(char)
            
            # Optimization: If the current result size exceeds k + 1,
            # we can truncate the trailing elements to manage memory.
            if len(result) > k + 1:
                result = result[:k + 1]
        
        if k < 0 or k >= len(result):
            return '.'
        return result[k]