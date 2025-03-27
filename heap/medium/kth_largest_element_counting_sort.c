/* 
* Problem Statement:
* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/*
 * Solution: We use a frequency countring solution, sinc the value range is small and bounded, I create a freq array, count the occurences, and walk it backwards to find the kth largest element
 *
 */

#include <limits.h>
#include <stdlib.h>

int findKthLargest(int* nums, int numsSize, int k) {
    int max = INT_MIN;
    int min = INT_MAX;
    int i;

    for(i = 0; i < numsSize; i++) {
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }

    int* test = calloc(max-min+1, sizeof(int));

    for(i = 0; i< numsSize; i++) {
        test[nums[i]-min]++;
    }
    for(i = max-min; i>=0; i--) {
        k-=test[i];
        if(k<=0) return i + min;
    }
    return 0;
}
