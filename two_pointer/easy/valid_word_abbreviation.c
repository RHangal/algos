/* 
* Problem Statement:
* A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
The following are not valid abbreviations:

"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)
Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string. 
*/

/*
 * Solution: Two Pointer approach moving through the string and the abbreviation
 *
 */

#include <stdbool.h>
#include <string.h>

bool validWordAbbreviation(char* word, char* abbr) {
    int i=0, j=0;

    while(word[i] && abbr[j]) {
        if(isalpha(abbr[j])) {
            if(word[i] != abbr[j]) return false;
            i++;
            j++;
        } else {
            if(abbr[j] == '0') return false;

            int num = 0;

            while(abbr[j] && isdigit(abbr[j])) {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            i+= num;
            if(i > strlen(word)) return false;
        }
    }

    return word[i] == '\0' && abbr[j] == '\0';
}
