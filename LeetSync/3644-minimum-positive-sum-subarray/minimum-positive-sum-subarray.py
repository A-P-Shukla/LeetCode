class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + nums[i]

        INF = 10 ** 18
        answer = INF

        for j in range(l, n + 1):
            max_len = min(r, j)          
            for length in range(l, max_len + 1):
                i = j - length           
                cur_sum = pref[j] - pref[i]
                if cur_sum > 0 and cur_sum < answer:
                    answer = cur_sum

        return -1 if answer == INF else answer