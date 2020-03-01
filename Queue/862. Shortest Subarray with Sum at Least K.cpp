/*

862. Shortest Subarray with Sum at Least K -- Hard
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9

*/

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size();
        if(N == 0) return -1;
        vector<int> B(N+1, 0);
        for(int i = 0; i < N; i++) B[i+1] = B[i] + A[i];
        deque<int> DQ;
        int res = N+1;
        for(int i = 0; i <= N; i++) {
            while(!DQ.empty() && B[i]-B[DQ.front()] >= K) {
                res = min(res, i-DQ.front());
                DQ.pop_front();
            }
            // Hope min(y-x), where x=DQ.front(), y = min(i,DQ.back())
            while(!DQ.empty() && B[i] <= B[DQ.back()]) {
                DQ.pop_back();
            }
            DQ.push_back(i);
        }
        
        // corner case: res = N+1
        return res < N+1 ? res : -1;
    }
};
