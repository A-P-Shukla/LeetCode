class Solution:
    def judgeCircle(self, moves: str) -> bool:
        # Initialize coordinates at the origin
        x, y = 0, 0
        
        # Iterate through each move in the sequence
        for move in moves:
            if move == 'U':
                y += 1
            elif move == 'D':
                y -= 1
            elif move == 'R':
                x += 1
            elif move == 'L':
                x -= 1
        
        # Return True if the final position is (0, 0)
        return x == 0 and y == 0

    # Alternative Pythonic approach using count:
    # return moves.count('U') == moves.count('D') and moves.count('L') == moves.count('R')