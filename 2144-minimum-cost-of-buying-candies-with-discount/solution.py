class Solution:
    def minimumCost(self, cost: list[int]) -> int:
        # Sort the costs in descending order
        cost.sort(reverse=True)
        
        total_cost = 0
        # Accumulate the cost of purchased candies, skipping every 3rd candy
        for i in range(len(cost)):
            if i % 3 != 2:
                total_cost += cost[i]
                
        return total_cost