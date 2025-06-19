Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        modmap = {0:-1}
        prefix_mod = 0
        for i in range(len(nums)):
            prefix_mod = (prefix_mod + nums[i]) % k

            if prefix_mod in modmap:
                if i - modmap[prefix_mod] > 1:
                    return True
            else:
                modmap[prefix_mod] = i

        return False

