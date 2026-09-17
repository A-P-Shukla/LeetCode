class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, n + 1);
        
        int l = 0;
        int current_sum = 0;
        int ans = n + 1;
        
        for (int r = 0; r < n; ++r) {
            current_sum += arr[r];
            
            while (current_sum > target) {
                current_sum -= arr[l];
                l++;
            }
            
            if (current_sum == target) {
                int curr_len = r - l + 1;
                
                if (l > 0 && min_len[l - 1] <= n) {
                    ans = std::min(ans, curr_len + min_len[l - 1]);
                }
                
                if (r > 0) {
                    min_len[r] = std::min(min_len[r - 1], curr_len);
                } else {
                    min_len[r] = curr_len;
                }
            } else {
                if (r > 0) {
                    min_len[r] = min_len[r - 1];
                }
            }
        }
        
        return ans > n ? -1 : ans;
    }
};