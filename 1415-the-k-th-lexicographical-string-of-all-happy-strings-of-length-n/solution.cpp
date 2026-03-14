class Solution {
public:
    /**
     * @param n Length of the happy string.
     * @param k The lexicographical index (1-based) to find.
     * @return The k-th happy string or an empty string if it doesn't exist.
     */
    string getHappyString(int n, int k) {
        string current = "";
        string result = "";
        int count = 0;
        
        backtrack(n, k, current, count, result);
        
        return result;
    }

private:
    void backtrack(int n, int k, string& current, int& count, string& result) {
        // If we have already found the k-th string, stop recursion
        if (!result.empty()) return;

        // Base case: current string reached required length
        if (current.length() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }

        // Try 'a', 'b', and 'c' in order to maintain lexicographical sorting
        for (char ch : {'a', 'b', 'c'}) {
            // Happy string constraint: s[i] != s[i-1]
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                backtrack(n, k, current, count, result);
                current.pop_back(); // Backtrack step
                
                // Early exit if result is found in a deeper recursion level
                if (!result.empty()) return;
            }
        }
    }
};
