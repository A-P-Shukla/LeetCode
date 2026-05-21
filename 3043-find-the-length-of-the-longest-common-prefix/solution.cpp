#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<int> prefixes;
        
        // Optimizing hash set capacity to avoid rehashing overhead
        prefixes.reserve(arr1.size() * 8);
        
        // Step 1: Insert all prefixes of arr1 elements into the hash set
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }
        
        int max_len = 0;
        
        // Step 2: For each element in arr2, find its longest matching prefix
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.count(val)) {
                    // Since we go from longest to shortest, the first match is the longest
                    max_len = std::max(max_len, (int)std::to_string(val).length());
                    break;
                }
                val /= 10;
            }
        }
        
        return max_len;
    }
};