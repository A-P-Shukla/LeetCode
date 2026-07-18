class Solution {
public:
    int findGCD(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        return gcd(low, high);
    }
};