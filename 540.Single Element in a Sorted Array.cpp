//Code 1:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        if (n == 1) return nums[0];
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};

//Code 2:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n-1 && nums[n - 1] != nums[n - 2]) return nums[mid];

            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid +1]) return nums[mid];

            if(mid % 2 == 0){
                if (nums[mid - 1] == nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else{
                if (nums[mid - 1] == nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
