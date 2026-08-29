class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<std::deque<int>> groupQueues;
        unordered_map<int, int> numToGroup;

        for (int i = 0; i < n; ++i) {
            if (i == 0 || sortedNums[i] - sortedNums[i - 1] > limit) {
                groupQueues.push_back({});
            }
            groupQueues.back().push_back(sortedNums[i]);
            numToGroup[sortedNums[i]] = groupQueues.size() - 1;
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int group = numToGroup[nums[i]];
            result[i] = groupQueues[group].front();
            groupQueues[group].pop_front();
        }

        return result;
    }
};