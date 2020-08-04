/*
Power of Four

@date: Aug 4, 2020

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    // Property-1: If num&(num-1), num is power of 2
    // Property-2: If (num-1) % 3 == 0 and num&(num-1), num is power of 4
    bool isPowerOfFour(int num) {
        return (num > 0) && (num & (num-1)) == 0 && (num-1) % 3 == 0;
    }
};
