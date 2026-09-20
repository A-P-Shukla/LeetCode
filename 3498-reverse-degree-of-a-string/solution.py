class Solution:
    def reverseDegree(self, s: str) -> int:
        # For each character, compute (26 - (ord(c) - ord('a'))) * (index + 1)
        # which simplifies to (ord('z') - ord(c) + 1) * index
        return sum(
            (ord('z') - ord(char) + 1) * idx 
            for idx, char in enumerate(s, start=1)
        )