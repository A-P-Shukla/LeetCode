class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        n = len(nums1)
        K = k1 + k2                       
        diff = [abs(a - b) for a, b in zip(nums1, nums2)]
        max_diff = max(diff) if diff else 0

        cnt = [0] * (max_diff + 1)
        for d in diff:
            cnt[d] += 1

        ops = K
        for d in range(max_diff, 0, -1):
            if ops == 0:
                break
            cur = cnt[d]
            if cur == 0:
                continue
            if ops >= cur:
                cnt[d - 1] += cur
                ops -= cur
                cnt[d] = 0
            else:
                cnt[d] -= ops
                cnt[d - 1] += ops
                ops = 0
                break


        ans = 0
        for d, c in enumerate(cnt):
            if c:
                ans += c * d * d
        return ans