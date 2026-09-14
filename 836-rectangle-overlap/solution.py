class Solution:
    def isRectangleOverlap(self, rec1: list[int], rec2: list[int]) -> bool:
        # rec = [x1, y1, x2, y2]
        # Check if the 1D projections overlap on both the X-axis and Y-axis
        x_overlap = rec1[0] < rec2[2] and rec2[0] < rec1[2]
        y_overlap = rec1[1] < rec2[3] and rec2[1] < rec1[3]
        
        return x_overlap and y_overlap