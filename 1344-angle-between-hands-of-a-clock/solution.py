class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        # Calculate the minute hand angle (6 degrees per minute)
        minute_angle = minutes * 6.0
        
        # Calculate the hour hand angle.
        # Hour hand position is affected by both the hour and the passed minutes.
        # (hour % 12) * 30 degrees for the hour part.
        # minutes * 0.5 degrees for the minute progression part.
        hour_angle = (hour % 12) * 30.0 + minutes * 0.5
        
        # Find the absolute difference between the two angles
        angle = abs(hour_angle - minute_angle)
        
        # Return the smaller angle
        return min(angle, 360.0 - angle)