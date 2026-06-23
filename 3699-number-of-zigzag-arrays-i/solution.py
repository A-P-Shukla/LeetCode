class Solution:
    def countZigzagArrays(self, n: int, l: int, r: int) -> int:
        S = r - l + 1
        MOD = 10**9 + 7

        # dp[val][0]: last step was up (prev < current)
        # dp[val][1]: last step was down (prev > current)
        dp = [[0, 0] for _ in range(S)]

        # Base case: length 2
        for i in range(S):
            for j in range(S):
                if i < j:
                    dp[j][0] += 1
                elif i > j:
                    dp[j][1] += 1

        for _ in range(3, n + 1):
            new_dp = [[0, 0] for _ in range(S)]
            
            # Prefix sums for state 1 (last step down)
            pref = [0] * (S + 1)
            for i in range(S):
                pref[i + 1] = (pref[i] + dp[i][1]) % MOD
                
            # Suffix sums for state 0 (last step up)
            suff = [0] * (S + 1)
            for i in range(S - 1, -1, -1):
                suff[i] = (suff[i + 1] + dp[i][0]) % MOD
                
            for v in range(S):
                # To go UP (v > prev), we need the count of prev where last step was DOWN
                new_dp[v][0] = pref[v]
                # To go DOWN (v < prev), we need the count of prev where last step was UP
                new_dp[v][1] = suff[v + 1]
            
            dp = new_dp
            
        return sum(sum(row) for row in dp) % MOD