#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    // Helper function to find R[l], the smallest r >= l such that max(nums[l..r]) - min(nums[l..r]) >= X
    vector<int> get_R(const vector<int>& nums, long long X) {
        int n = nums.size();
        vector<int> R(n);
        int r = 0;
        deque<int> max_dq, min_dq;
        for (int l = 0; l < n; ++l) {
            while (!max_dq.empty() && max_dq.front() < l) max_dq.pop_front();
            while (!min_dq.empty() && min_dq.front() < l) min_dq.pop_front();
            
            while (r < n) {
                int cur_max = max_dq.empty() ? -1 : nums[max_dq.front()];
                int cur_min = min_dq.empty() ? -1 : nums[min_dq.front()];
                if (r > l && cur_max - cur_min >= X) {
                    break;
                }
                while (!max_dq.empty() && nums[max_dq.back()] <= nums[r]) max_dq.pop_back();
                max_dq.push_back(r);
                while (!min_dq.empty() && nums[min_dq.back()] >= nums[r]) min_dq.pop_back();
                min_dq.push_back(r);
                r++;
            }
            int cur_max = max_dq.empty() ? -1 : nums[max_dq.front()];
            int cur_min = min_dq.empty() ? -1 : nums[min_dq.front()];
            if (r > l && cur_max - cur_min >= X) {
                R[l] = r - 1;
            } else {
                R[l] = n;
            }
        }
        return R;
    }

    // Counts the number of subarrays with value >= X
    long long count_subarrays(const vector<int>& nums, long long X) {
        int n = nums.size();
        long long count = 0;
        vector<int> R = get_R(nums, X);
        for (int l = 0; l < n; ++l) {
            if (R[l] < n) {
                count += (n - R[l]);
            }
        }
        return count;
    }

    // Computes the sum of values of all subarrays with value >= Y
    long long get_sum_of_values(const vector<int>& nums, long long Y,
                                 const vector<int>& PL, const vector<int>& PR,
                                 const vector<int>& QL, const vector<int>& QR) {
        int n = nums.size();
        vector<int> R = get_R(nums, Y);
        vector<long long> prefR(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefR[i + 1] = prefR[i] + R[i];
        }
        
        long long total_max = 0;
        long long total_min = 0;
        
        for (int i = 0; i < n; ++i) {
            // Contribution as maximum
            int L_start = PL[i] + 1;
            int L_end = i;
            int R_end = PR[i] - 1;
            
            int idx1 = -1;
            if (L_start <= L_end) {
                auto it = upper_bound(R.begin() + L_start, R.begin() + L_end + 1, i);
                idx1 = (it - R.begin()) - 1;
            }
            if (idx1 >= L_start) {
                total_max += (long long)(idx1 - L_start + 1) * (R_end - i + 1) * nums[i];
            }
            
            int L2_start = idx1 + 1;
            int idx2 = -1;
            if (L2_start <= L_end) {
                auto it = upper_bound(R.begin() + L2_start, R.begin() + L_end + 1, R_end);
                idx2 = (it - R.begin()) - 1;
            }
            if (idx2 >= L2_start) {
                long long term = (long long)(idx2 - L2_start + 1) * (R_end + 1) - (prefR[idx2 + 1] - prefR[L2_start]);
                total_max += term * nums[i];
            }
            
            // Contribution as minimum
            int L_start_min = QL[i] + 1;
            int L_end_min = i;
            int R_end_min = QR[i] - 1;
            
            int idx1_min = -1;
            if (L_start_min <= L_end_min) {
                auto it = upper_bound(R.begin() + L_start_min, R.begin() + L_end_min + 1, i);
                idx1_min = (it - R.begin()) - 1;
            }
            if (idx1_min >= L_start_min) {
                total_min += (long long)(idx1_min - L_start_min + 1) * (R_end_min - i + 1) * nums[i];
            }
            
            int L2_start_min = idx1_min + 1;
            int idx2_min = -1;
            if (L2_start_min <= L_end_min) {
                auto it = upper_bound(R.begin() + L2_start_min, R.begin() + L_end_min + 1, R_end_min);
                idx2_min = (it - R.begin()) - 1;
            }
            if (idx2_min >= L2_start_min) {
                long long term = (long long)(idx2_min - L2_start_min + 1) * (R_end_min + 1) - (prefR[idx2_min + 1] - prefR[L2_start_min]);
                total_min += term * nums[i];
            }
        }
        
        return total_max - total_min;
    }

public:
    long long maximumTotalSubarrayValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Precompute left/right boundaries of maximum/minimum elements
        vector<int> PL(n), PR(n), QL(n), QR(n);
        vector<int> st;
        
        // Find PL and PR for max elements
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }
            PL[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                st.pop_back();
            }
            PR[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        
        // Find QL and QR for min elements
        st.clear();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.back()] >= nums[i]) {
                st.pop_back();
            }
            QL[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                st.pop_back();
            }
            QR[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        
        // Step 2: Binary Search for the threshold X
        long long low = 0, high = 1e9, X = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count_subarrays(nums, mid) >= k) {
                X = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // Step 3: Compute sum of subarrays strictly greater than X, and pad the rest with X
        long long count_next = count_subarrays(nums, X + 1);
        long long sum_next = get_sum_of_values(nums, X + 1, PL, PR, QL, QR);
        
        return sum_next + (k - count_next) * X;
    }
};