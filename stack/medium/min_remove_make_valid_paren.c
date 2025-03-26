/* 
* Problem Statement:
* Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string. 
*/

/*
 * Solution: We use a stack with two pass marking invalid with #
 * Result is O(n) time/space complexity
 *
 */



#include <string.h>
#include <stdlib.h>

char* minRemoveToMakeValid(char* s) {
    int len = strlen(s);
    int* stack = calloc(len, sizeof(int));
    int top = -1;
    int i = 0;
    int j = 0;
    char* s_out = calloc(len+1, sizeof(char));

    for(i; i<len; i++) {
        if(s[i] == '(') {
            stack[++top] = i;
        }else if(s[i] == ')') {
            if(top>=0) {
                top--;
            } else {
                s[i] = '#';
            }
        }
    }

    for(i = top; i >= 0; i--) {
        s[stack[top--]] = '#';
    }

    for(i=0; i<len; i++) {
        if(s[i] != '#') s_out[j++] = s[i];
    }
    return s_out;
}

