class Solution:
    def minimumEffort(self, tasks: list[list[int]]) -> int:
        """
        To minimize initial energy, we should prioritize tasks where the gap 
        between 'minimum energy to start' and 'actual energy spent' is largest.
        """
        # Sort tasks by (minimum - actual) in descending order.
        tasks.sort(key=lambda x: x[1] - x[0], reverse=True)
        
        total_initial_energy = 0
        current_energy = 0
        
        for actual, minimum in tasks:
            # If current energy is insufficient to start the task,
            # increment the starting energy by the required difference.
            if current_energy < minimum:
                needed = minimum - current_energy
                total_initial_energy += needed
                current_energy += needed
            
            # Deduct the actual energy spent on the task.
            current_energy -= actual
            
        return total_initial_energy