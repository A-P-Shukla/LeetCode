class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        # dp[i] will store whether the current player can win with i stones remaining
        dp = [False] * (n + 1)
        
        for i in range(1, n + 1):
            k = 1
            while k * k <= i:
                # If taking k^2 stones leaves opponent in a losing position,
                # current player wins.
                if not dp[i - k * k]:
                    dp[i] = True
                    break
                k += 1
                
        return dp[n]