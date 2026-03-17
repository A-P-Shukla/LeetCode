class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        // Step 1: Calculate heights for each cell
        // We can modify the matrix in-place to store the height of consecutive 1s
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        // Step 2: For each row, sort heights and find the max area
        for (int i = 0; i < m; ++i) {
            // Copy current row to sort it without losing height data for the next row
            vector<int> currentRow = matrix[i];
            sort(currentRow.begin(), currentRow.end(), greater<int>());

            for (int j = 0; j < n; ++j) {
                if (currentRow[j] == 0) break; // Optimization: height 0 means no more rectangles
                
                // Area = height * width
                // Width is (j + 1) because heights are sorted descending
                int area = currentRow[j] * (j + 1);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};