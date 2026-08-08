class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n, m = len(word1), len(word2)

        pref = [-1] * m
        ptr = 0
        for i in range(m):
            while ptr < n and word1[ptr] != word2[i]:
                ptr += 1
            if ptr < n:
                pref[i] = ptr
                ptr += 1
            else:
                break

        suf = [-1] * (m + 2)
        suf[m] = n
        suf[m + 1] = n + 1
        ptr = n - 1
        for i in range(m - 1, -1, -1):
            ptr = min(ptr, suf[i + 1] - 1)
            while ptr >= 0 and word1[ptr] != word2[i]:
                ptr -= 1
            suf[i] = ptr

        valid_mismatch = [False] * m
        for k in range(m):
            prev_idx = -1 if k == 0 else pref[k - 1]
            if k > 0 and prev_idx == -1:
                valid_mismatch[k] = False
            else:
                valid_mismatch[k] = (prev_idx + 1 < suf[k + 1])

        has_valid_suffix = [False] * (m + 1)
        has_valid_suffix[m] = (pref[m - 1] != -1)
        for i in range(m - 1, -1, -1):
            has_valid_suffix[i] = has_valid_suffix[i + 1] or valid_mismatch[i]

        if not has_valid_suffix[0]:
            return []

        seq = [0] * m
        last_idx = -1
        mismatch_used = False

        for i in range(m):
            if mismatch_used:
                p = last_idx + 1
                while p < n and word1[p] != word2[i]:
                    p += 1
                seq[i] = p
                last_idx = p
            else:
                if valid_mismatch[i]:
                    p = last_idx + 1
                    seq[i] = p
                    last_idx = p
                    if word1[p] != word2[i]:
                        mismatch_used = True
                else:
                    p = pref[i]
                    seq[i] = p
                    last_idx = p

        return seq