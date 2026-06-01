#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        // Sort the costs in descending order
        std::sort(cost.rbegin(), cost.rend());
        
        int totalCost = 0;
        int n = cost.size();
        
        // Accumulate the cost of purchased candies, skipping every 3rd candy
        for (int i = 0; i < n; ++i) {
            if (i % 3 != 2) {
                totalCost += cost[i];
            }
        }
        
        return totalCost;
    }
};