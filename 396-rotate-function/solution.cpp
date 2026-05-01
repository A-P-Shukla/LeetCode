#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        long long sum = 0;
        long long f = 0;

        // Calculate the total sum of elements and F(0)
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }

        long long max_f = f;

        // Iteratively calculate F(k) based on F(k-1)
        // F(k) = F(k-1) + sum - n * nums[n-k]
        for (int k = 1; k < n; ++k) {
            f = f + sum - (long long)n * nums[n - k];
            max_f = max(max_f, f);
        }

        return (int)max_f;
    }
};