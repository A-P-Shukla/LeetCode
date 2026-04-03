import bisect

class Solution:
    def maximumWalls(self, robots: list[int], distance: list[int], walls: list[int]) -> int:
        n = len(robots)
        # Pair robots with their max bullet distances and sort by position
        r_dist = sorted(zip(robots, distance))
        walls.sort()

        def count_range(l, r):
            """Returns the number of unique walls in the inclusive range [l, r]."""
            if l > r:
                return 0
            return bisect.bisect_right(walls, r) - bisect.bisect_left(walls, l)

        # Pre-identify walls located exactly at robot positions
        # These are always destroyed because robot bullet covers its own position
        U = []
        for r, _ in r_dist:
            idx = bisect.bisect_left(walls, r)
            if idx < len(walls) and walls[idx] == r:
                U.append(1)
            else:
                U.append(0)

        # dp0: Max walls using first i robots, with robot i shooting Left
        # dp1: Max walls using first i robots, with robot i shooting Right
        dp0 = count_range(r_dist[0][0] - r_dist[0][1], r_dist[0][0] - 1) + U[0]
        dp1 = U[0]

        for i in range(1, n):
            r_curr, d_curr = r_dist[i]
            r_prev, d_prev = r_dist[i-1]

            # Walls in the gap (r_prev, r_curr)
            # subL_cnt: walls hit by current robot shooting Left
            l_start, l_end = max(r_curr - d_curr, r_prev + 1), r_curr - 1
            subL_cnt = count_range(l_start, l_end)

            # subR_prev_cnt: walls hit by previous robot shooting Right
            r_start_p, r_end_p = r_prev + 1, min(r_prev + d_prev, r_curr - 1)
            subR_prev_cnt = count_range(r_start_p, r_end_p)

            # f_RL: Unique walls hit if prev shoots Right AND curr shoots Left
            if r_start_p > r_end_p:
                f_RL = subL_cnt
            elif l_start > l_end:
                f_RL = subR_prev_cnt
            elif l_start <= r_end_p:
                # Ranges overlap or touch, union is [r_start_p, l_end]
                f_RL = count_range(r_start_p, l_end)
            else:
                # Ranges are disjoint within the gap
                f_RL = subL_cnt + subR_prev_cnt

            next_dp0 = max(dp0 + subL_cnt, dp1 + f_RL) + U[i]
            next_dp1 = max(dp0 + 0, dp1 + subR_prev_cnt) + U[i]
            
            dp0, dp1 = next_dp0, next_dp1

        # The last robot might shoot right into the infinite space beyond it
        last_right_gap = count_range(r_dist[-1][0] + 1, r_dist[-1][0] + r_dist[-1][1])
        
        return int(max(dp0, dp1 + last_right_gap))