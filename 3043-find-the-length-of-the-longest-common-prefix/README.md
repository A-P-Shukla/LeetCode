# 3043. Find the Length of the Longest Common Prefix

### Property | Value
--- | ---
Difficulty | Medium
Topics | Array, Hash Table, String, Trie
Date | May 21, 2026
LeetCode Link | [Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/)

---

### Intuition

The problem asks us to find the length of the longest common prefix between any number in `arr1` and any number in `arr2`. 

A key realization is that positive integers up to $10^8$ have at most $9$ digits. Thus, each number has at most $9$ possible prefixes (e.g., the prefixes of `1234` are `1`, `12`, `123`, and `1234`). 

Instead of doing a brute-force pairwise comparison of size $O(N \times M)$ which would TLE, we can:
1. **Store all possible prefixes** of every number in `arr1` into a Hash Set. Since the maximum length of any number is 9, the hash set will contain at most $9 \times \text{arr1.length}$ elements.
2. **Search for prefixes** of each number in `arr2` within the Hash Set. We can search from the longest prefix of each number to the shortest (by repeatedly dividing the number by 10). 
3. **Pruning Optimization**: If the length of a candidate number (or its current prefix) from `arr2` is less than or equal to the current maximum prefix length found so far (`max_len`), we can immediately stop exploring that number.

This approach bypasses the overhead of building a literal character Trie while achieving the same optimal complexity using a flat, cache-friendly hash set.

---

### Complexity Analysis

- **Time Complexity:** $\mathcal{O}((N + M) \log_{10}(\text{max\_val}))$ where $N$ and $M$ are the sizes of `arr1` and `arr2` respectively, and $\text{max\_val}$ is the maximum value in the arrays ($10^8$). Since $\log_{10}(10^8) \le 8$, the loop runs at most 8 times per number. This simplifies to a highly efficient $\mathcal{O}(N + M)$ time complexity.
- **Space Complexity:** $\mathcal{O}(N \log_{10}(\text{max\_val}))$ to store all prefixes of `arr1` in the hash set. For $N = 5 \times 10^4$, this is at most $\approx 4.5 \times 10^5$ integers, which easily fits within memory.

---

### CPP_START
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
    // Helper to get the number of digits of an integer
    int getLength(int num) {
        int len = 0;
        while (num > 0) {
            len++;
            num /= 10;
        }
        return len;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // Step 1: Insert all prefixes of elements in arr1 into the hash set
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }
        
        int max_len = 0;
        
        // Step 2: For each element in arr2, find its longest prefix present in the set
        for (int val : arr2) {
            int len = getLength(val);
            
            // Pruning: if the current number is already shorter than or equal to max_len, skip
            if (len <= max_len) continue;
            
            while (val > 0) {
                if (prefixes.count(val)) {
                    max_len = max(max_len, len);
                    break; // Since we check longest to shortest, the first match is the best
                }
                val /= 10;
                len--;
                
                // Early exit: if remaining prefix length is less than or equal to max_len, stop
                if (len <= max_len) break;
            }
        }
        
        return max_len;
    }
};
---CPP_END---

---PYTHON_START
class Solution:
    def longestCommonPrefix(self, arr1: list[int], arr2: list[int]) -> int:
        prefixes = set()
        
        # Step 1: Add all possible prefixes from arr1 into the set
        for val in arr1:
            while val > 0:
                prefixes.add(val)
                val //= 10
                
        max_len = 0
        
        # Step 2: Check prefixes from arr2, going from longest to shortest
        for val in arr2:
            length = len(str(val))
            
            # Pruning: skip if the number of digits is already smaller than or equal to max_len
            if length <= max_len:
                continue
                
            while val > 0:
                if val in prefixes:
                    max_len = max(max_len, length)
                    break # First match going downwards is always the longest possible for this number
                
                val //= 10
                length -= 1
                
                # Early exit: no need to search shorter prefixes if they cannot beat max_len
                if length <= max_len:
                    break
                    
        return max_len
---PYTHON_END---