class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        inf = float('inf')
        
        # min_len[i] stores the minimum length of a valid sub-array ending at or before index i
        min_len = [inf] * n
        
        ans = inf
        l = 0
        current_sum = 0
        
        for r in range(n):
            current_sum += arr[r]
            
            # Shrink window from the left if sum exceeds target
            while current_sum > target:
                current_sum -= arr[l]
                l += 1
                
            # Found a sub-array with sum equal to target
            if current_sum == target:
                curr_len = r - l + 1
                
                # If there exists a valid non-overlapping sub-array strictly before index l
                if l > 0 and min_len[l - 1] != inf:
                    ans = min(ans, curr_len + min_len[l - 1])
                
                # Update min_len at position r
                if r > 0:
                    min_len[r] = min(min_len[r - 1], curr_len)
                else:
                    min_len[r] = curr_len
            else:
                # Carry forward the best minimum length seen so far
                if r > 0:
                    min_len[r] = min_len[r - 1]
                    
        return ans if ans != inf else -1