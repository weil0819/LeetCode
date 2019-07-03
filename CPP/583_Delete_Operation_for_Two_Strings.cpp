//===========================================================================================
// 583. Delete Operation for Two Strings

// Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, 
// where in each step you can delete one character in either string.

// Example 1:
// Input: "sea", "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Note:
// The length of given words won't exceed 500.
// Characters in given words can only be lower-case letters.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: This is to compute the longest common substring and the other parts will be removed step by step
	* LCS is a dynamic programming problem, we use dp[i][j] to represent the 
	* LCS of word1.substr(0, i-1) and word2.substr(0, j-1), then we have 
	* dp[i][j] = dp[i-1][j-1] +1 or max{dp[i][j-1], dp[i-1][j]}
	* Attention: array index is from 0 while dp index is from 1
	* 
	*/
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){
        		if(word1[i-1] == word2[j-1]){
        			dp[i][j] = dp[i-1][j-1] + 1;
        		}else{
        			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);        			
        		}
        	}
        }
        int res = n + m - 2*dp[n][m];
        return res;
    }
};