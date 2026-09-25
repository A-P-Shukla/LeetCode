from typing import List, Set

class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        """
        Evaluate the expression according to the grammar and return a sorted list
        of distinct words.
        """
        self.s = expression
        self.n = len(expression)
        self.idx = 0
        result = self._parse_concat()
        return sorted(result)

    def _parse_concat(self) -> Set[str]:
        """Parse a concatenation sequence until ',' or '}'."""
        cur = {""}                     # start with empty string
        while self.idx < self.n and self.s[self.idx] not in ('}', ','):
            if self.s[self.idx] == '{':
                self.idx += 1          # skip '{'
                nxt = self._parse_set()
                self.idx += 1          # skip '}'
            else:
                nxt = {self.s[self.idx]}
                self.idx += 1
            cur = {a + b for a in cur for b in nxt}
        return cur

    def _parse_set(self) -> Set[str]:
        """Parse a union set: { expr1, expr2, ... }."""
        total = set()
        while True:
            part = self._parse_concat()
            total.update(part)          # union
            if self.idx >= self.n or self.s[self.idx] == '}':
                break
            # current char must be ','
            self.idx += 1               # skip ','
        return total