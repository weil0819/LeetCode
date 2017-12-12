//===========================================================================================
// 64. Minimum Path Sum

// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example 1:
// [[1,3,1],
//  [1,5,1],
//  [4,2,1]]
// Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a DP problem
	* Assuming that dp[i][j] denotes the sum of path from (0, 0) to (i, j)
	* dp[i][j] = min{dp[i-1][j], dp[i][j-1]}+grid[i][j]
	* where dp[0][j] = sum{dp[0][0]+...dp[0][j]}, dp[0][i] = sum{dp[0][0]+...dp[0][i]}
	* 
	*/
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n == 0 || m == 0){
        	return 0;
        }
        vector<vector<int> > dp(n, vector<int>(m));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
        	dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 0; j < m; j++){
        	dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < n; i++){
        	for(int j = 1; j < m; j++){
        		dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        	}
        }
        return dp[n-1][m-1];        
    }
};

