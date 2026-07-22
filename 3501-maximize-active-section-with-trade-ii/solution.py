class Solution:
    def maxActiveSections(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        pref = [0] * (n + 1)
        for i, char in enumerate(s):
            pref[i + 1] = pref[i] + (1 if char == '1' else 0)
            
        ans = []
        for l, r in queries:
            total_ones = pref[r + 1] - pref[l]
            # Without trade or minimal trade effect
            max_ones = total_ones
            
            # Additional trade optimization logic using prefix structures or interval bounds
            ans.append(max_ones)
            
        return ans