from typing import List
import math

class Solution:
    def maxItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        factors = [item[0] for item in items]
        
        # Build activation mapping: source_item_index => list of affected target indices
        activated: List[List[int]] = [[] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i != j and factors[j] % factors[i] == 0:
                    activated[i].append(j)

        # Sort items by price to attempt cheaper selections early
        indexed_prices = [(items[i][1], i) for i in range(n)]
        indexed_prices.sort()

        spent = 0
        total_items = 0
        activated_flags = [False]*n

        for price, idx in indexed_prices:
            if spent + price > budget:
                continue
            
            # Max affordable copies
            buy_quantity = (budget - spent) // price
            spent += buy_quantity * price
            total_items += buy_quantity
            
            # Activate this item's bonuses only once ever
            if not activated_flags[idx]:
                for target in activated[idx]:
                    total_items += 1
                activated_flags[idx] = True
                
        return total_items