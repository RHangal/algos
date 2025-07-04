Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        stack = []

        intervals.sort()

        stack.append(intervals[0])

        for i in range(1,len(intervals)):
            if intervals[i][0] <= stack[-1][1]:
                stack[-1][1] = max(intervals[i][1], stack[-1][1])
            else:
                stack.append(intervals[i])

        return stack
