class Solution:
    def maxSumOfSquares(self, num: int, total: int) -> str:
        if total > 9 * num:
            return ""

        digits = []
        for i in range(num):
            positions_left = num - i - 1
            start = 1 if i == 0 and num > 1 else 0

            for d in range(9, start - 1, -1):
                remaining = total - d
                if remaining < 0:
                    continue               
                if remaining > 9 * positions_left:
                    continue               
                digits.append(str(d))
                total -= d
                break
            else:
                return ""

        return "" if total != 0 else "".join(digits)