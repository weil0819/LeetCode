/*
Interval List Intersections

@date: May 23, 2020

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

class Solution {
public:
    // Like merge sort
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size(), M = B.size();
        vector<vector<int> > res;
        if(N == 0 || M == 0) return res;
        
        int i = 0, j = 0;
        while(i < N && j < M) {     // should have close interval
            if(A[i][1] < B[j][0]) i++;
            else if(A[i][0] > B[j][1]) j++;
            else {
                int start = max(A[i][0], B[j][0]);
                int end = min(A[i][1], B[j][1]);
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                res.push_back(temp); 
                if(A[i][1] < B[j][1]) i++;
                else j++;
            }
        }
        
        return res;
    }
};

