/* 
* Problem Statement:
* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

/*
 * Solution: We use an in place two pointer approach for O(1) space complexity but we can also build a clean string and use a two pointer approach after for O(n) space. Both have O(n) time complexity
 *
 */

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isPalindrome(char* s) {
    int len = strlen(s);
    char* cleaned = malloc(len +1);
    int j = 0, i;


    for(i = 0; i < len; i++){
        if(isalnum(s[i])) cleaned[j++] = tolower(s[i]);
    }

    cleaned[j] = '\0';

    int left = 0, right = j-1;
    while(left < right) {
        if(cleaned[left++] != cleaned[right--]) {
            free(cleaned);
            return false;
        }
    }
    free(cleaned);
    return true;

}
