class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        if s[-1] == '1':
            return False

        # dp[i] is True if index i is reachable
        dp = [False] * n
        dp[0] = True

        reachable_count = 0

        for i in range(1, n):
            # Slide the window: add the element entering the window from the right
            if i >= minJump:
                if dp[i - minJump]:
                    reachable_count += 1

            # Slide the window: remove the element leaving the window from the left
            if i > maxJump:
                if dp[i - maxJump - 1]:
                    reachable_count -= 1

            # An index is reachable if s[i] is '0' and there is at least one reachable point in the window
            if s[i] == '0' and reachable_count > 0:
                dp[i] = True

        return dp[-1]