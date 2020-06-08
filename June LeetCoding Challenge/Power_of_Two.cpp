/*
Power of Two

@date: June 8, 2020

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

*/

class Solution {
public:
    // Bit Manipulation
    // If an integer is power of 2, its binary format should be only one 1.
    // For example, 16=00010000, however, 15=00001111
    // 16&(16-1) = 00000000 = 0
    // ==> n&(n-1) = 0
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int temp = n&(n-1);
        return temp == 0;
    }
};
