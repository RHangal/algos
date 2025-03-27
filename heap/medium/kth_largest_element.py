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
 * Solution: Implement Priority Queue (min Heap)
 *
 */

import heapq

class solution:
    def findKthLargest(self, nums, k):
        min_heap = []

        for num in nums:
            heapq.heappush(min_heap,num)
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        return min_heap[0]
