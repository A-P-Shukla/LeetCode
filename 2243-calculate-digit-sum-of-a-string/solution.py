class Solution:
    def digitSum(self, s: str, k: int) -> str:
        """
        Repeatedly replace every consecutive block of size k (last block may be shorter)
        with the decimal representation of the sum of its digits until the string length
        is not greater than k.
        """
        while len(s) > k:
            nxt = []
            for i in range(0, len(s), k):
                block = s[i:i + k]
                digit_sum = sum(int(ch) for ch in block)
                nxt.append(str(digit_sum))
            s = ''.join(nxt)
        return s