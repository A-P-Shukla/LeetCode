class Solution {
public:
    /**
     * @brief Counts the number of special positions in a binary matrix.
     * A position (i, j) is special if mat[i][j] == 1 and it is the only 1 in its row and column.
     */
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Arrays to store the count of 1s in each row and each column
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // First pass: Calculate the sum of 1s for every row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int specialCount = 0;
        
        // Second pass: Identify cells that satisfy the "special" criteria
        for (int i = 0; i < m; ++i) {
            // Optimization: If a row doesn't have exactly one '1', no cell in it can be special
            if (rowCount[i] != 1) continue;
            
            for (int j = 0; j < n; ++j) {
                // A cell is special if it's 1 and its row/column counts are both exactly 1
                if (mat[i][j] == 1 && colCount[j] == 1) {
                    specialCount++;
                }
            }
        }
        
        return specialCount;
    }
};