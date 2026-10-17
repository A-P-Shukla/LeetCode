#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Compute sum of decimal digits of x
    static int digitSum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Step 1 & 2: build sorted target order
        vector<pair<int,int>> vec; // (digitSum, value)
        vec.reserve(n);
        for (int v : nums) {
            vec.emplace_back(digitSum(v), v);
        }
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        // Step 3: map value -> target index
        unordered_map<int,int> targetIdx;
        targetIdx.reserve(n*2);
        for (int i = 0; i < n; ++i) {
            targetIdx[vec[i].second] = i;
        }

        // Step 4: count cycles
        vector<char> visited(n, 0);
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int cur = i;
            int cycleSize = 0;
            while (!visited[cur]) {
                visited[cur] = 1;
                int nextVal = nums[cur];
                cur = targetIdx[nextVal];
                ++cycleSize;
            }
            if (cycleSize > 1) swaps += cycleSize - 1;
        }
        return swaps;
    }
};