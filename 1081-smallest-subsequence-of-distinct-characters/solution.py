class Solution:
    def smallestSubsequence(self, s: str) -> str:
        # Map each character to its last occurring index
        last_occurrence = {c: i for i, c in enumerate(s)}
        
        stack = []
        visited = set()
        
        for i, char in enumerate(s):
            # If the character is already in the stack, skip it
            if char in visited:
                continue
            
            # While stack is not empty, current char is smaller than top,
            # and the top character appears later in the string
            while stack and char < stack[-1] and last_occurrence[stack[-1]] > i:
                top = stack.pop()
                visited.remove(top)
            
            stack.append(char)
            visited.add(char)
            
        return "".join(stack)