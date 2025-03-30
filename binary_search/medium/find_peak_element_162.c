/* 
* Problem Statement:
* A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
*/

/*
 * Solution: “The array isn't sorted, but we can use binary search because the direction of the slope gives us a guarantee of where a peak must lie. If nums[mid] > nums[mid + 1], a peak exists on the left side. Otherwise, it must be on the right. This gives us a guaranteed O(log n) solution.” *
 */




int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize -1;

    while(left < right) {
        int mid = (left + right) / 2;

        if(nums[mid] > nums[mid+1]) {right = mid;}
        else {left = mid + 1;}
    }
    return left;
}

        
