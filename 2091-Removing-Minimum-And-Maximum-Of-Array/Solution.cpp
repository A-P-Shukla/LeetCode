#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0, maxIdx = 0;
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[minIdx]) minIdx = k;
            if (nums[k] > nums[maxIdx]) maxIdx = k;
        }

        // Order the indices such that i is the leftmost and j is the rightmost
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        // Option 1: Remove both elements from the front
        int removeFromFront = j + 1;

        // Option 2: Remove both elements from the back
        int removeFromBack = n - i;

        // Option 3: Remove the leftmost from the front and the rightmost from the back
        int removeFromBoth = (i + 1) + (n - j);

        return min({removeFromFront, removeFromBack, removeFromBoth});
    }
};

