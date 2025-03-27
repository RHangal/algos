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
 * Solution: Recursive QuickSelect Algorithm that recurses on the side that has K
 *
 */

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quickSelect(nums, k):
            pivot = random.choice(nums)
            left, mid, right = [], [], []

            for num in nums:
                if num < pivot:
                    right.append(num)
                elif num > pivot:
                    left.append(num)
                else:
                    mid.append(num)

            if k <= len(left):
                return quickSelect(left, k)
            elif len(left) + len(mid) < k:
                return quickSelect(right, k - len(left) - len(mid))
            else:
                return pivot

        return quickSelect(nums, k)


