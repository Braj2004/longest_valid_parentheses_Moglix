# longest_valid_parentheses_Moglix


Longest Valid Parentheses

Overview

This project finds the length of the longest valid (well-formed) parentheses substring in a given string.

The input string contains only two characters:

( (opening parenthesis)
) (closing parenthesis)

Instead of using a stack or dynamic programming, this solution uses the Two-Pass Counting approach, which runs in linear time and uses constant extra space.

Problem Statement

Given a string containing only '(' and ')', return the length of the longest valid parentheses substring.

Example 1

Input

(()

Output

2

Explanation

The longest valid substring is:

()
Example 2

Input

)()())

Output

4

Explanation

The longest valid substring is:

()()
Example 3

Input

""

Output

0
Approach

This solution performs two scans of the string.

1. Left to Right Scan
Count the number of opening parentheses using left.
Count the number of closing parentheses using right.
Whenever left == right, a valid substring is found.
If right > left, reset both counters because the current substring cannot become valid.
2. Right to Left Scan

The first scan cannot detect cases with extra '('.

To handle those cases, scan the string from right to left.

Count ')' using right.
Count '(' using left.
Whenever left == right, update the maximum length.
If left > right, reset both counters.

By combining both scans, all valid substrings are considered.

Algorithm
Initialize left, right, and answer to 0.
Traverse the string from left to right.
Update counters based on the current character.
Update the maximum length when left == right.
Reset counters if there are more closing parentheses than opening ones.
Repeat the same process from right to left.
Return the maximum length found.
Time Complexity
O(n)

The string is traversed twice, so the overall complexity is linear.

Space Complexity
O(1)

Only a few integer variables are used.

How to Run
Compile
g++ main.cpp -o main
Execute
./main
Sample Run
Enter parentheses string: )()())

Longest Valid Parentheses Length = 4
Learning Outcome

This project helped me understand:

Two-Pass Counting technique
Parentheses matching logic
Linear-time string processing
Constant space optimization
Difference between validation problems and longest valid substring problems
Author

Brajnandan Prasad

B.Tech Computer Science & Engineering
