#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> topSums;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Radius 0: Area 0 rhombus is just the value at the center cell
                topSums.insert(grid[r][c]);
                if (topSums.size() > 3) {
                    topSums.erase(topSums.begin());
                }

                // Radius k > 0: Expand the rhombus outward as long as it stays within grid boundaries
                for (int k = 1; ; ++k) {
                    int topR = r - k, topC = c;
                    int rightR = r, rightC = c + k;
                    int bottomR = r + k, bottomC = c;
                    int leftR = r, leftC = c - k;

                    // Check if all four corners are within grid bounds
                    if (topR < 0 || bottomR >= m || leftC < 0 || rightC >= n) {
                        break;
                    }

                    long long currentSum = 0;
                    
                    // Traverse the 4 segments of the rhombus border
                    // Each loop handles exactly k elements to avoid double-counting corners
                    for (int i = 0; i < k; ++i) {
                        // Top to Right segment
                        currentSum += grid[topR + i][topC + i];
                        // Right to Bottom segment
                        currentSum += grid[rightR + i][rightC - i];
                        // Bottom to Left segment
                        currentSum += grid[bottomR - i][bottomC - i];
                        // Left to Top segment
                        currentSum += grid[leftR - i][leftC + i];
                    }

                    topSums.insert((int)currentSum);
                    
                    // Maintain only the top 3 largest distinct sums
                    if (topSums.size() > 3) {
                        topSums.erase(topSums.begin());
                    }
                }
            }
        }

        // Return the set elements in descending order
        return vector<int>(topSums.rbegin(), topSums.rend());
    }
};