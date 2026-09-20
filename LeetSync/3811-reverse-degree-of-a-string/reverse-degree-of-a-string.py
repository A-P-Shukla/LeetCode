class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum(
            (ord('z') - ord(char) + 1) * idx 
            for idx, char in enumerate(s, start=1)
        )