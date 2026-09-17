class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        inf = float('inf')
        
        min_len = [inf] * n
        
        ans = inf
        l = 0
        current_sum = 0
        
        for r in range(n):
            current_sum += arr[r]
            
            while current_sum > target:
                current_sum -= arr[l]
                l += 1
                
            if current_sum == target:
                curr_len = r - l + 1
                
                if l > 0 and min_len[l - 1] != inf:
                    ans = min(ans, curr_len + min_len[l - 1])
                
                if r > 0:
                    min_len[r] = min(min_len[r - 1], curr_len)
                else:
                    min_len[r] = curr_len
            else:
                if r > 0:
                    min_len[r] = min_len[r - 1]
                    
        return ans if ans != inf else -1