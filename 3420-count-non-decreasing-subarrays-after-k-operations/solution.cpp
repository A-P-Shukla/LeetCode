#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        struct Seg {
            long long val;   // constant prefix maximum for this segment
            int cnt;         // length of the segment
        };
        deque<Seg> segs;                // monotonic decreasing by val
        long long sumNums = 0;          // sum of numbers in current window
        long long sumMax  = 0;          // sum of prefix maxima in current window
        long long ans = 0;
        int l = 0;
        const int n = nums.size();

        for (int r = 0; r < n; ++r) {
            long long x = nums[r];
            sumNums += x;

            int mergedLen = 1;
            // Merge all previous segments whose max ≤ x
            while (!segs.empty() && segs.back().val <= x) {
                sumMax -= segs.back().val * segs.back().cnt;
                mergedLen += segs.back().cnt;
                segs.pop_back();
            }
            segs.push_back({x, mergedLen});
            sumMax += x * mergedLen;

            // Shrink from left while cost exceeds k
            while (sumMax - sumNums > k) {
                // remove nums[l]
                sumNums -= nums[l];
                // adjust the front segment
                Seg &front = segs.front();
                sumMax -= front.val;   // contribution of the removed element
                front.cnt--;
                if (front.cnt == 0) segs.pop_front();
                ++l;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};