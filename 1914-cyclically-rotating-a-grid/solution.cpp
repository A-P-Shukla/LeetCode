#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            int top = layer, left = layer;
            int bottom = m - 1 - layer, right = n - 1 - layer;

            // 1. Extract the current layer into a 1D vector
            vector<int> elements;
            // Top row
            for (int j = left; j < right; ++j) elements.push_back(grid[top][j]);
            // Right col
            for (int i = top; i < bottom; ++i) elements.push_back(grid[i][right]);
            // Bottom row
            for (int j = right; j > left; --j) elements.push_back(grid[bottom][j]);
            // Left col
            for (int i = bottom; i > top; --i) elements.push_back(grid[i][left]);

            // 2. Determine effective rotation
            int len = elements.size();
            int shift = k % len;

            // 3. Put elements back into the grid after rotation
            // The element at index 'idx' in the rotated ring 
            // comes from index (idx + shift) % len in the original ring.
            int idx = 0;
            auto get_next_val = [&]() {
                return elements[(idx++ + shift) % len];
            };

            for (int j = left; j < right; ++j) grid[top][j] = get_next_val();
            for (int i = top; i < bottom; ++i) grid[i][right] = get_next_val();
            for (int j = right; j > left; --j) grid[bottom][j] = get_next_val();
            for (int i = bottom; i > top; --i) grid[i][left] = get_next_val();
        }

        return grid;
    }
};