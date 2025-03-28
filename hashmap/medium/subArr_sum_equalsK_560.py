/* 
* Problem Statement:
* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107 
*/

/*
 * Solution: We can use a hashmap to store the prefix sum
 * “This is a linear time solution using prefix sums and a custom hashmap with quadratic probing to store the frequency of running sums. For each element, I check whether (current prefix sum - k) has been seen before — if so, it means there’s a subarray that sums to k. All operations are O(1) on average thanks to open addressing, giving the full algorithm a time and space complexity of O(n).”
 *
 */

class solution:
    def subarraySum(self, nums: List[int], k:int) -> int:
        hashmap{0:1}
        count = prefixSum = 0

        for num in nums:
            prefixSum+=num
            count+= hashmap.get(prefixSum - k, 0)
            hashmap[prefixSum] = hashmap.get(prefixSum, 0) + 1

        return count
