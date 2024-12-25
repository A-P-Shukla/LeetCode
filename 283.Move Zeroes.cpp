//SOLUTION 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i  = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
            }
        }
        int j = 0;
        while(j < count){
            for(int i  = 1; i < n; i++){
                if(nums[i-1]==0){
                swap(nums[i-1], nums[i]);
                }
            }
            j++;
        }
        for(int i = 0; i < n; i++){
            cout<<nums[i];
        }
    }
};

//SOLUTION 2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i  = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
            }
        }
        for(int i = 0; i < count; i++){
            for(int i  = 1; i < n; i++){
                if(nums[i-1]==0){
                swap(nums[i-1], nums[i]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout<<nums[i];
        }
    }
};
