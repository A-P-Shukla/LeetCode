# 3331. Find Subtree Sizes After Changes
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | Array, Hash Table, String, Tree, Depth-First Search |
| Date | 2026-11-21 |
| LeetCode Link | https://leetcode.com/problems/find-subtree-sizes-after-changes/ |

## Intuition & Approach
The re‑parenting rule is **simultaneous** and depends only on the *original* ancestry.  
For every node `x (≥1)` we need the **closest** ancestor `y` such that `s[x] == s[y]`.  
If such `y` exists we replace `parent[x]` by `y`; otherwise `parent[x]` stays unchanged.  
After all replacements the tree is still rooted at `0` because each new parent is an
ancestor of the original node, guaranteeing a directed acyclic structure.

The problem therefore splits into two independent passes:

1. **Locate the nearest same‑character ancestor for every node**  
   Perform a DFS from the root on the *original* tree while maintaining, for each
   character `c`, a stack of nodes on the current path that bear `c`.  
   When we first visit `x`, the top of `stack[s[x]]` (if any) is exactly the
   closest ancestor with the same character. Record this as `newParent[x]`.  
   Push `x` onto its character stack, recurse into children, then pop on the way
   back – classic back‑tracking.

2. **Build the final tree and compute subtree sizes**  
   Using the `newParent` array, re‑create adjacency lists, then run a second
   post‑order DFS to accumulate subtree sizes: `size[u] = 1 + Σ size[child]`.

Both passes are linear, use only `O(n)` auxiliary structures, and avoid any
recursive depth issues by employing an explicit stack.

Why not naive approaches?  
- Re‑parenting nodes one‑by‑one while updating ancestors would corrupt the
  original ancestry for later nodes, violating the “simultaneous” requirement.  
- Searching upwards for each node independently would be `O(n²)` in the worst
  case (a line tree). The stack‑per‑character technique supplies the answer in
  `O(1)` per node.

## Complexity Analysis
- **Time:** `O(n)` – one DFS to discover new parents, another DFS to compute
  subtree sizes; each edge is visited a constant number of times.
- **Space:** `O(n)` – adjacency lists for the original and final trees,
  the `newParent` array, and 26 character stacks whose total length never exceeds
  `n`.