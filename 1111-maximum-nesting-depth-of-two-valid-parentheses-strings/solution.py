class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        ans = []
        depth = 0
        for ch in seq:
            if ch == '(':
                depth += 1
                ans.append(depth % 2)   # 0 for even depth, 1 for odd depth
            else:  # ch == ')'
                ans.append(depth % 2)
                depth -= 1
        return ans