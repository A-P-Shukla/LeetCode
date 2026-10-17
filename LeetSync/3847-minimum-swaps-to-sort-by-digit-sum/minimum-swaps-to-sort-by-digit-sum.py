class Solution:
    @staticmethod
    def _digit_sum(x: int) -> int:
        s = 0
        while x:
            s += x % 10
            x //= 10
        return s

    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)

        sorted_vals = sorted(nums, key=lambda v: (self._digit_sum(v), v))

        target_idx = {v: i for i, v in enumerate(sorted_vals)}

        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i]:
                continue
            cur = i
            cycle_len = 0
            while not visited[cur]:
                visited[cur] = True
                cur = target_idx[nums[cur]]
                cycle_len += 1
            if cycle_len > 1:
                swaps += cycle_len - 1

        return swaps