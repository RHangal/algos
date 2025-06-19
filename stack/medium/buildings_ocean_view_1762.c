/* 
* Problem Statement:
* There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order. 

Example 1:

Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
Example 2:

Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.
Example 3:

Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.
 

Constraints:

1 <= heights.length <= 105
1 <= heights[i] <= 109

*/

/*
 * Solution: We can scan the list from right to left keeping track of the Max value iterated on and if current val > Maxval, update MaxVal and add current val to the result
 * Reverse the resulting array and return it
 * Time Complexity O(n)
 * Space Complexity O(n)
 * 
 */

#include <stdlib.h>

int* findBuildings(int* heights, int heightsSize, int* returnSize) {
    int* result = malloc(heightsSize * sizeof(int));

    *returnSize = 0;
    int maxC = 0;

    for(int i = heightsSize -1; i >= 0; i--) {
        if(heights[i] > maxC) {
            result[(*returnSize)++] = i;
            maxC = heights[i];
        }
    }

    for(int i = 0; i < *returnSize/2; i++) {
        int temp = result[i];
        result[i] = result[*returnSize - 1 - i];
        result[*returnSize - 1 - i] = temp;
    }

    return result;
}
