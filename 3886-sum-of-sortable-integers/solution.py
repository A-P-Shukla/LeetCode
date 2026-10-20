import sys
from typing import List

def build_lps(pat: List[int]) -> List[int]:
    m = len(pat)
    lps = [0] * m
    i, length = 1, 0
    while i < m:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length:
            length = lps[length - 1]
        else:
            lps[i] = 0
            i += 1
    return lps

def is_cyclic_equal(src: List[int], tgt: List[int]) -> bool:
    k = len(src)
    if k == 0:
        return True
    lps = build_lps(tgt)
    i = j = 0
    while i < 2 * k:
        txt = src[i % k]
        if txt == tgt[j]:
            i += 1
            j += 1
            if j == k:
                start = i - j
                if start < k:
                    return True
                j = lps[j - 1]          # continue searching
        else:
            if j:
                j = lps[j - 1]
            else:
                i += 1
    return False

def check_k(nums: List[int], sorted_nums: List[int], k: int) -> bool:
    n = len(nums)
    for start in range(0, n, k):
        if not is_cyclic_equal(nums[start:start + k], sorted_nums[start:start + k]):
            return False
    return True

def main() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    nums = [int(next(it)) for _ in range(n)]
    sorted_nums = sorted(nums)

    # collect divisors of n
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
        if check_k(nums, sorted_nums, k):
            ans += k
    print(ans)

if __name__ == "__main__":
    main()