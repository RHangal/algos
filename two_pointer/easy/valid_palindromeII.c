/* 
* Problem Statement:
* Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

/*
 * Solution: Two pointer approach with a helper function to check offset should one mismatch occur
 *
 */

#include <string.h>
#include <stdbool.h>

bool offsetChecker(char* s, int left, int right) {
    while(left < right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char* s) {
    int left = 0, right = strlen(s) - 1;

    while(left < right) {
        if(s[left] != s[right]) {
            return offsetChecker(s, left + 1, right) || offsetChecker(s, left, right-1);
        }
        left++;
        right--;
    }
    return true;
}
