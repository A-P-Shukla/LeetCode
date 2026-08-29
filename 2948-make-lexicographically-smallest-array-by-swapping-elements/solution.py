from collections import deque
from typing import List


class Solution:

    def lexicographicallySmallestArray(
        self, nums: List[int], limit: int
    ) -> List[int]:
        n = len(nums)

        # Make a sorted copy of nums to group connected elements
        sorted_nums = sorted(nums)

        group_queues = []
        num_to_group = {}

        # Group elements: adjacent elements with difference <= limit belong to the same group
        for num in sorted_nums:
            if not group_queues or num - group_queues[-1][-1] > limit:
                group_queues.append(deque())

            group_queues[-1].append(num)
            num_to_group[num] = len(group_queues) - 1

        # Reconstruct the lexicographically smallest array
        result = [0] * n
        for i, num in enumerate(nums):
            group = num_to_group[num]
            result[i] = group_queues[group].popleft()

        return result