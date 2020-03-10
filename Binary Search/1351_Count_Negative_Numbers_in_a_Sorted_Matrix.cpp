/*
1351. Count Negative Numbers in a Sorted Matrix -- Easy
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

@date: Tue 10 Mar. 2020

Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 
Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/

class Solution {
public:
    // Method-I: O(M+N) iterate from top-right or bottom-left cornor 
    /*
    int countNegatives(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        int res = 0;
        // top-right cornor        
        // int r = 0, c = N-1;
        // while(r < M) {
        //     while(c >= 0 && grid[r][c] < 0) c--;
        //     res += N-c-1;
        //     r++;
        // }
        // bottom-left cornor
        int r = M-1, c = 0;
        while(r >= 0) {
            while(c < N && grid[r][c] >= 0) c++;
            res += N-c;
            r--;
        }
        return res;
    }*/
    
    // Method-II: O(MlogN) scan each row and use binary search on that row
    int countNegatives(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        int res = 0;

        for(int i = 0; i < M; i++) {
            if(grid[i][0] < 0) {
                res += N;
                continue ;
            }
            if(grid[i][N-1] > 0) continue ;
            
            int l = 0, r = N-1;
            while(l <= r) {
                int m = l + (r-l)/2;
                if(grid[i][m] < 0) {
                    r = m-1;;
                }else {
                    l = m+1;
                }
            }
            res += N-l;
        }
        return res;
    }
    
};

