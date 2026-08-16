class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Count remainders when divided by 3
        int cnt[3] = {0, 0, 0};
        for (int s : stones) {
            cnt[s % 3]++;
        }

        // If count of 0-remainder stones is even, it doesn't change the turn parity 
        // in the long run. Alice wins if she can start a sequence and Bob is 
        // forced to lose. This requires both Type 1 and Type 2 stones to exist.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If count of 0-remainder stones is odd, Bob can flip the turn.
        // Alice wins only if she has a surplus of one type (more than 2)
        // to offset the turn flip.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};