#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Base case: check bounds
        if (start < 0 || start >= arr.size()) {
            return false;
        }

        // Base case: if we found 0, target reached
        if (arr[start] == 0) {
            return true;
        }

        // To track visited nodes without extra space, we can flip the sign 
        // of the value at the current index. Since 0 is already handled, 
        // a negative value indicates this index has been visited.
        if (arr[start] < 0) {
            return false;
        }

        // Store original value and mark as visited
        int jump = arr[start];
        arr[start] = -arr[start];

        // Recurse left and right. If either branch finds 0, return true.
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};