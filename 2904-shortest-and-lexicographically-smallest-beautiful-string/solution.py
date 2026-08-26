class Solution:
    def shortestBeautifulString(self, s: str, k: int) -> str:
        # Collect 0-based indices of all '1's
        ones = [i for i, ch in enumerate(s) if ch == '1']
        
        # If total '1's is less than k, no beautiful substring is possible
        if len(ones) < k:
            return ""
        
        ans = ""
        
        # Check every window of k '1's
        for i in range(len(ones) - k + 1):
            start = ones[i]
            end = ones[i + k - 1]
            sub = s[start : end + 1]
            
            # Select the shortest string; break ties lexicographically
            if not ans or len(sub) < len(ans) or (len(sub) == len(ans) and sub < ans):
                ans = sub
                
        return ans