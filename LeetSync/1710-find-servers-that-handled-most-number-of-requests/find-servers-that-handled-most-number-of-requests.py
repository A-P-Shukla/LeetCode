class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        n = len(arrival)
        cnt = [0] * k

        busy: List[tuple[int, int]] = []

        free = list(range(k))

        for i in range(n):
            cur = arrival[i]

            while busy and busy[0][0] <= cur:
                ft, sid = heappop(busy)
                pos = bisect_left(free, sid)
                free.insert(pos, sid)

            if not free:
                continue  

            pref = i % k
            idx = bisect_left(free, pref)
            if idx == len(free):
                idx = 0  

            server = free.pop(idx)
            cnt[server] += 1
            heappush(busy, (cur + load[i], server))

        max_cnt = max(cnt)
        return [i for i, c in enumerate(cnt) if c == max_cnt]