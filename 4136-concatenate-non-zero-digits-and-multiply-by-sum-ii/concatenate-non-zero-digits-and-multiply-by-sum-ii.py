class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        mod = 10 ** 9 + 7
        prev_sum = [0] * (n + 1)
        prev_cnt = [0] * (n + 1)
        prev_val = [0] * (n + 1)

        cur_sum = 0
        cur_cnt = 0
        cur_val = 0
        for i in range(n):
            d = int(s[i])
            if d != 0:
                cur_sum += d
                cur_cnt += 1
                inv_pow = pow(10, -cur_cnt, mod)
                cur_val = (cur_val + d * inv_pow) % mod
            prev_sum[i + 1] = cur_sum
            prev_cnt[i + 1] = cur_cnt
            prev_val[i + 1] = cur_val
        res = []
        for l, r in queries:
            total = prev_sum[r + 1] - prev_sum[l]
            if total <= 0:
                res.append(0)
                continue
            sigma = (prev_val[r + 1] - prev_val[l]) % mod
            num_0 = pow(10, prev_cnt[r + 1], mod)
            x = (num_0 * sigma) % mod
            res.append((x * total) % mod)

        return res