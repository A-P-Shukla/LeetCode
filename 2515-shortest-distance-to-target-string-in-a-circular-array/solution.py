class Solution:
    def closetTarget(self, words: list[str], target: str, startIndex: int) -> int:
        n = len(words)
        min_distance = float('inf')
        found = False
        
        for i in range(n):
            if words[i] == target:
                found = True
                # Direct distance between indices
                direct_dist = abs(i - startIndex)
                
                # The minimum distance in a circular array is the minimum of
                # the direct distance and the distance going the other way around
                current_dist = min(direct_dist, n - direct_dist)
                
                if current_dist < min_distance:
                    min_distance = current_dist
        
        return min_distance if found else -1