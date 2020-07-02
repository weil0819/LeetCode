/*
Power of Three

@date: July 2, 2020

Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?

*/

class Solution {
public:
    // Find the max integer who is power of 3
    // if it is also dividable by n, n should be power of 3
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        // 3^k = max3power
        // k = log_3(max3power) ~ log_3(INT_MAX) = log(INT_MAX) / log3
        int max3power = (int)pow(3, (int)(log(INT_MAX)/log(3)));
        return max3power % n == 0;
    }
};
