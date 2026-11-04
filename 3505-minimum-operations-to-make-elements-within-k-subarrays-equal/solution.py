import heapq
from collections import defaultdict

class SlidingWindow:
    def __init__(self, x: int):
        self.x = x
        self.target_low = (x + 1) // 2
        self.low = []        # Max-heap (store negated values)
        self.high = []       # Min-heap
        self.delayed_low = defaultdict(int)
        self.delayed_high = defaultdict(int)
        self.low_size = 0
        self.high_size = 0
        self.sum_low = 0
        self.sum_high = 0

    def _prune_low(self):
        while self.low:
            v = -self.low[0]
            if self.delayed_low[v] > 0:
                self.delayed_low[v] -= 1
                heapq.heappop(self.low)
            else:
                break

    def _prune_high(self):
        while self.high:
            v = self.high[0]
            if self.delayed_high[v] > 0:
                self.delayed_high[v] -= 1
                heapq.heappop(self.high)
            else:
                break

    def _rebalance(self):
        self._prune_low()
        self._prune_high()

        while self.low_size > self.target_low and self.low:
            v = -heapq.heappop(self.low)
            self.sum_low -= v
            heapq.heappush(self.high, v)
            self.sum_high += v
            self.low_size -= 1
            self.high_size += 1
            self._prune_low()

        while self.low_size < self.target_low and self.high:
            v = heapq.heappop(self.high)
            self.sum_high -= v
            heapq.heappush(self.low, -v)
            self.sum_low += v
            self.high_size -= 1
            self.low_size += 1
            self._prune_high()

        self._prune_low()
        self._prune_high()

    def add(self, v: int):
        self._prune_low()
        if not self.low or v <= -self.low[0]:
            heapq.heappush(self.low, -v)
            self.sum_low += v
            self.low_size += 1
        else:
            heapq.heappush(self.high, v)
            self.sum_high += v
            self.high_size += 1
        self._rebalance()

    def remove(self, v: int):
        self._prune_low()
        if self.low and v <= -self.low[0]:
            self.delayed_low[v] += 1
            self.sum_low -= v
            self.low_size -= 1
        else:
            self.delayed_high[v] += 1
            self.sum_high -= v
            self.high_size -= 1
        self._rebalance()

    def median(self) -> int:
        self._prune_low()
        return -self.low[0]

    def cost(self) -> int:
        med = self.median()
        return (med * self.low_size - self.sum_low) + (self.sum_high - med * self.high_size)


class Solution:
    def minOperations(self, nums: list[int], x: int, k: int) -> int:
        n = len(nums)
        windows = n - x + 1
        window_cost = [0] * windows

        sw = SlidingWindow(x)
        for i in range(x):
            sw.add(nums[i])
        window_cost[0] = sw.cost()

        for s in range(1, windows):
            sw.remove(nums[s - 1])
            sw.add(nums[s + x - 1])
            window_cost[s] = sw.cost()

        inf = float('inf')
        dp = [[inf] * (k + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 0

        for i in range(1, n + 1):
            for j in range(k + 1):
                dp[i][j] = min(dp[i][j], dp[i - 1][j])

                if i >= x and j >= 1 and dp[i - x][j - 1] != inf:
                    cand = dp[i - x][j - 1] + window_cost[i - x]
                    dp[i][j] = min(dp[i][j], cand)

        return dp[n][k]
