# 3129. Find All Possible Stable Binary Arrays I

| Property | Value |
| :--- | :--- |
| Difficulty | Medium |
| Topics | Dynamic Programming, Prefix Sum |
| Date | March 09, 2026 |
| LeetCode Link | https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/ |

## Intuition

The problem asks for the count of binary arrays containing exactly `zero` zeros and `one` ones, subject to a stability constraint: any subarray longer than `limit` must contain both 0 and 1.

The stability constraint essentially means that we cannot have a contiguous sequence of $0$s of length greater than `limit`, nor a contiguous sequence of $1$s of length greater than `limit`. If we had $L+1$ consecutive identical elements (say, 0s), and $L+1 > \text{limit}$, then this subarray violates the condition. Thus, the maximum consecutive run of either 0s or 1s is `limit`.

This structure strongly suggests Dynamic Programming. We need to build the array step by step, keeping track of how many zeros and ones remain to be placed, and crucially, what the last element placed was, and how many times it has repeated consecutively.

Let $DP[i][j][k]$ be the number of valid prefixes formed using exactly $i$ zeros and $j$ ones, where $k$ indicates the last element appended:
*   $k=0$: The last element appended was '0'.
*   $k=1$: The last element appended was '1'.

However, just knowing the last element isn't enough; we need to know the length of the current run to enforce the `limit`. Since the constraint is based on the run length up to `limit`, we can simplify the state by realizing that if we are placing a '0', we must ensure that the run of preceding '0's (or '1's if the previous element was '1') does not exceed `limit`.

A more standard DP approach for sequence construction problems involves defining the state based on the remaining counts and the history required for the next transition.

Let $DP[z][o][last]$ be the number of ways to complete an array using exactly $z$ remaining zeros and $o$ remaining ones, given that the previous element placed determined the starting condition for the current run.

If we are placing the next element, say '0', this '0' must start a new run or extend an existing run of '0's. The stability constraint only cares if *any* run exceeds `limit`.

Consider the required history: to place the next element, we need to know how many of that same element have been placed consecutively *immediately preceding this position*.

Let $DP[z][o][k][\text{type}]$:
*   $z$: Zeros remaining.
*   $o$: Ones remaining.
*   $k$: Length of the current consecutive run ending at this position ($1 \le k \le \text{limit}$).
*   $\text{type} \in \{0, 1\}$: The element that constitutes the current run (0 or 1).

Since $z, o \le 200$ and $\text{limit} \le 200$, the state space would be $200 \times 200 \times 200 \times 2$, which is too large ($16$ million states).

We can optimize the state based on the nature of the transitions. When we transition from $DP[z_1][o_1][k_1][\text{type}_1]$ to $DP[z_2][o_2][k_2][\text{type}_2]$:

1.  **Extend run:** If $\text{type}_2 = \text{type}_1$ and $k_2 = k_1 + 1$, we must have $k_2 \le \text{limit}$.
2.  **Start new run:** If $\text{type}_2 \neq \text{type}_1$, then $k_2 = 1$.

The critical observation is that if we are trying to place a sequence of $m$ identical elements ($1 \le m \le \text{limit}$), the number of ways to do this depends only on the state *before* this sequence started.

Let $DP[z][o][0]$ be the number of stable arrays formed using $z$ zeros and $o$ ones, ending with a '0'.
Let $DP[z][o][1]$ be the number of stable arrays formed using $z$ zeros and $o$ ones, ending with a '1'.

To calculate $DP[z][o][0]$ (ending in 0): The immediately preceding sequence must have been $m$ zeros, where $1 \le m \le \min(z, \text{limit})$. The array preceding these $m$ zeros must have ended in a '1' (or it was the start of the array).

If we append $m$ zeros ($1 \le m \le \min(z, \text{limit})$):
The state we came from must have used $z-m$ zeros and $o$ ones, and ended in a '1'.
$$DP[z][o][0] = \sum_{m=1}^{\min(z, \text{limit})} DP[z-m][o][1]$$

Similarly, for $DP[z][o][1]$ (ending in 1):
$$DP[z][o][1] = \sum_{m=1}^{\min(o, \text{limit})} DP[z][o-m][0]$$

**Base Case:**
An empty array is the starting point. We need to define a virtual base state that allows transitions to start the array.

If $z=0$ and $o=0$, the count is 1 (for the empty array), but we use this DP state definition for *non-empty* prefixes, so the base case needs careful handling.

