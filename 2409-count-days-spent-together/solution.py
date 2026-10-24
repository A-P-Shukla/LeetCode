from typing import List

class Solution:
    # Days in each month for a non‑leap year
    _MONTH_DAYS: List[int] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    @staticmethod
    def _to_day_of_year(date: str) -> int:
        """Convert 'MM-DD' to 1‑based day of year."""
        month = int(date[:2])
        day = int(date[3:])
        # Sum days of all preceding months
        return day + sum(Solution._MONTH_DAYS[:month - 1])

    def countDaysTogether(self, arriveAlice: str, leaveAlice: str,
                          arriveBob: str, leaveBob: str) -> int:
        a_start = self._to_day_of_year(arriveAlice)
        a_end   = self._to_day_of_year(leaveAlice)
        b_start = self._to_day_of_year(arriveBob)
        b_end   = self._to_day_of_year(leaveBob)

        overlap_start = max(a_start, b_start)
        overlap_end   = min(a_end, b_end)

        if overlap_start > overlap_end:
            return 0
        return overlap_end - overlap_start + 1