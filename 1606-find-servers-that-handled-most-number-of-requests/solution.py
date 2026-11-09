from heapq import heappush, heappop
from bisect import bisect_left
from typing import List

class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        n = len(arrival)
        cnt = [0] * k

        # busy heap stores (free_time, server_id)
        busy: List[tuple[int, int]] = []

        # free list kept sorted; we will use bisect for lower bound
        free = list(range(k))

        for i in range(n):
            cur = arrival[i]

            # release servers whose work has finished
            while busy and busy[0][0] <= cur:
                ft, sid = heappop(busy)
                # insert back keeping order (binary insertion)
                pos = bisect_left(free, sid)
                free.insert(pos, sid)

            if not free:
                continue  # request dropped

            pref = i % k
            idx = bisect_left(free, pref)
            if idx == len(free):
                idx = 0  # wrap around

            server = free.pop(idx)
            cnt[server] += 1
            heappush(busy, (cur + load[i], server))

        max_cnt = max(cnt)
        return [i for i, c in enumerate(cnt) if c == max_cnt]