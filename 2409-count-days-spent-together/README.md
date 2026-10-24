# 2409. Count Days Spent Together
| Property | Value |
| --- | --- |
| Difficulty | Easy |
| Topics | Math, String |
| Date | 2026-10-24 |
| LeetCode Link | https://leetcode.com/problems/count-days-spent-together/ |

## Intuition & Approach
1. **Represent dates as an integer offset** – Map each “MM‑DD” string to the day‑of‑year (1‑based).  
   * Use a static array `monthDays = {31,28,31,30,31,30,31,31,30,31,30,31}`.  
   * For a date `MM-DD`, sum the days of all preceding months and add the day component.  
   This yields a linear order where later calendar dates have larger integer values, enabling simple interval arithmetic.

2. **Identify the overlapping interval** –  
   * Alice’s interval: `[aStart, aEnd]`  
   * Bob’s interval: `[bStart, bEnd]`  
   * Overlap start = `max(aStart, bStart)`  
   * Overlap end   = `min(aEnd,   bEnd)`  
   If `overlapStart > overlapEnd` there is no common day; otherwise the number of shared days is `overlapEnd - overlapStart + 1`.

3. **Why not scan day‑by‑day?**  
   Direct enumeration would be `O(365)` per query, which is unnecessary overhead for a single interval problem. Converting to day‑of‑year reduces the work to a constant number of arithmetic operations, delivering true O(1) time.

4. **Correctness proof sketch**  
   *Mapping*: The conversion function is strictly monotonic because each month adds a positive constant number of days; therefore the ordering of dates is preserved.  
   *Overlap*: For any two closed intervals on the integer line, the intersection is either empty or another closed interval `[max(l1,l2), min(r1,r2)]`. The algorithm computes exactly these bounds, guaranteeing that if the intersection is non‑empty its length (inclusive) is `min(r1,r2) - max(l1,l2) + 1`. Hence the returned count equals the exact number of days both are present.

## Complexity Analysis
- **Time Complexity:** `O(1)` – constant work for parsing four strings and a few arithmetic operations.  
- **Space Complexity:** `O(1)` – only a handful of integer variables; no dynamic allocation.