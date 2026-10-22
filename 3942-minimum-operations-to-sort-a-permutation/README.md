# 3942. Minimum Operations to Sort a Permutation
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array |
| Date | 2026-10-22 |
| LeetCode Link | https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/ |

**Intuition & Approach**  
The allowed operations generate the dihedral group Dₙ on the index set {0,…,n‑1}.  
* **Rotate left by one** – a cyclic shift (rotation).  
* **Reverse whole array** – a reflection (reversal).  

Any composition of these two operations is either  
1. a pure rotation of the sorted array, or  
2. a rotation of the *reversed* sorted array (the single reversal can be placed anywhere; surrounding rotations only change the rotation offset).  

Therefore a permutation `nums` is sortable **iff** it is a rotation of `[0,1,…,n‑1]` **or** a rotation of `[n‑1,n‑2,…,0]`.

*If it is a rotation of the sorted array*  
&nbsp;&nbsp;→ apply `k` left‑rotations, where `k` is the index of `0`.  
*If it is a rotation of the reversed array*  
&nbsp;&nbsp;→ first reverse (cost 1), then the array becomes a rotation of the sorted array with offset `n‑k`. One more `k` left‑rotations restore order.  
Thus the cost in this case is `1 + k`, where `k` is the index of `n‑1` in `nums`.

The answer is the minimum of the two feasible costs; if neither pattern matches, return `-1`.

**Complexity Analysis**  
*Time*: O(n) – a single scan to locate `0` and `n‑1`, plus verification of the two candidate patterns.  
*Space*: O(1) – only a few integer variables; the input array is modified in‑place only by the algorithm’s logic (no extra containers).