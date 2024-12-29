// Code 1:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < k; ++i) {
            int lastElement = nums[n - 1];
            for (int j = n - 1; j > 0; --j) {
                nums[j] = nums[j - 1];
            }
            nums[0] = lastElement;
        }
    }
};

// Code 2:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;
        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                ++count;
            } while (start != current);
        }
    }
};
