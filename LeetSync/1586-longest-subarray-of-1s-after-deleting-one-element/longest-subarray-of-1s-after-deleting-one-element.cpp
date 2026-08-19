class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int> temp;
        int i = 0;
        while (i < n) {
            if (nums[i] == 1) {
                count++;
            } else {
                temp.push_back(count);
                count = 0;
            }
            i++;
        }
        temp.push_back(count);

        if(temp.size() == 1){
            return n - 1;
        }

        int maxSum = 0;

        for (int i = 0; i < temp.size() - 1; i++) {
            maxSum = max(maxSum, temp[i] + temp[i + 1]);
        }

        return maxSum;
    }
};