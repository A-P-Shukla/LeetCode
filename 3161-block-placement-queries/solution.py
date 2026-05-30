import bisect

class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (2 * n)
        
    def update(self, i, val):
        i += self.n
        self.tree[i] = val
        while i > 1:
            self.tree[i >> 1] = max(self.tree[i], self.tree[i ^ 1])
            i >>= 1
            
    def query(self, l, r):
        res = 0
        l += self.n
        r += self.n + 1
        while l < r:
            if l & 1:
                res = max(res, self.tree[l])
                l += 1
            if r & 1:
                r -= 1
                res = max(res, self.tree[r])
            l >>= 1
            r >>= 1
        return res

class Solution:
    def getResults(self, queries: list[list[int]]) -> list[bool]:
        max_x = 0
        for q in queries:
            max_x = max(max_x, q[1])
            
        st = SegmentTree(max_x + 1)
        obstacles = [0]
        results = []
        
        for q in queries:
            if q[0] == 1:
                x = q[1]
                idx = bisect.bisect_left(obstacles, x)
                prev_val = obstacles[idx - 1]
                
                # Set the size of the new interval starting at prev_val ending at x
                st.update(x, x - prev_val)
                
                # If there is an obstacle to the right of x, its interval shrinks
                if idx < len(obstacles):
                    next_val = obstacles[idx]
                    st.update(next_val, next_val - x)
                    
                obstacles.insert(idx, x)
            else:
                x, sz = q[1], q[2]
                idx = bisect.bisect_right(obstacles, x) - 1
                prev_val = obstacles[idx]
                
                # Find maximum gap within [0, prev_val]
                max_gap = st.query(0, prev_val)
                
                # Remaining space is the region from prev_val to x
                rem = x - prev_val
                
                results.append(max(max_gap, rem) >= sz)
                
        return results