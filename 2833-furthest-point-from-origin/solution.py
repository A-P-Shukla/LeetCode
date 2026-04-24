class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        """
        Calculates the furthest point from the origin.
        
        The strategy is to find the net difference between fixed 'L' and 'R' moves
        and add the total number of flexible '_' moves to that magnitude.
        """
        # Count occurrences of each character
        count_L = moves.count('L')
        count_R = moves.count('R')
        count_underscore = moves.count('_')
        
        # Max distance = magnitude of fixed moves + all flexible moves
        return abs(count_L - count_R) + count_underscore