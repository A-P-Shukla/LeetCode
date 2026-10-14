#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(int num, int sum) {
        // Impossible if sum exceeds the maximum reachable with 'num' digits
        if (sum > 9LL * num) return "";
        string ans;
        ans.reserve(num);
        for (int i = 0; i < num; ++i) {
            int positionsLeft = num - i - 1;
            // Minimal digit we can place (0 for non‑leading, 1 for leading if more than one digit)
            int start = 0;
            if (i == 0 && num > 1) start = 1;
            // Choose the largest feasible digit
            int chosen = -1;
            for (int d = 9; d >= start; --d) {
                int remaining = sum - d;
                if (remaining < 0) continue;                     // exceeded sum
                if (remaining > 9LL * positionsLeft) continue;   // not enough capacity left
                chosen = d;
                break;
            }
            if (chosen == -1) return ""; // no feasible digit, should not happen after initial check
            ans.push_back('0' + chosen);
            sum -= chosen;
        }
        // After the loop sum must be zero; otherwise impossible (safety)
        if (sum != 0) return "";
        return ans;
    }
};