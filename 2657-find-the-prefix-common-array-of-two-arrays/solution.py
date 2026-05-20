class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        n = len(A)
        C = [0] * n
        # Frequency list tracking the count of each number seen so far (1 to n)
        freq = [0] * (n + 1)
        common_count = 0
        
        for i in range(n):
            # Process current element of A
            freq[A[i]] += 1
            if freq[A[i]] == 2:
                common_count += 1
                
            # Process current element of B
            freq[B[i]] += 1
            if freq[B[i]] == 2:
                common_count += 1
                
            # Record the prefix common count
            C[i] = common_count
            
        return C