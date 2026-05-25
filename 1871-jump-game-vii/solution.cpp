#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') {
            return false;
        }

        // dp[i] will be true if index i is reachable
        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable_count = 0;

        for (int i = 1; i < n; ++i) {
            // Add the newly entering element into the window [i - maxJump, i - minJump]
            if (i >= minJump) {
                if (dp[i - minJump]) {
                    reachable_count++;
                }
            }

            // Remove the element that just left the window from the left side
            if (i > maxJump) {
                if (dp[i - maxJump - 1]) {
                    reachable_count--;
                }
            }

            // If there is at least one reachable index in the window and current char is '0'
            if (s[i] == '0' && reachable_count > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};