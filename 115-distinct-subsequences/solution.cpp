class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // If s is shorter than t, it is impossible to form t as a subsequence
        if (m < n) {
            return 0;
        }

        // dp[j] stores the number of distinct subsequences of s processed so far that equal t[0...j-1]
        // Using unsigned long long to avoid intermediate integer overflow before fitting into 32-bit int
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: an empty string t can always be formed in 1 way

        for (int i = 0; i < m; ++i) {
            // Iterate backwards to use values from the previous step without extra space
            for (int j = n; j >= 1; --j) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return static_cast<int>(dp[n]);
    }
};