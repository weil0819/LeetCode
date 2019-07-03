//===========================================================================================
// 62. Unique Paths

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?
// Note: m and n will below at most 100.
//===========================================================================================

// c++
class Solution {
public:
	/**
	* Idea: This is a dynamic programming problem
	* we use dp[i][j] to denote the number of paths from (0, 0) to (i, j)
	* In initial, we have dp[i][0]=1 or dp[0][j]=1, dp[i][j] = dp[i-1][j] + dp[i][j-1]
	* and return dp[m-1][n-1]
	* 
	*/
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++){
        	for(int j = 1; j < n; j++){
        		dp[i][j] = dp[i-1][j] + dp[i][j-1];
        	}
        }
        return dp[m-1][n-1];
    }
};


// java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int i = 0; i < m; i++){
        	dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
        	dp[0][j] = 1;
        }
        for(int i = 1; i < m; i++){
        	for(int j = 1; j < n; j++){
        		dp[i][j] = dp[i-1][j] + dp[i][j-1];
        	}
        }
        return dp[m-1][n-1];
    }
}


