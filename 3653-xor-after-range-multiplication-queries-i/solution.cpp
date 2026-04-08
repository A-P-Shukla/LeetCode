#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        // Process each query sequentially
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            long long v = query[3];

            // Perform range multiplication with step k
            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        // Calculate bitwise XOR of all elements in the modified array
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }

        return result;
    }
};