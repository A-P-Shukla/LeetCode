import math
from typing import List

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        # Sort robots and factories by position
        # Relative order is preserved in the optimal matching on a 1D line
        robot.sort()
        factory.sort()
        
        n, m = len(robot), len(factory)
        
        # memo[robot_idx][factory_idx] stores the min distance
        # to fix robots from robot_idx onwards using factories from factory_idx onwards
        memo = {}

        def solve(r_idx, f_idx):
            # Base Case: All robots are repaired
            if r_idx == n:
                return 0
            # Base Case: No more factories left, but robots remain
            if f_idx == m:
                return float('inf')
            
            state = (r_idx, f_idx)
            if state in memo:
                return memo[state]
            
            # Option 1: Skip the current factory
            res = solve(r_idx, f_idx + 1)
            
            # Option 2: Assign k robots to the current factory
            # k can range from 1 to factory[f_idx][1] (limit)
            curr_dist = 0
            limit = factory[f_idx][1]
            f_pos = factory[f_idx][0]
            
            for k in range(1, limit + 1):
                if r_idx + k > n:
                    break
                
                # Add distance for the k-th robot assigned to this factory
                curr_dist += abs(robot[r_idx + k - 1] - f_pos)
                
                # Recursive call for the next factory and remaining robots
                sub_res = solve(r_idx + k, f_idx + 1)
                if sub_res != float('inf'):
                    res = min(res, curr_dist + sub_res)
            
            memo[state] = res
            return res

        return solve(0, 0)