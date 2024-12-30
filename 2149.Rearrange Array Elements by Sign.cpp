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

//Optimal:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};
