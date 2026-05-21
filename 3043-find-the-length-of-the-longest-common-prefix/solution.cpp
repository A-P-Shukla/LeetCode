#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

class Solution {
private:
    // Helper function to calculate the number of digits in an integer
    int getLength(int n) {
        int len = 0;
        while (n > 0) {
            len++;
            n /= 10;
        }
        return len;
    }

public:
    int findLengthOfLongestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::unordered_set<int> prefixes;
        // Optimize hash set capacity to avoid overhead rehashes
        prefixes.reserve(arr1.size() * 8); 

        // Step 1: Insert all prefixes of elements in arr1 into the hash set
        for (int x : arr1) {
            while (x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int maxLength = 0;

        // Step 2: Search for the longest common prefix for each element in arr2
        for (int y : arr2) {
            // Divide y by 10 until it becomes a prefix present in the set (or becomes 0)
            while (y > 0 && !prefixes.count(y)) {
                y /= 10;
            }
            if (y > 0) {
                maxLength = std::max(maxLength, getLength(y));
            }
        }

        return maxLength;
    }
};