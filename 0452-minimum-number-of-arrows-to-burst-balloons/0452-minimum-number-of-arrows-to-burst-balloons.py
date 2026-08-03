class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:

        if not points:
            return []

        points.sort(key=lambda x: x[1])

        arrows = 1 
        current_arrow = points[0][1]

        for x_start, x_end in points[1:]: 
            if  x_start > current_arrow:
                arrows += 1 
                current_arrow = x_end

        return arrows 

        