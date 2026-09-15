class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int counti = 0;
        int countd = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i-1] <= nums[i]){
                counti++;
            }
        }

        for(int i = 1; i < n; i++){
            if(nums[i-1] >= nums[i]){
                countd++;
            }
        }

        if(counti == n-1 || countd == n-1){
            return true;
        }

        return false;
    }
};