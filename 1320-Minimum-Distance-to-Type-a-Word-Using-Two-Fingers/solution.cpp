#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int memo[301][27];

    // Helper to calculate Manhattan distance between two keyboard indices
    int get_dist(int a, int b) {
        if (a == 26 || b == 26) return 0; // 26 represents "off-board"
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int solve(const string& word, int idx, int other_pos) {
        if (idx == word.length()) return 0;
        if (memo[idx][other_pos] != -1) return memo[idx][other_pos];

        int curr_char_pos = word[idx] - 'A';
        int prev_char_pos = word[idx - 1] - 'A';

        // Option 1: Move the finger that typed word[idx-1] to word[idx]
        int move_finger1 = get_dist(prev_char_pos, curr_char_pos) + solve(word, idx + 1, other_pos);

        // Option 2: Move the "other" finger to word[idx]
        int move_finger2 = get_dist(other_pos, curr_char_pos) + solve(word, idx + 1, prev_char_pos);

        return memo[idx][other_pos] = min(move_finger1, move_finger2);
    }

public:
    int minimumDistance(string word) {
        for (int i = 0; i <= 300; ++i) {
            for (int j = 0; j < 27; ++j) {
                memo[i][j] = -1;
            }
        }
        
        // Initial state: first character is typed by finger 1 for free.
        // Finger 1 is now at word[0], Finger 2 is at index 26 (off-board).
        return solve(word, 1, 26);
    }
};
