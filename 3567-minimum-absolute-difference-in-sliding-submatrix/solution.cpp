#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> calculateMinimumDifference(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int resRows = m - k + 1;
        int resCols = n - k + 1;
        vector<vector<int>> ans(resRows, vector<int>(resCols));

        // Iterate over every possible top-left corner (r, c) of the k x k submatrix
        for (int r = 0; r < resRows; ++r) {
            for (int c = 0; c < resCols; ++c) {
                vector<int> elements;
                elements.reserve(k * k);

                // Collect all elements in the current k x k submatrix
                for (int i = r; i < r + k; ++i) {
                    for (int j = c; j < c + k; ++j) {
                        elements.push_back(grid[i][j]);
                    }
                }

                // Sort elements to easily find distinct values and calculate differences
                sort(elements.begin(), elements.end());
                
                // Remove duplicates to focus on "distinct" values
                elements.erase(unique(elements.begin(), elements.end()), elements.end());

                // If fewer than 2 distinct values exist, the result is 0
                if (elements.size() < 2) {
                    ans[r][c] = 0;
                } else {
                    int minDiff = INT_MAX;
                    // Find the minimum gap between adjacent distinct values
                    for (size_t i = 1; i < elements.size(); ++i) {
                        minDiff = min(minDiff, elements[i] - elements[i - 1]);
                    }
                    ans[r][c] = minDiff;
                }
            }
        }

        return ans;
    }
};