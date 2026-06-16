class Solution:
    def processString(self, s: str) -> str:
        result = []
        
        for char in s:
            if char == '*':
                if result:
                    result.pop()
            elif char == '#':
                # Duplicate the current result
                result.extend(result)
            elif char == '%':
                # Reverse the current result
                result.reverse()
            else:
                # Append lowercase letter
                result.append(char)
        
        return "".join(result)