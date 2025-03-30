/* 
* Problem Statement:
* A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/

/*
 * Solution: “The array isn't sorted, but we can use binary search because the direction of the slope gives us a guarantee of where a peak must lie. If nums[mid] > nums[mid + 1], a peak exists on the left side. Otherwise, it must be on the right. This gives us a guaranteed O(log n) solution.” 
 * This Version is made to handle duplicates and a potential flat slope, worst case is a flat scan of O(n)*
 */


#include <stdbool.h>



int findPeak(int* nums, int left, int right, int numsSize) {
    if (left > right) return -1;

    int mid = left + ((right - left)/2); /* avoid overflow*/

    bool leftOk = (mid == 0 || nums[mid] > nums[mid -1]);
    bool rightOk = (mid == numsSize -1 || nums[mid] > nums[mid+1]);

    if(leftOk && rightOk) return mid;

    int leftRes = findPeak(nums, left, mid -1, numsSize);
    if(leftRes != -1) return leftRes;

    return findPeak(nums, mid+1, right, numsSize); /*technically rightRes*/

}

int findPeakElement(int* nums, int numsSize){
    return findPeak(nums, 0, numsSize -1, numsSize);
}


        
