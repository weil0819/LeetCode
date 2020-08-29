/*
Edit Distance

@date: May 31, 2020

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

class Solution {
public:
    // DP problem
    // dp[i][j] is the min edit distance between word1[0:i] and word2[0:j]
    // If word1[i]==word2[j], dp[i][j] = dp[i-1][j-1]
    // Else dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<vector<int> > dp(N+1, vector<int>(M+1, 0));
        
        // We need to deal with index=0
        for(int i = 1; i <= N; i++) {
            dp[i][0] = i;
        }
        for(int j = 1; j <= M; j++) {
            dp[0][j] = j;
        }
        
        // two layer loop
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    // Case-I: Replace word1[i-1] by word2[j-1] (dp[i][j] = dp[i-1][j-1] + 1);
                    // Case-II: If word1[0:i-2] = word2[0:j-1] then delete word1[i-1] (dp[i][j] = dp[i-1][j] + 1);
                    // Case-III: If word2[0:j-2] = word1[i-1], so word1[i-1]+word2[j-1]=word2[0:j-1] then insert word2[j-1] to word1[0:i-1] (dp[i][j] = dp[i][j-1] + 1).
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;                    
                }
            }
        }  
        return dp[N][M];
    }
};
