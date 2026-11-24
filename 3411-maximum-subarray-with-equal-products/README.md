# 3411. Maximum Subarray With Equal Products
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Array, Math, Sliding Window, Enumeration, Number Theory |
| Date | 2026-11-24 |
| LeetCode Link | https://leetcode.com/problems/maximum-subarray-with-equal-products/ |

## Intuition & Approach
The condition  

```
product(subarray) = lcm(subarray) * gcd(subarray)
```

holds for two numbers because `a·b = gcd(a,b)·lcm(a,b)`.  
For more than two numbers the equality is **not** always true.  

Write every element as a product of prime powers.  
All numbers are ≤ 10, therefore the only possible primes are **2, 3, 5, 7**.  
For a prime `p` let  

* `e_i` – exponent of `p` in the *i*‑th element of the subarray  
* `S = Σ e_i` – total exponent in the product  
* `M = max e_i` – exponent in the LCM  
* `m = min e_i` – exponent in the GCD  

Since  

```
product = Π p^{e_i}          → exponent = S
lcm     = Π p^{M}            → exponent = M
gcd     = Π p^{m}            → exponent = m
```

the equality for prime `p` becomes `S = M + m`.  
Thus the whole subarray is *product equivalent* **iff** this relation holds for **every** prime.

The array length is ≤ 100, so an O(n²) enumeration of all subarrays is trivial.  
For each left endpoint we extend the right endpoint while maintaining, for each prime, the running sum, current maximum and current minimum of exponents.  
After each extension we test the `S = M + m` condition for the four primes; if it holds we update the answer.

Because we only store small integer counters (max exponent for numbers ≤ 10 is ≤ 3), overflow is impossible.

### Why naïve multiplication fails
Directly multiplying the subarray elements quickly exceeds 64‑bit limits (`10¹⁰⁰`).  
Even using big integers would be unnecessary overhead; the prime‑exponent representation avoids this entirely and provides a constant‑time check per extension.

## Complexity Analysis
*Time*:  
The outer loop runs `n` times, the inner loop at most `n` times, and each extension updates/checks four primes →  
\[
O(n^2 \cdot 4) = O(n^2) \quad (n \le 100)
\]

*Space*:  
We store the exponent vector for each element (`n × 4`) → `O(n)` extra space.  
All other variables are `O(1)`.