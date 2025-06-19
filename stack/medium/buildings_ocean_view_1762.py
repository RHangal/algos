There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        maxval = 0
        n = len(heights) - 1
        res = []

        for i in range(n,-1,-1):
            if heights[i]>maxval:
                res.append(i)
                maxval = heights[i]

        return res[::-1]
