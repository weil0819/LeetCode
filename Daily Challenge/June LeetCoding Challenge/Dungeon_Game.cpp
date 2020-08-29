/*
Dungeon Game

@date: June 21, 2020

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

*/

class Solution {
public:
    // DP problem
    // dp[i][j] = minimum health can arrive (i, j)
    // Starting from (N-1, M-1)
    // dp[i][j] = min(dp[i-1][j], dp[i][j-1]) - dungeon[i][j]
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int N = dungeon.size();
        if(N == 0) return 0;
        int M = dungeon[0].size();
        
        vector<vector<int> > dp(N+1, vector<int>(M+1, INT_MAX));
        dp[N][M-1] = 1;       // last value should be 1
        dp[N-1][M] = 1;
        for(int i = N-1; i >= 0; i--) {
            for(int j = M-1; j >= 0; j--) {
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            }
        }
        
        return dp[0][0];
    }
};

