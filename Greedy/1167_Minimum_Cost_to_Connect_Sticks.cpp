/*
1167. Minimum Cost to Connect Sticks -- Medium
https://leetcode.com/problems/minimum-cost-to-connect-sticks/ 

@date: Sun 1 Mar. 2020

You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

 
Example 1:

Input: sticks = [2,4,3]
Output: 14
Example 2:

Input: sticks = [1,8,3,5]
Output: 30
 

Constraints:

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4

*/

class Solution {
public:
    // stick two sticks whose lengths are smallest
    // use priority_queue 
    int connectSticks(vector<int>& sticks) {
        int N = sticks.size();
        if(N <= 1) return 0;
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> PQ(sticks.begin(), sticks.end());
        while(PQ.size() > 1) {
            int A = PQ.top();       // the smallest
            PQ.pop();
            int B = PQ.top();       // the second smallest
            PQ.pop();
            res += (A+B);
            PQ.push(A+B);
        }
        return res;
    }
};

