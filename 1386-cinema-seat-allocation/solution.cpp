#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        // Map row number to a bitmask representing reserved status for seats 2 through 9
        std::unordered_map<int, int> row_masks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // Only seats 2 through 9 affect group placement
            if (col >= 2 && col <= 9) {
                // Map seat col to bit position (col - 2)
                row_masks[row] |= (1 << (col - 2));
            }
        }
        
        // Base count for rows with no relevant reservations (each gets 2 groups)
        int total_groups = (n - static_cast<int>(row_masks.size())) * 2;
        
        // Bitmask configurations for the three 4-seat blocks
        const int LEFT_MASK  = 0b00001111; // Seats 2, 3, 4, 5
        const int RIGHT_MASK = 0b11110000; // Seats 6, 7, 8, 9
        const int MID_MASK   = 0b00111100; // Seats 4, 5, 6, 7
        
        // Evaluate each row with reservations
        for (const auto& [row, mask] : row_masks) {
            bool left_free = (mask & LEFT_MASK) == 0;
            bool right_free = (mask & RIGHT_MASK) == 0;
            bool mid_free = (mask & MID_MASK) == 0;
            
            if (left_free && right_free) {
                total_groups += 2;
            } else if (left_free || right_free || mid_free) {
                total_groups += 1;
            }
        }
        
        return total_groups;
    }
};