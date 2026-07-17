#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);

        vector<int> freq(max_val + 1, 0);
        for (int x : nums) {
            for (int i = 1; i * i <= x; ++i) {
                if (x % i == 0) {
                    freq[i]++;
                    if (i * i != x) freq[x / i]++;
                }
            }
        }

        vector<long long> count(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long pairs_with_multiple = (1LL * freq[i] * (freq[i] - 1)) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs_with_multiple -= count[j];
            }
            count[i] = pairs_with_multiple;
        }

        vector<long long> prefix_sum(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + count[i];
        }

        vector<int> results;
        for (long long q : queries) {
            auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), q);
            results.push_back(distance(prefix_sum.begin(), it));
        }
        return results;
    }
};