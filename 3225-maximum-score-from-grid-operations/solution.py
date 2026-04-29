class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        # P[j][h] stores the sum of grid[0...h-1][j]
        P = [[0] * (n + 1) for _ in range(n)]
        for j in range(n):
            for i in range(n):
                P[j][i + 1] = P[j][i] + grid[i][j]

        # dp[h_curr][h_prev] stores max score up to col j-1
        # H_j = h_curr, H_{j-1} = h_prev
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        for j in range(n):
            next_dp = [[0] * (n + 1) for _ in range(n + 1)]
            for h_j in range(n + 1):
                # Precompute prefix max of dp
                prefix_max_dp = [0] * (n + 1)
                curr_max = -1
                for k in range(n + 1):
                    if dp[h_j][k] > curr_max:
                        curr_max = dp[h_j][k]
                    prefix_max_dp[k] = curr_max
                
                # Precompute suffix max of (dp + P[j])
                suffix_max_dp_plus_P = [-1] * (n + 2)
                curr_max_p = -1
                for k in range(n, -1, -1):
                    val = dp[h_j][k] + P[j][k]
                    if val > curr_max_p:
                        curr_max_p = val
                    suffix_max_dp_plus_P[k] = curr_max_p
                
                pj_hj = P[j][h_j]
                for h_next in range(n + 1):
                    if h_j >= h_next:
                        # Case: Previous height or no gain
                        val1 = prefix_max_dp[h_j]
                        val2 = suffix_max_dp_plus_P[h_j + 1] - pj_hj
                        next_dp[h_next][h_j] = val1 if val1 > val2 else val2
                    else:
                        # Case: Next height or previous height
                        pj_hnext = P[j][h_next]
                        val1 = prefix_max_dp[h_next] + pj_hnext - pj_hj
                        val2 = suffix_max_dp_plus_P[h_next + 1] - pj_hj
                        next_dp[h_next][h_j] = val1 if val1 > val2 else val2
            dp = next_dp

        # Result assumes a virtual column n with height 0
        return max(dp[0])