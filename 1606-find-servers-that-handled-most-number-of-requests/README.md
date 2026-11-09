# 1606. Find Servers That Handled Most Number of Requests

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Heap (Priority Queue), Simulation, Ordered Set |
| Date | 2026-11-09 |
| LeetCode Link | https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/ |

## Intuition & Approach
1. **Model the system as two dynamic groups**  
   - *Busy servers*: each entry stores the time when the server becomes free.  
   - *Free servers*: a sorted collection of server indices that are currently idle.  

2. **Why a naïve simulation fails**  
   - Scanning linearly from the preferred server `(i % k)` until a free one is found costs `O(k)` per request, leading to `O(n·k)` in the worst case (`k, n ≤ 10⁵`).  
   - Keeping only a heap of busy servers leaves us without a fast way to locate the *next* free server respecting the wrap‑around rule.

3. **Optimal data structures**  
   - A **min‑heap** (`busy`) ordered by `(free_time, server_id)` gives the next server that will become idle in `O(log k)`.  
   - An **ordered set** (`free`) of currently idle server IDs supports “find the smallest element ≥ x” (and wrap‑around) in `O(log k)`. In C++ the STL `std::set` provides this directly. In Python we emulate it with a sorted list plus binary search (still `O(log k)` for search; deletion is `O(k)` but passes the given limits).

4. **Processing each request `i`**  
   - **Release** all servers whose `free_time ≤ arrival[i]` by moving them from `busy` to `free`.  
   - If `free` is empty → the request is dropped.  
   - Compute the *preferred* server `pref = i % k`. Use `free.lower_bound(pref)` (C++) / binary search (Python) to locate the first idle server ≥ `pref`. If none exists, wrap to the smallest id in `free`.  
   - Assign the request: increment its handled‑count, push `(arrival[i] + load[i], chosen_id)` into `busy`, and erase `chosen_id` from `free`.

5. **Collect the busiest servers**  
   - After all requests, the maximum value in the `cnt` array determines the busiest load. Return all indices whose count equals this maximum.

The algorithm maintains the exact state required by the problem while guaranteeing `O(n log k)` time and `O(k)` auxiliary space.

## Complexity Analysis
- **Time Complexity:**  
  For each of the `n` requests we perform:  
  - Heap pops for releasing servers – each server is popped once → `O(k log k)` total.  
  - One binary‑search (or `lower_bound`) on the ordered set → `O(log k)` per request.  
  - Heap push for the newly busy server → `O(log k)` per request.  
  Hence overall `O(n log k)` (with `n ≤ 10⁵`, `k ≤ 10⁵`).

- **Space Complexity:**  
  - `cnt` array of size `k`.  
  - Heap and ordered set together store at most `k` server IDs.  
  → `O(k)` extra space.