/*
Ugly Number II

@date: July 4, 2020

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

class Solution {
public:
    // Property: next ugly = previous ugly * 2/3/5
    // dp[i] demotes the i-th ugly number
    // dp[i] = min(x*2,y*3,z*5) where x,y,z is one of elements in dp[j], j < i
    // O(n) time + O(n) space
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int x = 1, y = 1, z = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[x]*2, min(dp[y]*3, dp[z]*5));
            if(dp[i] == dp[x]*2) x++;
            if(dp[i] == dp[y]*3) y++;
            if(dp[i] == dp[z]*5) z++;
        }
        return dp[n];
    }
};

