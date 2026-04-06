class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        # Directions: North, East, South, West
        # Turning right: (i + 1) % 4
        # Turning left: (i - 1) % 4 (or (i + 3) % 4)
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        
        # Robot starts at (0, 0) facing North (index 0)
        x, y, d = 0, 0, 0
        
        # Convert obstacles to a set of tuples for O(1) lookup
        obstacle_set = {tuple(obs) for obs in obstacles}
        
        max_dist_sq = 0
        
        for cmd in commands:
            if cmd == -2:
                # Turn left
                d = (d + 3) % 4
            elif cmd == -1:
                # Turn right
                d = (d + 1) % 4
            else:
                # Move forward k steps
                for _ in range(cmd):
                    nx, ny = x + dx[d], y + dy[d]
                    
                    # Check if the next position is an obstacle
                    if (nx, ny) in obstacle_set:
                        break
                    
                    x, y = nx, ny
                    # Update max squared Euclidean distance
                    max_dist_sq = max(max_dist_sq, x*x + y*y)
                    
        return max_dist_sq