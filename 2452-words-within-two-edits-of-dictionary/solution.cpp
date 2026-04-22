#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordsWithinTwoEdits(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for (const string& query : queries) {
            bool foundMatch = false;
            
            for (const string& word : dictionary) {
                int diffCount = 0;
                
                // Compare query and word character by character
                for (int i = 0; i < query.length(); ++i) {
                    if (query[i] != word[i]) {
                        diffCount++;
                    }
                    // Optimization: If differences exceed 2, this word is not a match
                    if (diffCount > 2) break;
                }
                
                // If we found a word in the dictionary within 2 edits
                if (diffCount <= 2) {
                    foundMatch = true;
                    break;
                }
            }
            
            if (foundMatch) {
                result.push_back(query);
            }
        }
        
        return result;
    }
};