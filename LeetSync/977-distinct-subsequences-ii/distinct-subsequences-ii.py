class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        ends_with = [0] * 26
        
        for ch in s:
            idx = ord(ch) - ord('a')
            ends_with[idx] = (1 + sum(ends_with)) % MOD
            
        return sum(ends_with) % MOD