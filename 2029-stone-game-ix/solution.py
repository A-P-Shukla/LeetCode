class Solution:
    def stoneGameIX(self, stones: list[int]) -> bool:
        # Count remainders 0, 1, and 2
        cnt0, cnt1, cnt2 = 0, 0, 0
        for s in stones:
            rem = s % 3
            if rem == 0:
                cnt0 += 1
            elif rem == 1:
                cnt1 += 1
            else:
                cnt2 += 1
        
        # Scenario 1: Even number of stones with remainder 0
        # These stones don't change the eventual turn order for 1s and 2s.
        # Alice wins if both Type 1 and Type 2 stones are available.
        if cnt0 % 2 == 0:
            return cnt1 > 0 and cnt2 > 0
        
        # Scenario 2: Odd number of stones with remainder 0
        # Bob can use the 0-stone to flip the turn parity.
        # Alice needs a lead of at least 3 in either Type 1 or Type 2 
        # stones to force a win.
        return abs(cnt1 - cnt2) > 2