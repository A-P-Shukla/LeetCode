class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        arr = [(intervals[i][0], intervals[i][1], intervals[i][2], i) for i in range(n)]
        arr.sort(key=lambda x: (x[0], x[1], x[3]))
        
        starts = [x[0] for x in arr]
        
        dp_prev = [(0, ())] * (n + 1)
        
        for k in range(1, 5):
            dp_curr = [(0, ())] * (n + 1)
            for i in range(n - 1, -1, -1):
                best_score, best_indices = dp_curr[i + 1]
                
                next_idx = bisect_right(starts, arr[i][1])
                prev_score, prev_indices = dp_prev[next_idx]
                
                take_score = arr[i][2] + prev_score
                orig_idx = arr[i][3]
                
                take_indices = tuple(sorted(prev_indices + (orig_idx,)))
                
                if take_score > best_score:
                    best_score = take_score
                    best_indices = take_indices
                elif take_score == best_score:
                    if take_indices < best_indices:
                        best_score = take_score
                        best_indices = take_indices
                
                dp_curr[i] = (best_score, best_indices)
            
            dp_prev = dp_curr
            
        return list(dp_prev[0][1])