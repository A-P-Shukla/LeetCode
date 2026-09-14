#include <vector>

class Solution {
public:
    bool isRectangleOverlap(const std::vector<int>& rec1, const std::vector<int>& rec2) {
        // rec = [x1, y1, x2, y2]
        // Check if horizontal projections overlap:
        // rec1's left < rec2's right AND rec2's left < rec1's right
        bool xOverlap = rec1[0] < rec2[2] && rec2[0] < rec1[2];
        
        // Check if vertical projections overlap:
        // rec1's bottom < rec2's top AND rec2's bottom < rec1's top
        bool yOverlap = rec1[1] < rec2[3] && rec2[1] < rec1[3];
        
        return xOverlap && yOverlap;
    }
};