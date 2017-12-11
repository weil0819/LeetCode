//===========================================================================================
// 474. Ones and Zeroes

// In the computer world, use restricted resource you have to generate maximum benefit is 
// what we always want to pursue.

// For now, suppose you are a dominator of m 0s and n 1s respectively. 
// On the other hand, there is an array with strings consisting of only 0s and 1s.

// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. 
// Each 0 and 1 can be used at most once.

// Note:
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.
// Example 1:
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4

// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, 
// which are “10,”0001”,”1”,”0”
// Example 2:
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2

// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
//===========================================================================================

bool myCompare(const string& s1, const string& s2){
	return s1.size() < s2.size();
}

class Solution {
public:
	/**
	* Idea: this is a DP problem
	* firtly, we sort the array in ascending order of length of string
	* then, we use dp[i][j] to denote the maximum number of strings can be formed with given i 0s and j 1s
	* two cases: 1) accept current string; 2) refuse current string
	* dp[i][j] = max{dp[i-zero][j-one]+1, dp[i][j]}
	* return dp[m][n]
	*
	*/
    int findMaxForm(vector<string>& strs, int m, int n) {
        sort(strs.begin(), strs.end(), myCompare);
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < strs.size(); i++){
        	int zero = 0, one = 0;
        	for(int j = 0; j < strs[i].size(); j++){
        		if(strs[i][j] == '0'){
        			zero++;
        		}else{
        			one++;
        		}
        	}
        	// DP
        	for(int p = m; p >= zero; p--){
        		for(int q = n; q >= one; q--){
        			dp[p][q] = max(dp[p][q], dp[p-zero][q-one]+1);
        		}
        	}
        }
        return dp[m][n];
    }
};

