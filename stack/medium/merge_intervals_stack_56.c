/* 
* Problem Statement:
* 
Topics
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104 
*/

/*
 * Solution: We need to sort the array then iterate over and merge any values where the start is < intervals[i-1][1]
 * Solution has time complexity of O(n log n) and space of O(n)
 *
 */


#include <stdlib.h>

#define MAX(a,b) a > b ? a : b

int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSize) {
    if(intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSize = NULL;
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** stack = malloc(intervalsSize * sizeof(int*));
    stack[0] = intervals[0];
    int top = 0;
    for(int i = 1; i < intervalsSize; i++) {
        if(intervals[i][0] <= stack[top][1]) {
            stack[top][1] = MAX(intervals[i][1], stack[top][1]);
            } else {
                stack[++top] = intervals[i];
            }
    }

    *returnSize = top + 1;
    *returnColumnSize = malloc((*returnSize) * sizeof(int));
    for(int i = 0; i < *returnSize; i++) {
        (*returnColumnSize)[i] = 2;
    }
    return stack;


  }

