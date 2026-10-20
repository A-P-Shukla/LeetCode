from typing import List

class Solution:
    def sumOfSortableIntegers(self, nums: List[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)

        # collect all divisors of n
        divisors = []
        i = 1
        while i * i <= n:
            if n % i == 0:
                divisors.append(i)
                if i != n // i:
                    divisors.append(n // i)
            i += 1

        ans = 0
        for k in divisors:
            ok = True
            for start in range(0, n, k):
                orig = nums[start:start + k]
                target = sorted_nums[start:start + k]

                # check if target is a rotation of orig
                block_ok = False
                for offset in range(k):
                    if orig[offset] != target[0]:
                        continue
                    match = True
                    for i in range(k):
                        if orig[(offset + i) % k] != target[i]:
                            match = False
                            break
                    if match:
                        block_ok = True
                        break
                if not block_ok:
                    ok = False
                    break
            if ok:
                ans += k
        return ans