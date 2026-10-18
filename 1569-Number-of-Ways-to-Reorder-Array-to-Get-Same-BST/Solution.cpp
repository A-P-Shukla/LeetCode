class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
      
        // Build Pascal's triangle for combinatorial calculations
        // pascal[i][j] represents C(i, j) = number of ways to choose j items from i items
        vector<vector<int>> pascal(n, vector<int>(n, 0));
        pascal[0][0] = 1;
      
        for (int i = 1; i < n; ++i) {
            pascal[i][0] = 1;  // C(i, 0) = 1
            for (int j = 1; j <= i; ++j) {
                // C(i, j) = C(i-1, j) + C(i-1, j-1)
                pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
            }
        }
      
        // Recursive function to count the number of valid BST arrangements
        function<int(vector<int>)> countBSTArrangements = [&](vector<int> sequence) -> int {
            // Base case: empty or single element has only one arrangement
            if (sequence.size() < 2) {
                return 1;
            }
          
            // Partition elements based on the root (first element)
            vector<int> leftSubtree, rightSubtree;
            int root = sequence[0];
          
            for (int& value : sequence) {
                if (value < root) {
                    leftSubtree.push_back(value);  // Elements smaller than root go to left
                } else if (value > root) {
                    rightSubtree.push_back(value);  // Elements larger than root go to right
                }
            }
          
            int leftSize = leftSubtree.size();
            int rightSize = rightSubtree.size();
          
            // Recursively count arrangements for left and right subtrees
            int leftArrangements = countBSTArrangements(leftSubtree);
            int rightArrangements = countBSTArrangements(rightSubtree);
          
            // Total arrangements = C(leftSize + rightSize, leftSize) * leftArrangements * rightArrangements
            // This represents choosing positions for left subtree elements among all positions
            return (1LL * pascal[leftSize + rightSize][leftSize] * leftArrangements % MOD) * rightArrangements % MOD;
        };
      
        // Subtract 1 because we don't count the original arrangement
        return (countBSTArrangements(nums) - 1 + MOD) % MOD;
    }
};
