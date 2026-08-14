class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        max_len = 0
        left = 0
        count = {}

        for right, char in enumerate(s):
            count[char] = count.get(char, 0) + 1

            # Shrink window from the left until the current character's count is <= 2
            while count[char] > 2:
                count[s[left]] -= 1
                left += 1

            # Update the maximum valid substring length
            max_len = max(max_len, right - left + 1)

        return max_len