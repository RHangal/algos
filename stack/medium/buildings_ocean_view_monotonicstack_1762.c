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
 * Solution: We use a monotonic stack scaning from left to right popping the stack should the current value be greater than the top of the stack
 * pop the resulting stack values and insert them into our return array
 * Time Complexity O(n)
 * Space Complexity O(n)
 * 
 */

#include <stdlib.h>

int* findBuildings(int* heights, int heightsSize, int* returnSize) {
    int* stack = malloc(heightsSize * sizeof(int));
    int top = -1;

    for(int i = 0; i < heightsSize; i++) {
        while(top >= 0 && heights[i] >= heights[stack[top]]) {
            top--;
        }
        stack[++top] = i;
    }
    
    *returnSize = top + 1;

   
    return stack; 
}
