class Robot:

    def __init__(self, width: int, height: int):
        self.w = width
        self.h = height
        # Total distance to complete one full lap
        self.p = 2 * (width - 1) + 2 * (height - 1)
        self.idx = 0
        self.moved = False

    def step(self, num: int) -> None:
        self.moved = True
        self.idx = (self.idx + num) % self.p

    def getPos(self) -> list[int]:
        idx = self.idx
        w, h = self.w, self.h
        
        if 0 <= idx < w:
            # Bottom edge
            return [idx, 0]
        elif w <= idx < w + h - 1:
            # Right edge
            return [w - 1, idx - (w - 1)]
        elif w + h - 1 <= idx < 2 * w + h - 2:
            # Top edge
            return [w - 1 - (idx - (w + h - 2)), h - 1]
        else:
            # Left edge
            return [0, h - 1 - (idx - (2 * w + h - 3))]

    def getDir(self) -> str:
        idx = self.idx
        w, h = self.w, self.h
        
        # Initial state at (0,0) is East. 
        # If we return to (0,0) after moving, the last step was Southward.
        if idx == 0:
            return "South" if self.moved else "East"
        
        # Ranges based on perimeter segments
        if 1 <= idx <= w - 1:
            return "East"
        if w <= idx <= w + h - 2:
            return "North"
        if w + h - 1 <= idx <= 2 * w + h - 3:
            return "West"
        return "South"