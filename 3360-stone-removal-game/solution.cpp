#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns true if Alice wins given an initial pile of n stones.
    bool stoneGame(int n) {
        int required = 10;          // stones to remove on the current turn
        bool aliceTurn = true;      // true if it's Alice's turn, false for Bob

        // Simulate the deterministic decreasing removal sequence.
        while (required > 0 && n >= required) {
            n -= required;          // player takes the required stones
            required--;             // next player must take one fewer stone
            aliceTurn = !aliceTurn; // switch turn
        }

        // Loop exited because the player whose turn it is cannot move.
        // If it's Alice's turn now, she loses; otherwise Alice wins.
        return !aliceTurn;
    }
};