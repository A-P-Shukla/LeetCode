#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minAbsoluteDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = INT_MAX;
        // Map stores: reverse(nums[i]) -> most recent index i
        unordered_map<int, int> last_seen_rev;

        for (int j = 0; j < n; ++j) {
            int current_val = nums[j];

            // If the current value matches a reversed value from a previous index i
            if (last_seen_rev.count(current_val)) {
                min_dist = min(min_dist, j - last_seen_rev[current_val]);
            }

            // Calculate reverse of current_val to store for future pairs
            int rev_val = reverseNumber(current_val);
            last_seen_rev[rev_val] = j;
        }

        return (min_dist == INT_MAX) ? -1 : min_dist;
    }

private:
    int reverseNumber(int n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }
};