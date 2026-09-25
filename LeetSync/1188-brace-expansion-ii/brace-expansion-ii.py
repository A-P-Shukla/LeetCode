class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        self.s = expression
        self.n = len(expression)
        self.idx = 0
        result = self._parse_concat()
        return sorted(result)

    def _parse_concat(self) -> Set[str]:
        cur = {""}                     
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
        total = set()
        while True:
            part = self._parse_concat()
            total.update(part)          
            if self.idx >= self.n or self.s[self.idx] == '}':
                break
            self.idx += 1               
        return total