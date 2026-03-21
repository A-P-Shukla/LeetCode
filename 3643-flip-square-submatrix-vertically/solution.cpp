class Solution {
public:
    /**
     * Flips the square submatrix of size k x k starting at (x, y) vertically.
     * 
     * @param grid The original m x n matrix.
     * @param x The starting row index of the submatrix.
     * @param y The starting column index of the submatrix.
     * @param k The side length of the square submatrix.
     * @return The updated matrix after the vertical flip.
     */
    vector<vector<int>> flipData(vector<vector<int>>& grid, int x, int y, int k) {
        // top points to the first row of the submatrix
        // bottom points to the last row of the submatrix
        int top = x;
        int bottom = x + k - 1;

        // Perform the vertical flip by swapping elements in rows from outside-in
        while (top < bottom) {
            for (int j = y; j < y + k; ++j) {
                // Swap elements at the same column index in the top and bottom rows
                swap(grid[top][j], grid[bottom][j]);
            }
            // Move pointers towards the center
            top++;
            bottom--;
        }

        return grid;
    }
};