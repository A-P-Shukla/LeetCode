class Solution {
public:
    /**
     * Finds the kth bit in the nth binary string using recursion.
     * Sn = S_{n-1} + "1" + reverse(invert(S_{n-1}))
     */
    char findKthBit(int n, int k) {
        // Base case: S1 is "0"
        if (n == 1) {
            return '0';
        }

        // Length of Sn is 2^n - 1
        int length = (1 << n) - 1;
        int mid = (length / 2) + 1;

        if (k == mid) {
            // The middle bit is always '1' for n > 1
            return '1';
        } else if (k < mid) {
            // If k is in the first half, it's the same as in S_{n-1}
            return findKthBit(n - 1, k);
        } else {
            // If k is in the second half, it's the mirrored, inverted bit from S_{n-1}
            // Mirror position: length - k + 1
            char bit = findKthBit(n - 1, length - k + 1);
            return (bit == '0') ? '1' : '0';
        }
    }
};