//USING BINARY SEARCH

/*
Algorithm
Sort the Array: Sort nums. Time: O(N log N).
Check Array Size: If n < 4, return empty.
Outer Loops (Fix a, b, c):
Iterate a from 0 to n-4.
Skip duplicates for a.
Iterate b from a+1 to n-3.
Skip duplicates for b.
Iterate c from b+1 to n-2.
Skip duplicates for c.
Calculate Target for d: Calculate the value the fourth element (d) must have: long long target_d = (long long)target - nums[a] - nums[b] - nums[c]; Use long long to avoid overflow.
Binary Search: Perform a binary search for target_d within the subarray nums[c+1 ... n-1]. Time: O(log N).
Store Result: If target_d is found by the binary search, it means a valid quadruplet exists. Since the array is sorted and we ensured a < b < c < d (because we search in nums[c+1...]), the indices are distinct. Add the quadruplet {nums[a], nums[b], nums[c], (int)target_d} to a result container. Using a std::set<vector<int>> is the easiest way to automatically handle cases where different combinations of a, b, c might lead to the same quadruplet values.
Convert and Return: Convert the set of unique quadruplets into a vector<vector<int>> and return it.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> results_set; 
        int n = nums.size();
        if (n < 4) {
            return {};
        }
        sort(nums.begin(), nums.end()); 
        for (int a = 0; a < n - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
             if ((long long)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
             if ((long long)nums[a] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for (int b = a + 1; b < n - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                if ((long long)nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) break;
                if ((long long)nums[a] + nums[b] + nums[n - 2] + nums[n - 1] < target) continue;
                for (int c = b + 1; c < n - 1; ++c) {
                    if (c > b + 1 && nums[c] == nums[c - 1]) {
                        continue;
                    }
                    long long target_d = (long long)target - nums[a] - nums[b] - nums[c];
                    if (c + 1 < n && (target_d < nums[c+1] || target_d > nums[n-1])) {
                         if (target_d < nums[c+1]) break; // Can break 'c' loop
                         else continue; 
                    }
                    bool found = binary_search(nums.begin() + c + 1, nums.end(), (int)target_d);
                    if (found) {
                        results_set.insert({nums[a], nums[b], nums[c], (int)target_d});
                    }
                }
            }
        }
        vector<vector<int>> ans(results_set.begin(), results_set.end());
        return ans;
    }
};
