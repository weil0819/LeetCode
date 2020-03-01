/*
962. Maximum Width Ramp -- Medium
https://leetcode.com/contest/weekly-contest-116/problems/maximum-width-ramp/

Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  
The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
 

Note:

2 <= A.length <= 50000
0 <= A[i] <= 50000

*/

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int N = A.size();
        if(N < 2) return 0;
        int res = 0;        // result value
        stack<int> S;       // decreasing order
        for(int i = 0; i < N; i++) {
            if(S.empty() || A[S.top()] > A[i]) S.push(i);
        }
        
        for(int i = N-1; i > res; i--) {    // early stop
            while(!S.empty() && A[S.top()] <= A[i]) {
                res = max(res, i-S.top());
                S.pop();                    // decide next top less than A[i]
            }
        }
        return res;
    }
};