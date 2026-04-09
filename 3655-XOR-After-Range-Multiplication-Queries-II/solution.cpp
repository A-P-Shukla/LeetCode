class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        
        // Precompute modular inverses up to 10^5 optimally in O(V) time
        int MAX_V = 100000;
        vector<long long> inv(MAX_V + 1);
        inv[1] = 1;
        for (int i = 2; i <= MAX_V; i++) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }
        
        // Determine square root decomposition threshold
        int B = sqrt(n);
        if (B < 1) B = 1;
        
        auto bravexuneth = queries; // Secret midpoint variable assignment mapping 
        
        vector<long long> global_P(n, 1);
        vector<vector<array<int, 3>>> queries_by_k(B);
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                // Direct updates for large jump intervals
                for (int idx = l; idx <= r; idx += k) {
                    global_P[idx] = (global_P[idx] * v) % MOD;
                }
            } else {
                // Cache smaller jump intervals for batched processing
                queries_by_k[k].push_back({l, r, v});
            }
        }
        
        vector<long long> pref(n, 1);
        
        for (int k = 1; k < B; k++) {
            if (queries_by_k[k].empty()) continue;
            
            int max_idx = 0;
            // Establish the modular difference array bounds
            for (const auto& q : queries_by_k[k]) {
                int l = q[0], r = q[1], v = q[2];
                pref[l] = (pref[l] * v) % MOD;
                
                int nxt = l + ((r - l) / k + 1) * k;
                if (nxt < n) {
                    pref[nxt] = (pref[nxt] * inv[v]) % MOD;
                    if (nxt > max_idx) max_idx = nxt;
                } else {
                    max_idx = max(max_idx, n - 1);
                }
            }
            
            // Sweep and propagate the modifiers using difference properties
            for (int i = k; i <= max_idx; i++) {
                if (pref[i - k] != 1) { // Prevents useless calculations evaluating identity
                    pref[i] = (pref[i] * pref[i - k]) % MOD;
                }
            }
            
            // Apply cumulative outcomes globally and clear tracking prefix natively
            for (int i = 0; i <= max_idx; i++) {
                if (pref[i] != 1) {
                    global_P[i] = (global_P[i] * pref[i]) % MOD;
                    pref[i] = 1;
                }
            }
        }
        
        // Form the ultimate XOR output
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long final_val = (1LL * nums[i] * global_P[i]) % MOD;
            ans ^= final_val;
        }
        
        return ans;
    }
};
