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



//USING DIVIDE AND CONQUER

/*
Algorithm
Sort the Array: Sort the input array nums. This is crucial for efficiently finding pairs with the two-pointer technique and for skipping duplicate quadruplets. Time complexity: O(N log N).
Check Array Size: If the array has fewer than 4 elements, return an empty result immediately.
Outer Loops (Fixing a and b):
Iterate through the array with an index a from 0 up to n-4.
Skip Duplicates for a: If a > 0 and nums[a] == nums[a-1], continue to the next iteration to avoid duplicate quadruplets starting with the same first element.
Inside the a loop, iterate with an index b from a + 1 up to n-3.
Skip Duplicates for b: If b > a + 1 and nums[b] == nums[b-1], continue to the next iteration to avoid duplicate quadruplets starting with the same first two elements.
Inner Two Pointers (Finding c and d):
For the fixed nums[a] and nums[b], we need to find pairs (nums[c], nums[d]) in the rest of the array (nums[b+1] to nums[n-1]) such that nums[c] + nums[d] == target - nums[a] - nums[b].
Calculate the remaining_target needed from the pair (c, d). Be mindful of potential integer overflows, use long long. long long remaining_target = (long long)target - nums[a] - nums[b];
Initialize two pointers: left = b + 1 and right = n - 1.
Two-Pointer Search: While left < right:
Calculate the current_sum of the elements at the pointers: long long current_sum = (long long)nums[left] + nums[right];
If current_sum == remaining_target:
We found a valid quadruplet: {nums[a], nums[b], nums[left], nums[right]}. Add it to the result vector.
Skip Duplicates for left: Increment left while left < right and nums[left] == nums[left + 1].
Skip Duplicates for right: Decrement right while left < right and nums[right] == nums[right - 1].
Move the pointers inward: left++, right--.
If current_sum < remaining_target: Increment left to increase the sum.
If current_sum > remaining_target: Decrement right to decrease the sum.
Return Result: After all iterations, return the vector containing the unique quadruplets.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            if ((long long)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) {
                break;
            }
            if ((long long)nums[a] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }
            for (int b = a + 1; b < n - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                if ((long long)nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) {
                    break; 
                }
                if ((long long)nums[a] + nums[b] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }
                long long remaining_target = (long long)target - nums[a] - nums[b];
                int left = b + 1;
                int right = n - 1;
                while (left < right) {
                    long long current_sum = (long long)nums[left] + nums[right];
                    if (current_sum == remaining_target) {
                        ans.push_back({nums[a], nums[b], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (current_sum < remaining_target) {
                        left++;
                    } else { 
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
