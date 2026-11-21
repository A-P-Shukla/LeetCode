from typing import List

class Solution:
    def findSubtreeSizesAfterChanges(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        children = [[] for _ in range(n)]
        for i in range(1, n):
            children[parent[i]].append(i)

        # ---------- Step 1: compute new parents ----------
        new_parent = parent[:]                     # default = old parent
        char_stack: List[List[int]] = [[] for _ in range(26)]

        # iterative DFS: (node, state) where state 0 = pre, 1 = post
        stack: List[tuple[int, int]] = [(0, 0)]
        while stack:
            u, state = stack.pop()
            if state == 0:                         # pre‑visit
                c = ord(s[u]) - ord('a')
                if u != 0 and char_stack[c]:
                    new_parent[u] = char_stack[c][-1]   # closest same‑char ancestor
                char_stack[c].append(u)

                stack.append((u, 1))               # post‑visit marker
                for v in children[u][::-1]:        # push children (order irrelevant)
                    stack.append((v, 0))
            else:                                  # post‑visit
                c = ord(s[u]) - ord('a')
                char_stack[c].pop()

        # ---------- Step 2: build final adjacency ----------
        final_children = [[] for _ in range(n)]
        for i in range(1, n):
            final_children[new_parent[i]].append(i)

        # ---------- Step 3: subtree sizes ----------
        size = [1] * n
        stack = [(0, 0)]                           # (node, state)
        while stack:
            u, state = stack.pop()
            if state == 0:
                stack.append((u, 1))
                for v in final_children[u][::-1]:
                    stack.append((v, 0))
            else:
                for v in final_children[u]:
                    size[u] += size[v]
        return size