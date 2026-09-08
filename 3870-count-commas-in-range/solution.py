class Solution:
    def countCommas(self, n: int) -> int:
        total_commas = 0
        threshold = 1000

        # Add the contribution for each threshold of 1000^k
        while n >= threshold:
            total_commas += n - threshold + 1
            threshold *= 1000

        return total_commas