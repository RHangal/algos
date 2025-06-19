Given a string s which represents an expression, evaluate this expression and return its value. 

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



class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        operand = '+'
        num = 0
        s+= "+"

        for c in s:
            if c.isdigit():
                num = (num*10) + int(c)
            elif not c.isdigit() and c != ' ':
                if operand == '+':
                    stack.append(num)
                elif operand == '-':
                    stack.append(-num)
                elif operand == '*':
                    stack[-1]*= num
                elif operand == '/':
                    stack[-1]= int(stack[-1] / num)
                num = 0
                operand = c

        return sum(stack)
        
