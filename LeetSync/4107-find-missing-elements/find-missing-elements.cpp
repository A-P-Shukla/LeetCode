class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        unordered_set<int> present(nums.begin(), nums.end());
        
        vector<int> missing;
        
        for (int i = min_val; i <= max_val; ++i) {
            if (present.find(i) == present.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};