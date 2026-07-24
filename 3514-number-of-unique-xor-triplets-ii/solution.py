class Solution:
    def countUniqueXORTriplets(self, nums: list[int]) -> int:
        # Step 1: Deduplicate elements in nums
        U = list(set(nums))
        n = len(U)
        
        # Step 2: Compute all unique pair XOR values
        S2 = set()
        for i in range(n):
            u_i = U[i]
            for j in range(i, n):
                S2.add(u_i ^ U[j])
                
        # Step 3: Compute all unique triplet XOR values
        S3 = set()
        for w in S2:
            for z in U:
                S3.add(w ^ z)
                
        return len(S3)