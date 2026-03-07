#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        // Double the string to simulate all possible Type-1 rotations
        string doubled = s + s;
        
        // Target patterns: 
        // target1: 010101...
        // target2: 101010...
        // We calculate mismatches against these patterns in a sliding window of size n.
        
        int diff1 = 0; // Mismatches with target1
        int diff2 = 0; // Mismatches with target2
        int min_flips = n;
        
        for (int i = 0; i < 2 * n; ++i) {
            // Check if current char matches pattern starting with '0' at index 0
            // Pattern 1: index % 2 == 0 -> '0', else '1'
            if (doubled[i] != (i % 2 == 0 ? '0' : '1')) {
                diff1++;
            }
            // Pattern 2: index % 2 == 0 -> '1', else '0'
            if (doubled[i] != (i % 2 == 0 ? '1' : '0')) {
                diff2++;
            }
            
            // Once the window exceeds size n, remove the effect of the character that left the window
            if (i >= n) {
                int left_idx = i - n;
                if (doubled[left_idx] != (left_idx % 2 == 0 ? '0' : '1')) {
                    diff1--;
                }
                if (doubled[left_idx] != (left_idx % 2 == 0 ? '1' : '0')) {
                    diff2--;
                }
            }
            
            // When we have a full window of size n, update the minimum flips
            if (i >= n - 1) {
                min_flips = min({min_flips, diff1, diff2});
            }
        }
        
        return min_flips;
    }
};
---CODE_END---