class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int n : nums){
            pq.push(n);
        }

        int n = 0;

        for(int i = 0; i <= nums.size() - k; i++){
            n = pq.top();
            pq.pop();
        }

        return n;
    }
};