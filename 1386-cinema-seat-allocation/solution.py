from typing import List
from collections import defaultdict

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        # Map row number to a bitmask for seats 2 through 9
        row_masks = defaultdict(int)
        
        for row, col in reservedSeats:
            if 2 <= col <= 9:
                # Map seat col to bit position (col - 2)
                row_masks[row] |= (1 << (col - 2))
                
        # Base count for rows with no relevant reservations
        total_groups = (n - len(row_masks)) * 2
        
        # Bitmask configurations for the three blocks
        LEFT_MASK  = 0b00001111  # Seats 2, 3, 4, 5
        RIGHT_MASK = 0b11110000  # Seats 6, 7, 8, 9
        MID_MASK   = 0b00111100  # Seats 4, 5, 6, 7
        
        # Evaluate each modified row
        for mask in row_masks.values():
            left_free = (mask & LEFT_MASK) == 0
            right_free = (mask & RIGHT_MASK) == 0
            mid_free = (mask & MID_MASK) == 0
            
            if left_free and right_free:
                total_groups += 2
            elif left_free or right_free or mid_free:
                total_groups += 1
                
        return total_groups