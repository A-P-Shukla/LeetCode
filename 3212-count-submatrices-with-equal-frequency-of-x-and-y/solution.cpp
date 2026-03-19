#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * Counts submatrices starting at (0,0) with equal 'X' and 'Y' frequency 
     * and at least one 'X'.
     */
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // colX[j] stores the count of 'X' in column j from row 0 to current row i
        // colY[j] stores the count of 'Y' in column j from row 0 to current row i
        vector<int> colX(cols, 0);
        vector<int> colY(cols, 0);
        
        int validSubmatrices = 0;
        
        for (int i = 0; i < rows; ++i) {
            // Horizontal prefix sums for the submatrix ending at (i, j)
            int currentXCount = 0;
            int currentYCount = 0;
            
            for (int j = 0; j < cols; ++j) {
                // Update vertical counts for the current column
                if (grid[i][j] == 'X') {
                    colX[j]++;
                } else if (grid[i][j] == 'Y') {
                    colY[j]++;
                }
                
                // Add the current column's accumulated values to the horizontal prefix
                // This effectively computes the 2D prefix sum for (0,0) to (i,j)
                currentXCount += colX[j];
                currentYCount += colY[j];
                
                // Condition 1: Equal frequency of 'X' and 'Y'
                // Condition 2: At least one 'X'
                if (currentXCount > 0 && currentXCount == currentYCount) {
                    validSubmatrices++;
                }
            }
        }
        
        return validSubmatrices;
    }
};