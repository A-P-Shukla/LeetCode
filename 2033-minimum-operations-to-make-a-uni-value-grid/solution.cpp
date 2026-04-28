#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        vector<int> nums;
        nums.reserve(totalElements);

        // Flatten the grid and check if all elements have the same remainder mod x
        int remainder = grid[0][0] % x;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != remainder) {
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }

        // Sort to find the median
        sort(nums.begin(), nums.end());
        
        // The median is the optimal value to minimize absolute differences
        int median = nums[totalElements / 2];
        int operations = 0;

        for (int val : nums) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};