class Solution {
public:
    /**
     * @brief Computes the bitwise complement of a base-10 integer.
     * 
     * @param n The input integer.
     * @return The complement of n.
     */
    int bitwiseComplement(int n) {
        // Edge case: The complement of 0 is 1.
        if (n == 0) return 1;

        // mask will store a sequence of 1s of the same bit-length as n.
        unsigned int mask = 1;
        
        // Expand the mask until it covers all bits of n.
        // For example, if n = 5 (101), mask will become 7 (111).
        while (mask < n) {
            mask = (mask << 1) | 1;
        }
        
        // XORing n with the mask flips all bits of n within its range.
        return n ^ mask;
    }
};