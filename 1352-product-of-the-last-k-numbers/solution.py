class ProductOfNumbers:
    def __init__(self) -> None:
        # sentinel product for empty prefix
        self.pref: list[int] = [1]

    def add(self, num: int) -> None:
        if num == 0:
            # reset on zero; any product crossing this zero is zero
            self.pref = [1]
        else:
            # append product of previous prefix and current number
            self.pref.append(self.pref[-1] * num)

    def getProduct(self, k: int) -> int:
        # If k exceeds length of current non‑zero segment, zero is inside window
        if k >= len(self.pref):
            return 0
        numerator = self.pref[-1]
        denominator = self.pref[-k - 1]
        return numerator // denominator