class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        def is_palindrome(l: int, r: int) -> bool:
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        n = len(s)
        count = 0
        last_end = 0 

        for i in range(k - 1, n):
            if i - k + 1 >= last_end and is_palindrome(i - k + 1, i):
                count += 1
                last_end = i + 1
            elif i - k >= last_end and is_palindrome(i - k, i):
                count += 1
                last_end = i + 1

        return count