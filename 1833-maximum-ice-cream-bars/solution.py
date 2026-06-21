class Solution:
    def maxIceCream(self, costs: list[int], coins: int) -> int:
        # Determine the range for counting sort
        max_cost = max(costs)
        freq = [0] * (max_cost + 1)
        
        # Fill the frequency array
        for cost in costs:
            freq[cost] += 1
            
        count = 0
        # Iterate through frequencies to buy cheapest bars first
        for cost in range(1, max_cost + 1):
            if freq[cost] > 0:
                # Calculate how many of this specific price we can afford
                num_bars = min(freq[cost], coins // cost)
                
                count += num_bars
                coins -= (num_bars * cost)
                
                # If we have less coins than the current cost, we can't buy anymore
                if coins < cost:
                    break
                    
        return count