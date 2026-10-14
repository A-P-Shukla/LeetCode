class Solution:
    def largestNumber(self, num: int, total: int) -> str:
        """
        Construct the maximum integer (as a string) with exactly `num` digits
        whose digits sum to `total` and whose sum of squares is maximized.
        """
        # If the required sum is unattainable, return empty string
        if total > 9 * num:
            return ""

        digits = []
        for i in range(num):
            positions_left = num - i - 1
            # Leading digit cannot be zero when the number has more than one digit
            start = 1 if i == 0 and num > 1 else 0

            # Pick the biggest digit that leaves a feasible remainder
            for d in range(9, start - 1, -1):
                remaining = total - d
                if remaining < 0:
                    continue               # sum would become negative
                if remaining > 9 * positions_left:
                    continue               # not enough capacity to distribute remaining sum
                digits.append(str(d))
                total -= d
                break
            else:
                # No digit fits – should not happen after the initial feasibility test
                return ""

        # Safety check: total must be exactly 0 now
        return "" if total != 0 else "".join(digits)