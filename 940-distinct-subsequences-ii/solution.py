class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        # ends_with[i] stores the number of distinct subsequences ending with chr(ord('a') + i)
        ends_with = [0] * 26
        
        for ch in s:
            idx = ord(ch) - ord('a')
            # 1 accounts for the single-character subsequence [ch]
            # sum(ends_with) represents appending ch to all previous distinct subsequences
            ends_with[idx] = (1 + sum(ends_with)) % MOD
            
        return sum(ends_with) % MOD