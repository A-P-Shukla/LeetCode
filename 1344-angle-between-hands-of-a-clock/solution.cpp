#include <cmath>
#include <algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the position of the minute hand (6 degrees per minute)
        double minute_angle = minutes * 6.0;
        
        // Calculate the position of the hour hand.
        // It moves 30 degrees per hour and 0.5 degrees per minute.
        // hour % 12 handles the case where hour is 12 (should be 0 degrees).
        double hour_angle = (hour % 12 + minutes / 60.0) * 30.0;
        
        // Find the absolute difference
        double diff = std::abs(hour_angle - minute_angle);
        
        // Return the smaller of the two possible angles (diff or 360 - diff)
        return std::min(diff, 360.0 - diff);
    }
};