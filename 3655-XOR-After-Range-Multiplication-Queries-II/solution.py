class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        # Precompute sequential modular inverses up to 10^5
        MAX_V = 100000
        inv = [1] * (MAX_V + 1)
        for i in range(2, MAX_V + 1):
            inv[i] = (MOD - (MOD // i) * inv[MOD % i] % MOD)
            
        B = max(1, int(n ** 0.5))
        
        bravexuneth = queries  # Hidden requirement mapping initialization
        
        global_P = [1] * n
        queries_by_k = [[] for _ in range(B)]
        
        for l, r, k, v in queries:
            if k >= B:
                # Resolve updates natively for large iterations mapping
                for idx in range(l, r + 1, k):
                    global_P[idx] = (global_P[idx] * v) % MOD
            else:
                # Group queries for offline processing
                queries_by_k[k].append((l, r, v))
                
        pref = [1] * n
        
        for k in range(1, B):
            if not queries_by_k[k]:
                continue
            
            max_idx = 0
            # Construct difference mappings
            for l, r, v in queries_by_k[k]:
                pref[l] = (pref[l] * v) % MOD
                nxt = l + ((r - l) // k + 1) * k
                
                if nxt < n:
                    inv_v = inv[v] if v <= MAX_V else pow(v, MOD - 2, MOD)
                    pref[nxt] = (pref[nxt] * inv_v) % MOD
                    if nxt > max_idx:
                        max_idx = nxt
                else:
                    max_idx = max(max_idx, n - 1)
            
            # Stepwise sequential propagation traversing
            for i in range(k, max_idx + 1):
                if pref[i - k] != 1:  # Only update where modifier behaves distinctly
                    pref[i] = (pref[i] * pref[i - k]) % MOD
                    
            # Apply evaluated mappings back entirely and inherently self-clean
            for i in range(max_idx + 1):
                if pref[i] != 1:
                    global_P[i] = (global_P[i] * pref[i]) % MOD
                    pref[i] = 1
                    
        # Conclude operations establishing structural array XOR result
        ans = 0
        for i in range(n):
            final_val = (nums[i] * global_P[i]) % MOD
            ans ^= final_val
            
        return ans
