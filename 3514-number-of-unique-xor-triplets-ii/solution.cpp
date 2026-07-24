#include <vector>

class Solution {
public:
    int countUniqueXORTriplets(std::vector<int>& nums) {
        // Step 1: Extract unique values from nums
        std::vector<bool> present(2048, false);
        std::vector<int> U;
        for (int x : nums) {
            if (!present[x]) {
                present[x] = true;
                U.push_back(x);
            }
        }

        // Step 2: Compute all unique pair XOR values (S2)
        std::vector<bool> S2(2048, false);
        int n = U.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                S2[U[i] ^ U[j]] = true;
            }
        }

        // Step 3: Compute all unique triplet XOR values (S3)
        std::vector<bool> S3(2048, false);
        for (int w = 0; w < 2048; ++w) {
            if (S2[w]) {
                for (int z : U) {
                    S3[w ^ z] = true;
                }
            }
        }

        // Step 4: Count the total unique triplet XOR values
        int uniqueCount = 0;
        for (int i = 0; i < 2048; ++i) {
            if (S3[i]) {
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
};