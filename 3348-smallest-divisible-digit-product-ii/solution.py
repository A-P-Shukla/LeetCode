class Solution:
    def stringSequence(self, num: str, t: int) -> str:
        # Factorize t into powers of 2, 3, 5, 7
        req2 = req3 = req5 = req7 = 0
        temp_t = t
        
        while temp_t % 2 == 0:
            req2 += 1
            temp_t //= 2
        while temp_t % 3 == 0:
            req3 += 1
            temp_t //= 3
        while temp_t % 5 == 0:
            req5 += 1
            temp_t //= 5
        while temp_t % 7 == 0:
            req7 += 1
            temp_t //= 7

        # If t has any other prime factor, impossible to form with digits 1-9
        if temp_t > 1:
            return "-1"

        def get_factors(d: int):
            f2 = f3 = f5 = f7 = 0
            if d == 2: f2 = 1
            elif d == 3: f3 = 1
            elif d == 4: f2 = 2
            elif d == 5: f5 = 1
            elif d == 6: f2 = 1; f3 = 1
            elif d == 7: f7 = 1
            elif d == 8: f2 = 3
            elif d == 9: f3 = 2
            return f2, f3, f5, f7

        def is_better(a: str, b: str) -> bool:
            if len(a) != len(b):
                return len(a) < len(b)
            return a < b

        # Precompute DP for optimal (minimum length, lexicographically smallest)
        # multiset of digits from {2, 3, 4, 6, 8, 9} to achieve required 2s and 3s.
        INF = "9" * 100
        dp = [[INF] * 31 for _ in range(48)]
        dp[0][0] = ""

        available_digits = [(2, 1, 0), (3, 0, 1), (4, 2, 0), (6, 1, 1), (8, 3, 0), (9, 0, 2)]

        for u in range(48):
            for v in range(31):
                if u == 0 and v == 0:
                    continue
                best = INF
                for d, f2, f3 in available_digits:
                    pu = max(0, u - f2)
                    pv = max(0, v - f3)
                    cand = "".join(sorted(dp[pu][pv] + str(d)))
                    if is_better(cand, best):
                        best = cand
                dp[u][v] = best

        def get_optimal_multiset(r2: int, r3: int, r5: int, r7: int) -> str:
            m = dp[max(0, r2)][max(0, r3)]
            if r5 > 0:
                m += "5" * r5
            if r7 > 0:
                m += "7" * r7
            return "".join(sorted(m))

        N = len(num)
        fz = num.find('0')

        # Compute prefix factor counts for num
        pref2 = [0] * (N + 1)
        pref3 = [0] * (N + 1)
        pref5 = [0] * (N + 1)
        pref7 = [0] * (N + 1)

        for i in range(N):
            pref2[i + 1] = pref2[i]
            pref3[i + 1] = pref3[i]
            pref5[i + 1] = pref5[i]
            pref7[i + 1] = pref7[i]
            if '1' <= num[i] <= '9':
                f2, f3, f5, f7 = get_factors(int(num[i]))
                pref2[i + 1] += f2
                pref3[i + 1] += f3
                pref5[i + 1] += f5
                pref7[i + 1] += f7

        # Case 1: Check if num itself is valid
        if fz == -1:
            if (pref2[N] >= req2 and pref3[N] >= req3 and 
                pref5[N] >= req5 and pref7[N] >= req7):
                return num

        # Case 2: Match prefix of length i, increment digit at index i, minimize suffix
        max_i = fz if fz != -1 else N - 1

        for i in range(max_i, -1, -1):
            start_d = int(num[i]) + 1
            for d_pos in range(start_d, 10):
                f2, f3, f5, f7 = get_factors(d_pos)
                p2 = pref2[i] + f2
                p3 = pref3[i] + f3
                p5 = pref5[i] + f5
                p7 = pref7[i] + f7

                M = get_optimal_multiset(req2 - p2, req3 - p3, req5 - p5, req7 - p7)
                rem_len = N - 1 - i

                if len(M) <= rem_len:
                    return num[:i] + str(d_pos) + "1" * (rem_len - len(M)) + M

        # Case 3: Impossible with length N, construct for minimum length > N
        M = get_optimal_multiset(req2, req3, req5, req7)
        target_len = max(N + 1, len(M))
        return "1" * (target_len - len(M)) + M