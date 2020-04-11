/*
Happy Number
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
public:
    // Using hash set to store the square sum until meeting loop or equal to 1
    // if loop, return false;
    // if 1, return true
    bool isHappy(int n) {
        unordered_set<int> help;
        while(help.find(n) == help.end()) {
            help.insert(n);
            int tmp = squareSum(n);
            if(tmp == 1) return true;
            else n = tmp;
        }
        return false;
    }
private:
    int squareSum(int n) {
        int res = 0;
        while(n) {
            int tmp = n % 10;   // 9
            n /= 10;            // 1  
            res += tmp * tmp;
        }
        return res;
    }
};

