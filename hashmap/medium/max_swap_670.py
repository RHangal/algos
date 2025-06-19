You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.

class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = list(str(num))
        last = {int(d): i for i,d in enumerate(digits) }

        for i, d in enumerate(digits):
            for bigger in range(9,int(d),-1):
                if last.get(bigger,-1) > i:

                    digits[i], digits[last[bigger]] = digits[last[bigger]], digits[i]
                    return int(''.join(digits))
        return num

