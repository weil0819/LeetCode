/*

174. Dungeon Game -- Hard
https://leetcode.com/problems/dungeon-game/

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. 
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 
if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters 
and the bottom-right room where the princess is imprisoned.

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int N = dungeon.size();
        int M = dungeon[0].size();
        
        // hp[i][j] denotes the minimum health points required
        vector<vector<int> > hp(N+1, vector<int>(M+1,INT_MAX));
        hp[N][M-1] = 1;
        hp[N-1][M] = 1;
        
        for(int i = N-1; i >= 0; i--) {
            for(int j = M-1; j >= 0; j--) {
                // current need is the minimum one
                int need = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                // current need should be not less than 0, at least 1
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};


