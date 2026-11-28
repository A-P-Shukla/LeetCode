class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        if not items or budget <= 0:
            return 0

        mini = float("inf")
        maxi = 0
        for tag, cost in items:
            if tag > maxi:
                maxi = tag
            if cost < mini:
                mini = cost

        freq = [0] * (maxi + 1)
        for tag, _ in items:
            freq[tag] += 1

        g = [0] * (maxi + 1)
        for i in range(1, maxi + 1):
            if freq[i] > 0:
                total = 0
                for j in range(i, maxi + 1, i):
                    total += freq[j]
                g[i] = total

        # Collect (cost, count) pairs where cost is strictly less than 2 * mini
        pairs = []
        limit = 2 * mini
        for tag, cost in items:
            h = g[tag] - 1
            if h > 0 and cost < limit:
                pairs.append((cost, h))

        pairs.sort()

        ans = 0
        rem_budget = budget
        for cost, h in pairs:
            if rem_budget >= cost:
                temp = min(h, rem_budget // cost)
                rem_budget -= temp * cost
                ans += temp * 2
            if rem_budget == 0:
                break

        ans += rem_budget // int(mini)
        return ans