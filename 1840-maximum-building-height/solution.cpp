#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        std::sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // Left to right pass: maintain slope constraint
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = std::min(restrictions[i][1], 
                                          restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }
        
        // Right to left pass: maintain slope constraint
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = std::min(restrictions[i][1], 
                                          restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }
        
        int maxHeight = 0;
        // Calculate max height between adjacent restrictions
        for (int i = 0; i < m - 1; ++i) {
            int d = restrictions[i + 1][0] - restrictions[i][0];
            int h1 = restrictions[i][1];
            int h2 = restrictions[i + 1][1];
            // Peak between i and i+1: (h1 + h2 + dist) / 2
            maxHeight = std::max(maxHeight, (h1 + h2 + d) / 2);
        }
        
        // Check the range from the last restriction to building n
        maxHeight = std::max(maxHeight, restrictions.back()[1] + (n - restrictions.back()[0]));
        
        return maxHeight;
    }
};