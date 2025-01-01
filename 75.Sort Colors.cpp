//Starting 2025 with colors:
class Solution {
public:
    void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int num : nums) {
        if (num == 0){
            count0++;
        }
        else if (num == 1){
            count1++;
        }
        else if (num == 2){
            count2++;
        }
    }
    int i = 0;
    while (count0-- > 0){
        nums[i++] = 0;
    }
    while (count1-- > 0){
        nums[i++] = 1;
    }
    while (count2-- > 0){
        nums[i++] = 2;
    }
    }
};

//One-Pass Dutch National Flag:
class Solution {
public:
    void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            ++low;
            ++mid;
        }
        else if (nums[mid] == 1) {
            ++mid;
        }
        else {
            swap(nums[mid], nums[high]);
            --high;
        }
    }
}
};
