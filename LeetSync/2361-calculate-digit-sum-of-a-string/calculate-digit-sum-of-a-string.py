class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            nxt = []
            for i in range(0, len(s), k):
                block = s[i:i + k]
                digit_sum = sum(int(ch) for ch in block)
                nxt.append(str(digit_sum))
            s = ''.join(nxt)
        return s