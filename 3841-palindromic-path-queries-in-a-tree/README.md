# 3841. Palindromic Path Queries in a Tree
| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, String, Divide and Conquer, Bit Manipulation, Tree, Depth-First Search, Binary Indexed Tree, Segment Tree |
| Date | 2026-10-29 |
| LeetCode Link | https://leetcode.com/problems/palindromic-path-queries-in-a-tree/ |

## Intuition & Approach
1. **Parity mask for a character multiset**  
   - For a set of lowercase letters, whether it can be rearranged into a palindrome depends only on the parity (odd/even) of each character’s count.  
   - Represent the parity as a 26‑bit integer `mask` where bit *k* is `1` iff the character `'a'+k` occurs an odd number of times.  
   - A multiset forms a palindrome **iff** `mask` has ≤ 1 bits set, i.e. `mask == 0` or `mask & (mask‑1) == 0`.

2. **Path query becomes XOR of masks**  
   - The XOR of two parity masks yields the parity of the combined multiset because odd⊕odd = even, odd⊕even = odd.  
   - Therefore the mask of the characters on the unique tree path `u → v` equals the XOR of the masks of all nodes on that path.

3. **Dynamic updates**  
   - An `update u c` operation changes the character at a single node. The mask of that node becomes `1 << (c‑'a')`.  
   - We need a data structure supporting **point update** and **path XOR query** on a static tree.

4. **Heavy‑Light Decomposition (HLD)**  
   - HLD linearises the tree into an array where any root‑to‑node or node‑to‑node path can be expressed as O(log n) contiguous segments.  
   - For each node we store its position `pos[node]` in the base array and the head of its heavy chain.  

5. **Segment tree over the base array**  
   - Leaf `pos[node]` holds the current mask of that node.  
   - Internal nodes store the XOR of their children, enabling range XOR queries in O(log n).  
   - Point update: replace leaf value and recompute ancestors – O(log n).

6. **Answering a query**  
   - While `head[u] != head[v]`, repeatedly lift the deeper head and XOR the segment `[pos[head], pos[node]]`.  
   - When both nodes share a head, query the final segment `[min(pos[u], pos[v]), max(pos[u], pos[v])]`.  
   - After obtaining the total mask, test the palindrome condition with `mask & (mask‑1) == 0`.

7. **Why naïve methods fail**  
   - Recomputing the entire path each time would be O(n) per query → 2.5 × 10⁹ operations in worst case.  
   - Storing full frequency vectors per node would use O(26 · n) memory and still require O(log n) merges per query; the bitmask reduces both time and space drastically.

## Complexity Analysis
- **Preprocessing (DFS + HLD + segment tree build):** `O(n)` time, `O(n)` memory.  
- **Update operation:** `O(log n)` time for a point update in the segment tree, `O(1)` additional work.  
- **Query operation:** Each ascent reduces the depth of one node to the parent of its chain head, at most `O(log n)` segments → `O(log n)` time.  
- **Overall:** `O((n + q) log n)` time, `O(n)` auxiliary space (adjacency list, HLD arrays, segment tree).