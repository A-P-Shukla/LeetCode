class Solution {
public:
    /**
     * Determines if the matrix remains the same after k cyclic shifts.
     * Even rows shift left, odd rows shift right.
     */
    bool findMatrixSimilarity(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // A cyclic shift of k is equivalent to k % n
        k %= n;
        
        // If k is a multiple of n, no change occurs
        if (k == 0) return true;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // For a row to be identical after shifting by k, 
                // mat[i][j] must equal the element k positions away.
                // This logic works for both left and right shifts because
                // if mat[i][j] == mat[i][(j + k) % n], then 
                // mat[i][j] == mat[i][(j - k + n) % n] is also true.
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};