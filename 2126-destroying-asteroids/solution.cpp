#include <vector>
#include <algorithm>

class Solution {
public:
    bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
        // Sort the asteroids in non-decreasing order to apply the greedy approach
        std::sort(asteroids.begin(), asteroids.end());
        
        // Use a 64-bit integer to prevent overflow when accumulating masses
        long long current_mass = mass;
        
        for (int asteroid : asteroids) {
            // If the planet's mass is less than the asteroid's mass, it gets destroyed
            if (current_mass < asteroid) {
                return false;
            }
            // Otherwise, absorb the asteroid's mass
            current_mass += asteroid;
        }
        
        return true;
    }
};