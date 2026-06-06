#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int left_sum = 0;
        std::vector<int> answer;
        answer.reserve(nums.size());
        
        for (int num : nums) {
            // right_sum is total_sum minus elements seen so far (left_sum) and the current element
            int right_sum = total_sum - left_sum - num;
            answer.push_back(std::abs(left_sum - right_sum));
            // Update left_sum for the next index
            left_sum += num;
        }
        
        return answer;
    }
};