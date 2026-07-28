class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        half_len = n // 2
        
        # Extract the first half and sort it alphabetically
        half = "".join(sorted(s[:half_len]))
        
        # If length is odd, middle character is fixed at s[half_len]
        mid = s[half_len] if n % 2 == 1 else ""
        
        # Reconstruct the smallest palindromic permutation
        return half + mid + half[::-1]