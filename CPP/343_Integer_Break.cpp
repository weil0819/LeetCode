//===========================================================================================
// 343. Integer Break

// Given a positive integer n, break it into the sum of at least two positive integers 
// and maximize the product of those integers. 
// Return the maximum product you can get.

// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

// Note: You may assume that n is not less than 2 and not larger than 58.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a dynamic programming problem, 
	* dp[2]=1, dp[3]=max{max{dp[2],2}*max{dp[1],1}}
	* dp[4]=max{max{dp[3],3}*max{dp[1],1}, max{dp[2],2}*max{dp[2],2}}
	* dp[5]=max{max{dp[4],4}*max{dp[1],1}, max{dp[3],3}*max{dp[2],2}}
	* dp[6]=max{max{dp[5],5}*max{dp[1],1}, max{dp[4],4}*max{dp[2],2}, max{dp[3],3}*max{dp[3],3}}
	* 
	*/
    int integerBreak(int n) {    	
        vector<int> dp(n+1, 1);
        for(int i = 3; i <= n; i++){
        	for(int j = 1; j <= (i/2); j++){
        		dp[i] = max(dp[i], max(dp[j], j)*max(dp[i-j], i-j));
        	}
        }
        return dp[n];
    }
};