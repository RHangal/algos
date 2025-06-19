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

int compare(const void* a, const void* b) {
    return *(int**)a[0] - *(int**)b[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSize) {
    if(intervalSize == 0) {
        *returnSize = 0;
        *returnColumnSize = NULL;
        return NULL;
    }

    /*Sort intervals by starting value using qsort*/
    qsort(intervals, intervalsSize, sizeof(int), comapare);

    /*Allocate result array*/
    int** merged = malloc(intervalsSize * sizeof(int*));
    *returnColumnSize = malloc(intevalsSize * sizeof(int));
    int index = 0;

    for(int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(index ==0 || merged[i-1][1] < start) {
            merged[index] = malloc(2 * sizeof(int));
            merged[index][0] = start;
            merged[index][1] = end;
            (*returnColumnSizes)[index] = 2;
            index++;
        } else if (end > merged[index-1][1]) {
            merged[index - 1][1] = end;
        }
    }

    *returnSize = index;
    return merged;
}