Let $DP[z][o][0]$ be the number of stable arrays using exactly $z$ zeros and $o$ ones, ending in 0.
Let $DP[z][o][1]$ be the number of stable arrays using exactly $z$ zeros and $o$ ones, ending in 1.

Initialize $DP$ table to 0.
The transitions naturally build sequences from smaller counts to larger counts. We iterate $z$ from 0 to `zero` and $o$ from 0 to `one`.

**Initialization (The first element):**
When $z>0, o=0$: $DP[z][0][0] = 1$ if $z \le \text{limit}$, else 0. (Array is $0, 0, \dots, 0$)
When $z=0, o>0$: $DP[0][o][1] = 1$ if $o \le \text{limit}$, else 0. (Array is $1, 1, \dots, 1$)

For the general iteration, we can define $DP[0][0][0] = DP[0][0][1] = 0$. We need a way to start the sequence.

If we are calculating $DP[z][o][0]$:
1. If the array consists only of $z$ zeros (i.e., $o=0$): This is valid only if $z \le \text{limit}$. (Handled in initialization if we use it carefully).
2. If the array ends with $m$ zeros ($1 \le m \le \min(z, \text{limit})$) and the element before that was '1' (or the array started with these $m$ zeros):

If $z=m$ and $o=0$: $DP[z][0][0] = 1$ if $z \le \text{limit}$.
If $z>m$ and $o>0$: We transition from $DP[z-m][o][1]$.

A cleaner way is to use an artificial base case representing the "state before the first element," which can transition to either a 0-run or a 1-run of length $m$.

Let $DP[z][o][0]$ be the count ending in 0, and $DP[z][o][1]$ ending in 1.
We iterate $z$ from 0 to `zero`, $o$ from 0 to `one`. Skip $(0, 0)$.

**Transition:**

For current $(z, o)$:
If $z \ge 1$:
$$DP[z][o][0] = \sum_{m=1}^{\min(z, \text{limit})} \begin{cases} 1 & \text{if } o=0 \text{ and } z=m \text{ (Base case: pure 0s)} \\ DP[z-m][o][1] & \text{if } o>0 \text{ or } z>m \text{ (Transition from ending in 1)} \end{cases}$$

If $o \ge 1$:
$$DP[z][o][1] = \sum_{m=1}^{\min(o, \text{limit})} \begin{cases} 1 & \text{if } z=0 \text{ and } o=m \text{ (Base case: pure 1s)} \\ DP[z][o-m][0] & \text{if } z>0 \text{ or } o>m \text{ (Transition from ending in 0)} \end{cases}$$

We must perform all calculations modulo $10^9 + 7$.

**Simplifying Base Cases:**
If we define $DP[0][0][0] = DP[0][0][1] = 1$ (representing the empty prefix), then:

If $z=m, o=0$: $DP[m][0][0]$ sums $DP[0][0][1] = 1$ (when $m=1$), $DP[-1][0][1]$ (impossible). This formulation is tricky for the pure sequences.

Let's stick to the recursive structure and handle the start explicitly:
For $DP[z][o][0]$ (ending in 0):
1.  If $o=0$: Only possible if $1 \le z \le \text{limit}$. Count is 1.
2.  If $o>0$: We must transition from a state ending in 1.
    $$DP[z][o][0] = \sum_{m=1}^{\min(z, \text{limit})} DP[z-m][o][1]$$

For $DP[z][o][1]$ (ending in 1):
1.  If $z=0$: Only possible if $1 \le o \le \text{limit}$. Count is 1.
2.  If $z>0$: We must transition from a state ending in 0.
    $$DP[z][o][1] = \sum_{m=1}^{\min(o, \text{limit})} DP[z][o-m][0]$$

We must iterate in an order such that $DP[z-m][o][1]$ and $DP[z][o-m][0]$ are already computed. Iterating $z$ and $o$ incrementally works perfectly.

**Final Answer:** $DP[\text{zero}][\text{one}][0] + DP[\text{zero}][\text{one}][1]$.

**Optimization using Prefix Sums (Crucial for efficiency):**
The sums involve calculating $\sum DP[\cdot][\cdot][\cdot]$ over a contiguous range of indices (the $m$ loop). This is a classic use case for prefix sums to reduce the $O(\text{limit})$ calculation per state to $O(1)$.

Let $S[z][o][\text{type}]$ be the prefix sum of $DP$ values up to $z$ or $o$:
Define $P0[z][o] = \sum_{i=0}^{z} DP[i][o][0]$ (Prefix sum over $z$ for fixed $o$ and ending type 0). (This seems overly complicated due to the nature of the sum).

