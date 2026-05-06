#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // 1. Apply gravity to each row independently
        for (int i = 0; i < m; ++i) {
            // emptyPos tracks the rightmost available spot for a stone to fall into
            int emptyPos = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '*') {
                    // Obstacle: stones cannot pass. Reset emptyPos to the left of the obstacle.
                    emptyPos = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    // Stone: move it to the emptyPos and update emptyPos
                    boxGrid[i][j] = '.';
                    boxGrid[i][emptyPos] = '#';
                    emptyPos--;
                }
            }
        }

        // 2. Rotate the box 90 degrees clockwise
        // Original (m x n) -> Result (n x m)
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Mapping: (r, c) -> (c, m - 1 - r)
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }
};