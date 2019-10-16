/*

1215. Stepping Numbers -- Medium
https://leetcode.com/problems/stepping-numbers/

A Stepping Number is an integer such that all of its adjacent digits have an absolute difference of exactly 1. 
For example, 321 is a Stepping Number while 421 is not.

Given two integers low and high, find and return a sorted list of all the Stepping Numbers in the range [low, high] inclusive.

 

Example 1:

Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
 

Constraints:

0 <= low <= high <= 2 * 10^9

*/

class Solution {
public:
    // Method-I: iterative solution
    /*
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        if(low > high) return res;
        
        queue<long> Q;        
        for(long i = 1; i < 10; i++) Q.push(i);
        if(low == 0) res.push_back(0);
        
        while(!Q.empty()) {
            long q = Q.front();
            Q.pop();
            if(q < high) {
                int last = q % 10;
                long prev = q * 10 + last - 1;
                long next = q * 10 + last + 1;
                if(last != 0) Q.push(prev);
                if(last != 9) Q.push(next);                
            }
            if(q >= low && q <= high) res.push_back((int)q);
        }
        
        return res;
    }
    */
    
    // Method-II: recursive solution
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        if(low > high) return res;
        
        if(low == 0) res.push_back(0);
        
        for(long i = 1; i <= 9; i++) {
            helper(low, high, i, res);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
private:
    void helper(int low, int high, long cur, vector<int>& res) {
        if(cur > high) return;
        if(cur >= low) res.push_back(cur);
        
        int last = cur % 10;
        long prev = cur * 10 + last - 1;
        long next = cur * 10 + last + 1;
        
        if(last != 0) helper(low, high, prev, res);
        if(last != 9) helper(low, high, next, res);    
    }
    
};
