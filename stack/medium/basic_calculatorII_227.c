/* 
* Problem Statement:
* Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer. 
*/

/*
 * Solution: We can use a stack and pop the value when we see a * or / and push either the positive or negative value when we see a + or a - operator
 * finally we sum the stack
 *
 */
#include <ctype.h>

int calculate(char* s){
    int stack[300000];
    int top = -1;
    int num = 0;
    char operation = '+';

    while(*s) {
        char c = *s;

        if(isdigit(c)){
            num = (num * 10) + (c - '0');
        }

        if((!isdigit(c) && c != ' ') || *(s+1) == '\0'){
            if(operation == '+') {
                stack[++top] = num;
            } else if(operation == '-') {
                stack[++top] = -num;
            } else if(operation == '*') {
                stack[top] *= num;
            } else if(operation == '/') {
                stack[top] /= num;
            }

            num = 0;
            operation = c;
        }
        *s++;
    }

    int res = 0;

    for(int i = 0; i <=top; i++) {
        res += stack[i];
    }

    return res;
}




