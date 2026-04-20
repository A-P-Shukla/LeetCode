#include <vector>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Case 1: Compare index 0 with houses starting from the end
        for (int j = n - 1; j > 0; --j) {
            if (colors[j] != colors[0]) {
                maxDist = std::max(maxDist, j);
                break;
            }
        }

        // Case 2: Compare index n-1 with houses starting from the beginning
        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] != colors[n - 1]) {
                maxDist = std::max(maxDist, (n - 1) - i);
                break;
            }
        }

        return maxDist;
    }
};