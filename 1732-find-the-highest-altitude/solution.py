from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        """
        Calculates the highest altitude reached by a biker.
        Iterates through the gain array, updating the current altitude
        and tracking the peak value encountered.
        """
        max_altitude = 0
        current_altitude = 0
        
        for g in gain:
            current_altitude += g
            # Update max_altitude if the current point is higher
            if current_altitude > max_altitude:
                max_altitude = current_altitude
                
        return max_altitude