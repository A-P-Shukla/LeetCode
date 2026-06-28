#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        // Sort the array to process elements in non-decreasing order
        std::sort(arr.begin(), arr.end());
        
        // Condition: The first element must be 1
        arr[0] = 1;
        
        // Iterate through the array to enforce the constraint:
        // abs(arr[i] - arr[i-1]) <= 1
        for (size_t i = 1; i < arr.size(); ++i) {
            // If the current element is significantly larger than the previous one,
            // we reduce it to the maximum allowable value (prev + 1).
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        // The last element will be the maximum possible value
        return arr.back();
    }
};