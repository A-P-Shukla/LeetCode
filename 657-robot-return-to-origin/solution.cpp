class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;

        for (char move : moves) {
            // Update coordinates based on the direction
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'R') {
                x++;
            } else if (move == 'L') {
                x--;
            }
        }

        // The robot returns to origin if both net displacements are zero
        return (x == 0 && y == 0);
    }
};