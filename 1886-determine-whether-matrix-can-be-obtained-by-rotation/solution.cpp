#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Rotates an n x n matrix 90 degrees clockwise in-place.
     */
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // Check all 4 possible rotations (0, 90, 180, 270 degrees)
        for (int i = 0; i < 4; ++i) {
            if (mat == target) {
                return true;
            }
            rotate(mat);
        }
        
        return false;
    }
};

/**
 * Technical Note: 
 * The equality operator (==) for std::vector<std::vector<int>> in C++ 
 * performs a deep comparison, which is efficient for this problem's constraints.
 */