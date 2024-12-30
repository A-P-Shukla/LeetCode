// Brute Force:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
        }
        for(int j = 0; j < n/2; j++){
            ans[2 * j] = pos[j];
            ans[2 * j + 1] = neg[j];
        }
        return ans;
    }
};
