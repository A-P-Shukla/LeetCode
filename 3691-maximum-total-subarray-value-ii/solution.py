from collections import deque
from bisect import bisect_right

class Solution:
    def maximumTotalSubarrayValue(self, nums: list[int], k: int) -> int:
        n = len(nums)
        
        # Helper function to get R[l], the smallest r >= l such that max - min >= X
        def get_R(X: int) -> list[int]:
            R = [n] * n
            r = 0
            max_dq = deque()
            min_dq = deque()
            for l in range(n):
                while max_dq and max_dq[0] < l:
                    max_dq.popleft()
                while min_dq and min_dq[0] < l:
                    min_dq.popleft()
                
                while r < n:
                    cur_max = nums[max_dq[0]] if max_dq else -1
                    cur_min = nums[min_dq[0]] if min_dq else -1
                    if r > l and cur_max - cur_min >= X:
                        break
                    
                    while max_dq and nums[max_dq[-1]] <= nums[r]:
                        max_dq.pop()
                    max_dq.append(r)
                    while min_dq and nums[min_dq[-1]] >= nums[r]:
                        min_dq.pop()
                    min_dq.append(r)
                    r += 1
                
                cur_max = nums[max_dq[0]] if max_dq else -1
                cur_min = nums[min_dq[0]] if min_dq else -1
                if r > l and cur_max - cur_min >= X:
                    R[l] = r - 1
            return R

        # Counts the number of subarrays with value >= X
        def count_subarrays(X: int) -> int:
            R = get_R(X)
            count = 0
            for l in range(n):
                if R[l] < n:
                    count += (n - R[l])
            return count

        # Precompute boundaries for each element as the max and min
        PL = [0] * n
        PR = [0] * n
        QL = [0] * n
        QR = [0] * n
        
        # Find PL and PR
        st = []
        for i in range(n):
            while st and nums[st[-1]] <= nums[i]:
                st.pop()
            PL[i] = st[-1] if st else -1
            st.append(i)
        
        st = []
        for i in range(n - 1, -1, -1):
            while st and nums[st[-1]] < nums[i]:
                st.pop()
            PR[i] = st[-1] if st else n
            st.append(i)
            
        # Find QL and QR
        st = []
        for i in range(n):
            while st and nums[st[-1]] >= nums[i]:
                st.pop()
            QL[i] = st[-1] if st else -1
            st.append(i)
            
        st = []
        for i in range(n - 1, -1, -1):
            while st and nums[st[-1]] > nums[i]:
                st.pop()
            QR[i] = st[-1] if st else n
            st.append(i)

        # Binary Search for the threshold X
        low, high = 0, int(1e9)
        X = 0
        while low <= high:
            mid = (low + high) // 2
            if count_subarrays(mid) >= k:
                X = mid
                low = mid + 1
            else:
                high = mid - 1
                
        # Helper to compute sum of values of all subarrays >= Y
        def get_sum_of_values(Y: int) -> int:
            R = get_R(Y)
            prefR = [0] * (n + 1)
            for i in range(n):
                prefR[i + 1] = prefR[i] + R[i]
                
            total_max = 0
            total_min = 0
            
            for i in range(n):
                # Contribution as max
                L_start, L_end = PL[i] + 1, i
                R_end = PR[i] - 1
                
                idx1 = -1
                if L_start <= L_end:
                    idx1 = bisect_right(R, i, lo=L_start, hi=L_end + 1) - 1
                if idx1 >= L_start:
                    total_max += (idx1 - L_start + 1) * (R_end - i + 1) * nums[i]
                    
                L2_start = idx1 + 1
                idx2 = -1
                if L2_start <= L_end:
                    idx2 = bisect_right(R, R_end, lo=L2_start, hi=L_end + 1) - 1
                if idx2 >= L2_start:
                    term = (idx2 - L2_start + 1) * (R_end + 1) - (prefR[idx2 + 1] - prefR[L2_start])
                    total_max += term * nums[i]
                    
                # Contribution as min
                L_start_min, L_end_min = QL[i] + 1, i
                R_end_min = QR[i] - 1
                
                idx1_min = -1
                if L_start_min <= L_end_min:
                    idx1_min = bisect_right(R, i, lo=L_start_min, hi=L_end_min + 1) - 1
                if idx1_min >= L_start_min:
                    total_min += (idx1_min - L_start_min + 1) * (R_end_min - i + 1) * nums[i]
                    
                L2_start_min = idx1_min + 1
                idx2_min = -1
                if L2_start_min <= L_end_min:
                    idx2_min = bisect_right(R, R_end_min, lo=L2_start_min, hi=L_end_min + 1) - 1
                if idx2_min >= L2_start_min:
                    term = (idx2_min - L2_start_min + 1) * (R_end_min + 1) - (prefR[idx2_min + 1] - prefR[L2_start_min])
                    total_min += term * nums[i]
                    
            return total_max - total_min

        count_next = count_subarrays(X + 1)
        sum_next = get_sum_of_values(X + 1)
        
        return sum_next + (k - count_next) * X