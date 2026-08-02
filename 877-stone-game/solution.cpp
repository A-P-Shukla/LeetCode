class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Alice can always win by choosing to take either all even-indexed piles
        // or all odd-indexed piles. Since the sum of all stones is odd and the 
        // total number of piles is even, one set of indices strictly exceeds the other.
        // Therefore, Alice can always pick the winning strategy on turn 1.
        return true;
    }
};