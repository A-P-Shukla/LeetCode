# 3970. Shortest Path With At Most K Consecutive Identical Characters
| Property | Value |
| --- | --- |
| Difficulty | Medium |
| Topics | String, Graph Theory, Heap (Priority Queue), Shortest Path |
| Date | 2026-10-30 |
| LeetCode Link | https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/ |

## Intuition & Approach
The ordinary shortest‑path problem (Dijkstra) ignores the string label constraint.  
The constraint only cares about **how many identical characters have appeared consecutively** at the current position.  
When we move from node `u` to node `v` we can compute the new consecutive count:

* if `labels[v] == labels[u]` → `run = previous_run + 1`
* else → `run = 1`

The path is valid only while `run ≤ k`.  
Thus the decision process depends on **both** the graph node and the current run length.  
We turn the original graph into an *augmented state graph*:

```
state = (node, run)   where 1 ≤ run ≤ k
```

From a state `(u, run_u)` we can traverse every outgoing edge `(u → v, w)`:

```
run_v = (labels[v] == labels[u]) ? run_u + 1 : 1
if run_v ≤ k   →   edge to state (v, run_v) with cost w
```

The augmented graph has at most `n * k` vertices (`n ≤ 5·10⁴`, `k ≤ 50` → ≤ 2.5·10⁶) and each original edge is examined for every reachable `run` of its source, leading to at most `m * k` relaxations (`m ≤ 5·10⁴`). This size is easily handled by Dijkstra with a binary heap.

The answer is the minimum distance among all states `(n‑1, run)`.

### Why naïve approaches fail
* **Plain Dijkstra on original nodes** ignores the run length and may accept illegal paths.
* **BFS/DP on label runs only** cannot guarantee minimal total weight because edge weights vary.
* **Enumerating all paths** is exponential; the state‑augmented Dijkstra provides optimality in polynomial time.

## Complexity Analysis
* **Time:** `O((n·k + m·k) log (n·k))` – each reachable state is extracted once from the heap and each outgoing edge is relaxed at most `k` times.
* **Space:** `O(n·k)` for distance table and the priority queue.

---