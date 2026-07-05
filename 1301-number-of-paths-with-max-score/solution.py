class Solution:
    def pathsWithMaxScore(self, board: list[str]) -> list[int]:
        n = len(board)
        MOD = 10**9 + 7
        
        # dp[r][c] stores [max_sum, number_of_ways]
        # Initialize with -1 to signify unreachable
        dp = [[[-1, 0] for _ in range(n)] for _ in range(n)]
        
        # Base case: start from bottom-right (S)
        dp[n - 1][n - 1] = [0, 1]
        
        for r in range(n - 1, -1, -1):
            for c in range(n - 1, -1, -1):
                if board[r][c] == 'X' or (r == n - 1 and c == n - 1):
                    continue
                
                max_s = -1
                paths = 0
                
                # Check neighbors: (r+1, c), (r, c+1), (r+1, c+1)
                for dr, dc in [(0, 1), (1, 0), (1, 1)]:
                    nr, nc = r + dr, c + dc
                    if nr < n and nc < n and dp[nr][nc][0] != -1:
                        if dp[nr][nc][0] > max_s:
                            max_s = dp[nr][nc][0]
                            paths = dp[nr][nc][1]
                        elif dp[nr][nc][0] == max_s:
                            paths = (paths + dp[nr][nc][1]) % MOD
                            
                if max_s != -1:
                    val = 0 if board[r][c] == 'E' else int(board[r][c])
                    dp[r][c] = [max_s + val, paths]
                    
        return dp[0][0] if dp[0][0][0] != -1 else [0, 0]