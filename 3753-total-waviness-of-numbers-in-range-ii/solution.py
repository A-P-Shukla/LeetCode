from functools import cache

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def solve(N: int) -> int:
            if N <= 0:
                return 0
            S = str(N)
            L = len(S)
            
            @cache
            def dp(idx: int, prev1: int, prev2: int, is_less: bool, is_started: bool):
                # Base Case: Reached the end of the digit string
                if idx == L:
                    return (1, 0) if is_started else (0, 0)
                
                limit = 9 if is_less else int(S[idx])
                total_count = 0
                total_waviness = 0
                
                for d in range(limit + 1):
                    next_is_less = is_less or (d < limit)
                    next_is_started = is_started or (d > 0)
                    next_prev1 = -1
                    next_prev2 = -1
                    waviness_add = 0
                    
                    if next_is_started:
                        if not is_started:
                            # Start placing non-zero digits
                            next_prev1 = d
                            next_prev2 = -1
                            waviness_add = 0
                        else:
                            next_prev1 = d
                            next_prev2 = prev1
                            # Evaluate if the middle digit (prev1) forms a wave
                            if prev2 != -1:
                                is_peak = (prev1 > prev2) and (prev1 > d)
                                is_valley = (prev1 < prev2) and (prev1 < d)
                                waviness_add = 1 if (is_peak or is_valley) else 0
                                
                    sub_count, sub_waviness = dp(idx + 1, next_prev1, next_prev2, next_is_less, next_is_started)
                    total_count += sub_count
                    total_waviness += sub_waviness + waviness_add * sub_count
                    
                return total_count, total_waviness
            
            return dp(0, -1, -1, False, False)[1]
            
        return solve(num2) - solve(num1 - 1)