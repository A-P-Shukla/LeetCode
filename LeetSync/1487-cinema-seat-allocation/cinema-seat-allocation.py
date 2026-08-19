class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        row_masks = defaultdict(int)
        
        for row, col in reservedSeats:
            if 2 <= col <= 9:
                row_masks[row] |= (1 << (col - 2))
                
        total_groups = (n - len(row_masks)) * 2
        
        LEFT_MASK  = 0b00001111  
        RIGHT_MASK = 0b11110000  
        MID_MASK   = 0b00111100  
        
        for mask in row_masks.values():
            left_free = (mask & LEFT_MASK) == 0
            right_free = (mask & RIGHT_MASK) == 0
            mid_free = (mask & MID_MASK) == 0
            
            if left_free and right_free:
                total_groups += 2
            elif left_free or right_free or mid_free:
                total_groups += 1
                
        return total_groups