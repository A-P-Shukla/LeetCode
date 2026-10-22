class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int zeroIndex = ranges::find(nums, 0) - nums.begin();

        auto isNonDecreasing = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prevIndex = (zeroIndex + (i - 1) * step + n) % n;
                int currIndex = (zeroIndex + i * step + n) % n;

                if (nums[prevIndex] > nums[currIndex]) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;
        if (isNonDecreasing(1)) {
            ans = min(ans, zeroIndex);
            ans = min(ans, n - zeroIndex + 2);
        }

        if (isNonDecreasing(-1)) {
            ans = min(ans, zeroIndex + 2);
            ans = min(ans, n - zeroIndex);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
