#include <vector>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a valid sub-array ending at or before index i
        std::vector<int> min_len(n, n + 1);
        
        int l = 0;
        int current_sum = 0;
        int ans = n + 1; // n + 1 represents infinity since total combined length <= n
        
        for (int r = 0; r < n; ++r) {
            current_sum += arr[r];
            
            // Shrink window from the left if sum exceeds target
            while (current_sum > target) {
                current_sum -= arr[l];
                l++;
            }
            
            // Found a sub-array with sum equal to target
            if (current_sum == target) {
                int curr_len = r - l + 1;
                
                // If there exists a valid non-overlapping sub-array strictly before index l
                if (l > 0 && min_len[l - 1] <= n) {
                    ans = std::min(ans, curr_len + min_len[l - 1]);
                }
                
                // Update min_len at position r
                if (r > 0) {
                    min_len[r] = std::min(min_len[r - 1], curr_len);
                } else {
                    min_len[r] = curr_len;
                }
            } else {
                // Carry forward the best minimum length seen so far
                if (r > 0) {
                    min_len[r] = min_len[r - 1];
                }
            }
        }
        
        return ans > n ? -1 : ans;
    }
};