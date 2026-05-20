#include <vector>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();
        std::vector<int> C(n);
        // Frequency array to keep track of element occurrences.
        // Elements are 1-indexed and range from 1 to n.
        std::vector<int> freq(n + 1, 0);
        int common_count = 0;
        
        for (int i = 0; i < n; ++i) {
            // Process the element from array A
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common_count++;
            }
            
            // Process the element from array B
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common_count++;
            }
            
            // Store the count of common elements up to index i
            C[i] = common_count;
        }
        
        return C;
    }
};