import math
from typing import List

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        # Step 1: Remove redundant coins to optimize Inclusion-Exclusion
        coins.sort()
        filtered_coins = []
        for c in coins:
            if not any(c % fc == 0 for fc in filtered_coins):
                filtered_coins.append(c)
        
        n = len(filtered_coins)
        
        # Step 2: Precompute LCM and subset size for all 2^n - 1 non-empty subsets
        subsets = []
        def build_subsets(idx: int, current_lcm: int, size: int):
            if idx == n:
                if size > 0:
                    subsets.append((current_lcm, size))
                return
            # Exclude element
            build_subsets(idx + 1, current_lcm, size)
            # Include element
            new_lcm = math.lcm(current_lcm, filtered_coins[idx])
            build_subsets(idx + 1, new_lcm, size + 1)

        build_subsets(0, 1, 0)

        # Function to compute count of amounts <= x using Inclusion-Exclusion Principle
        def count(x: int) -> int:
            total = 0
            for lcm_val, size in subsets:
                if size % 2 == 1:
                    total += x // lcm_val
                else:
                    total -= x // lcm_val
            return total

        # Step 3: Binary Search
        low = 1
        high = filtered_coins[0] * k
        ans = high

        while low <= high:
            mid = (low + high) // 2
            if count(mid) >= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans