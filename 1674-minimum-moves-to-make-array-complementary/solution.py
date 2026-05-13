class Solution:
    def minMoves(self, nums: list[int], limit: int) -> int:
        # diff array to track changes in move counts for every possible target sum S
        # Sum range: [2, 2 * limit]
        diff = [0] * (2 * limit + 2)
        n = len(nums)
        
        for i in range(n // 2):
            a, b = nums[i], nums[n - 1 - i]
            
            # For each pair (a, b), we define move requirements for target sum S:
            # - [2, min(a, b)]: 2 moves
            # - [min(a, b) + 1, a + b - 1]: 1 move
            # - [a + b]: 0 moves
            # - [a + b + 1, max(a, b) + limit]: 1 move
            # - [max(a, b) + limit + 1, 2 * limit]: 2 moves
            
            min_val = min(a, b)
            max_val = max(a, b)
            
            # Apply changes to the difference array
            # Start with 2 moves for all S in [2, 2*limit]
            diff[2] += 2
            
            # In range [min_val + 1, max_val + limit], we only need 1 move.
            # So we subtract 1 from the baseline of 2 moves.
            diff[min_val + 1] -= 1
            
            # At exactly a + b, we need 0 moves.
            # So we subtract 1 from the range that already has 1 move.
            diff[a + b] -= 1
            
            # After a + b, we go back to 1 move.
            diff[a + b + 1] += 1
            
            # After max_val + limit, we go back to 2 moves.
            diff[max_val + limit + 1] += 1
            
        ans = float('inf')
        current_moves = 0
        # Compute prefix sums to find the minimum moves required
        for i in range(2, 2 * limit + 1):
            current_moves += diff[i]
            if current_moves < ans:
                ans = current_moves
                
        return ans