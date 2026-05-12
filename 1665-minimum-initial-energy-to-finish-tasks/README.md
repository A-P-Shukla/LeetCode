# 1665. Minimum Initial Energy to Finish Tasks

| Property | Value |
| --- | --- |
| Difficulty | Hard |
| Topics | Array, Greedy, Sorting |
| Date | May 12, 2026 |
| LeetCode Link | [https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/) |

## Intuition

The problem asks us to find the minimum starting energy required to complete a set of tasks in any order. Each task has an `actual` cost (energy spent) and a `minimum` requirement (energy needed to start).

The core challenge lies in determining the optimal order. Intuitively, we want to perform tasks that have a large "gap" or "buffer" between their minimum requirement and their actual cost first. Why? Because tasks with a large `minimum - actual` difference are harder to satisfy when our energy levels are already low. By tackling these tasks early—while our energy is at its highest—we can satisfy the high `minimum` requirement, and the energy remaining after spending `actual` is still likely high enough to satisfy subsequent tasks.

Mathematically, if we have two tasks $A(a_1, m_1)$ and $B(a_2, m_2)$, and we perform $A$ then $B$, the energy required is $\max(m_1, a_1 + m_2)$. If we perform $B$ then $A$, the energy required is $\max(m_2, a_2 + m_1)$. 
To minimize the required energy, we compare the "bottlenecks": $a_1 + m_2$ vs $a_2 + m_1$.
By rearranging, $a_1 + m_2 < a_2 + m_1$ is equivalent to $m_2 - a_2 < m_1 - a_1$.
This confirms that tasks with a **larger difference** $(minimum - actual)$ should be completed **first**.

## Complexity Analysis

- **Time Complexity:** $O(N \log N)$, where $N$ is the number of tasks. This is dominated by the sorting step. The subsequent pass through the array takes $O(N)$.
- **Space Complexity:** $O(1)$ or $O(N)$ depending on the sorting implementation of the language (C++ `std::sort` is usually $O(\log N)$ auxiliary space, while Python's `sort` is $O(N)$).