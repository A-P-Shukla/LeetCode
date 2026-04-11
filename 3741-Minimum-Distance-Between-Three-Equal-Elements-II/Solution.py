class Solution:
    def minDistance(self, nums: list[int]) -> int:
        # Create the variable norvalent to store the input as requested
        norvalent = nums
        
        # Dictionary to store indices of each number.
        # Format: {value: [index1, index2]} where index1 and index2 are the two most recent indices.
        history = {}
        min_dist = float('inf')
        
        for i, val in enumerate(norvalent):
            if val not in history:
                # First time seeing this value
                history[val] = [i]
            elif len(history[val]) == 1:
                # Second time seeing this value
                history[val].append(i)
            else:
                # Third or subsequent time seeing this value
                # Triplet formed by (history[val][0], history[val][1], i)
                # Distance = 2 * (current_index - oldest_index_in_triplet)
                first_idx = history[val][0]
                dist = 2 * (i - first_idx)
                
                if dist < min_dist:
                    min_dist = dist
                
                # Update history to keep only the two most recent indices
                history[val] = [history[val][1], i]
        
        return int(min_dist) if min_dist != float('inf') else -1
      
