class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if not encodedText:
            return ""
        
        # Calculate the number of columns in the grid
        n = len(encodedText)
        cols = n // rows
        
        res = []
        
        # Traverse the conceptual matrix diagonally
        # Diagonals start at each column 'j' of the first row (row 0)
        for j in range(cols):
            r, c = 0, j
            while r < rows and c < cols:
                # Calculate index in the 1D string representing the row-major matrix
                index = r * cols + c
                res.append(encodedText[index])
                # Move diagonally down-right
                r += 1
                c += 1
        
        # Join characters and strip only the trailing spaces
        # Note: rstrip() without arguments strips all whitespace; 
        # rstrip(' ') specifically targets trailing spaces.
        return "".join(res).rstrip(' ')