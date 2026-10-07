from collections import deque

class Solution:
    def is_valid(self, s: str) -> bool:
        bal = 0
        for ch in s:
            if ch == '(':
                bal += 1
            elif ch == ')':
                if bal == 0:
                    return False
                bal -= 1
        return bal == 0

    def removeInvalidParentheses(self, s: str):
        visited = set([s])
        q = deque([s])
        res = []
        found = False

        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                if self.is_valid(cur):
                    res.append(cur)
                    found = True

                if found:
                    continue  # skip generating deeper states

                for i, ch in enumerate(cur):
                    if ch not in ('(', ')'):
                        continue
                    nxt = cur[:i] + cur[i+1:]
                    if nxt not in visited:
                        visited.add(nxt)
                        q.append(nxt)

            if found:
                break

        return res if res else [""]