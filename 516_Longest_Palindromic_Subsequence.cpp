//===========================================================================================
// 516. Longest Palindromic Subsequence

// Given a string s, find the longest palindromic subsequence's length in s. 
// You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a dynamic programing problem
	* we use dp[i][j] to donate the longest palindromic subsequence between i and j
	* if s[i] == s[j], we have dp[i][j] = dp[i+1][j-1] + 2;
	* else we have dp[i][j] = max(dp[i+1][j], dp[i][j-1])
	* Attention: we must scan the string from tail to head
	* 
	*/
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size()-1; i >= 0; i--){					// from tail to head
        	dp[i][i] = 1;										// for single char, it must be palindromic
        	for(int j = i+1; j < s.size(); j++){
        		if(s[i] == s[j]){								// tail == head
        			dp[i][j] = dp[i+1][j-1] + 2;
        		}else{											// tail != head
        			dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        		}
        	}
        }
        return dp[0][s.size()-1];
    }
};