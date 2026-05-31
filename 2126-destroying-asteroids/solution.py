class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: list[int]) -> bool:
        # Sort the asteroids to greedily destroy the smallest ones first
        asteroids.sort()
        
        for asteroid in asteroids:
            # If the current mass is less than the asteroid, we cannot proceed
            if mass < asteroid:
                return False
            # Accumulate the mass of the destroyed asteroid
            mass += asteroid
            
        return True