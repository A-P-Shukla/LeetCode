from functools import lru_cache

class Solution:
    def minimumDistance(self, word: str) -> int:
        def get_dist(p1, p2):
            if p1 == 26 or p2 == 26:
                return 0
            # Standard keyboard 6-column layout
            r1, c1 = divmod(p1, 6)
            r2, c2 = divmod(p2, 6)
            return abs(r1 - r2) + abs(c1 - c2)

        @lru_cache(None)
        def solve(idx, other_pos):
            # Base case: entire word typed
            if idx == len(word):
                return 0
            
            curr_pos = ord(word[idx]) - ord('A')
            prev_pos = ord(word[idx - 1]) - ord('A')
            
            # Choice 1: Use the finger that was at word[idx-1]
            res1 = get_dist(prev_pos, curr_pos) + solve(idx + 1, other_pos)
            
            # Choice 2: Use the "other" finger (currently at other_pos)
            res2 = get_dist(other_pos, curr_pos) + solve(idx + 1, prev_pos)
            
            return min(res1, res2)

        # Start from the second character.
        # The first character is always typed with 0 cost by the first finger.
        # other_pos = 26 indicates the second finger is not yet on the board.
        return solve(1, 26)
      
