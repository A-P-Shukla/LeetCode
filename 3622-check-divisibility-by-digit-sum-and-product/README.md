# Check if Number is Divisible by Sum and Product of Digits

## Metadata Table
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Math, Implementation |
| Date | August 22, 2026 |
| LeetCode Link | https://leetcode.com/problems/check-if-number-is-divisible-by-sum-and-product-of-digits/ |

## Intuition
The problem asks us to evaluate a simple mathematical condition on a given positive integer $n$: determine if $n$ is divisible by the sum of its digit sum and its digit product.

To solve this, we can extract the individual digits of $n$ one by one using standard base-10 arithmetic operations (modulo `% 10` to extract the last digit and integer division `/ 10` to shift to the next digit). 

As we extract each digit:
1. Add it to a running `digit_sum` accumulator (initialized to `0`).
2. Multiply it with a running `digit_product` accumulator (initialized to `1`).

After processing all digits, we compute the combined divisor `total = digit_sum + digit_product`. Finally, we check if $n$ is divisible by `total` by verifying if `n % total == 0`.

Note: Since $n \ge 1$, `digit_sum` will always be at least $1$, guaranteeing that `total > 0` and preventing any potential division-by-zero errors.

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(\log_{10} n)$. The algorithm inspects each digit of $n$. For $n \le 10^6$, there are at most $7$ digits, meaning the loop runs in constant time $\mathcal{O}(1)$ in practice.
- **Space Complexity:** $\mathcal{O}(1)$. Only a few primitive integer variables are used for intermediate calculations, requiring constant auxiliary space.