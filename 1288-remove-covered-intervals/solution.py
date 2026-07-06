from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        # Sort: ascending start, descending end for same starts
        # This puts wider intervals first if they share a start point
        intervals.sort(key=lambda x: (x[0], -x[1]))
        
        count = 0
        max_r = 0
        
        for _, r in intervals:
            # If current r is greater than the farthest end point seen so far,
            # this interval is not covered.
            if r > max_r:
                max_r = r
                count += 1
                
        return count