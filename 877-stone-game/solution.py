class Solution:
    def stoneGame(self, piles: list[int]) -> bool:
        # Alice can always win by choosing to collect either all even-indexed
        # or all odd-indexed piles. Since the total number of piles is even
        # and the total sum of stones is odd, one group strictly has more stones.
        # Thus, Alice always wins playing optimally.
        return True