Let's analyze the transition sum again:
$$DP[z][o][0] = \sum_{m=1}^{\min(z, \text{limit})} DP[z-m][o][1]$$
Let $z' = z-m$. As $m$ goes from $1$ to $\min(z, L)$, $z'$ goes from $z-1$ down to $\max(0, z-L)$.

If $o>0$:
$$DP[z][o][0] = DP[z-1][o][1] + DP[z-2][o][1] + \dots + DP[\max(0, z-L)][o][1]$$

We can relate $DP[z][o][0]$ to $DP[z-1][o][0]$:
$$DP[z-1][o][0] = DP[z-2][o][1] + \dots + DP[\max(0, z-1-L)][o][1]$$

Subtracting the two:
$$DP[z][o][0] - DP[z-1][o][0] = DP[z-1][o][1] - DP[\max(0, z-L-1)][o][1]$$

Where $DP[k][o][1] = 0$ if $k < 0$.
If $z > L$:
$$DP[z][o][0] = DP[z-1][o][0] + DP[z-1][o][1] - DP[z-L-1][o][1]$$
If $z \le L$:
$$DP[z][o][0] = DP[z-1][o][0] + DP[z-1][o][1]$$ (Since $z-L-1 < 0$)

This transforms the $O(L)$ summation into $O(1)$ transition, making the total time complexity $O(\text{zero} \cdot \text{one})$. Given constraints of 200, this is $O(40000)$, which is very fast.

We need to handle the base cases ($o=0$ for type 0, $z=0$ for type 1) separately, as they do not have a predecessor ending in the opposite type.

**Revised Iteration Structure:**

Initialize $DP[z][o][\text{type}] = 0$. MOD = $10^9 + 7$.

Iterate $z$ from 0 to `zero`.
Iterate $o$ from 0 to `one`.
If $z=0$ and $o=0$, continue.

1. **Calculate $DP[z][o][0]$ (Ending in 0):**
   If $o=0$:
     If $1 \le z \le \text{limit}$, $DP[z][0][0] = 1$.
   If $o>0$:
     If $z=1$: $DP[1][o][0] = DP[0][o][1] \pmod{MOD}$ (This is the starting 0, preceded by a sequence ending in 1).
     If $z>1$:
       $DP[z][o][0] = (DP[z-1][o][0] + DP[z-1][o][1]) \pmod{MOD}$.
       If $z > \text{limit}$:
         $DP[z][o][0] = (DP[z][o][0] - DP[z-\text{limit}-1][o][1] + MOD) \pmod{MOD}$.

2. **Calculate $DP[z][o][1]$ (Ending in 1):**
   If $z=0$:
     If $1 \le o \le \text{limit}$, $DP[0][o][1] = 1$.
   If $z>0$:
     If $o=1$: $DP[z][1][1] = DP[z][0][0] \pmod{MOD}$.
     If $o>1$:
       $DP[z][o][1] = (DP[z][o-1][1] + DP[z][o-1][0]) \pmod{MOD}$.
       If $o > \text{limit}$:
         $DP[z][o][1] = (DP[z][o][1] - DP[z][o-\text{limit}-1][0] + MOD) \pmod{MOD}$.

The transitions for $z=1$ and $o=1$ are slightly simpler:
If $z=1, o>0$: $DP[1][o][0]$ is the sum of 1 zero preceded by any sequence ending in 1 using $o$ ones. The only state ending in 1 using $o$ ones is $DP[0][o][1]$. So $DP[1][o][0] = DP[0][o][1]$. (This matches the $z>L$ formula if we assume $DP[0][o][0]=0$).

Let's re-examine the $z=1$ case using the derived recurrence:
For $z=1, o>0$:
$DP[1][o][0] = (DP[0][o][0] + DP[0][o][1]) \pmod{MOD}$. Since $DP[0][o][0]=0$ (cannot end in 0 if $z=0$), this yields $DP[0][o][1]$. This seems correct for the start of the sequence.

The approach using the simplified recurrence relation derived from the prefix sum logic appears robust across the indices, provided we initialize the table correctly (all zeros) and handle the edge cases where the subtraction index falls below zero by using the property $DP[k][\dots] = 0$ for $k<0$.

Final result: $(DP[\text{zero}][\text{one}][0] + DP[\text{zero}][\text{one}][1]) \pmod{MOD}$.