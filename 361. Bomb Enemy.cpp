/*

361. Bomb Enemy -- Medium
http://www.leetfree.com/problems/bomb-enemy.html

Given a 2D grid, each cell is either a wall 'Y', an enemy 'X' or empty '0' (the number zero), 
return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from 
the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:

For the given grid

0 X 0 0
X 0 Y X
0 X 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)

*/

/*
投放一颗炸弹，能炸掉一行和一列的敌人，但是不能穿墙
求投放炸弹的位置，使得炸掉尽量多的敌人
*/
class Solution {  
public:  
	/*
	对于每一行来说, 我们可以在第0列或者当前位置前一列为墙的时候从当前列开始往右搜索直到撞到墙. 
	对于每一列来说, 可以在第0行的时候或者在当前行前一行为墙的时候从当前行往下搜索, 直到碰到墙为止. 
	这样就可以一次计算出一行直到碰到墙之前有几个敌人, 一列在没有碰到墙之前有几个敌人. 
	直到当某个某位之前位置墙的时候才会重新计算. 
	*/
    int maxKilledEnemies(vector<vector<char>>& grid) {  
        if(grid.size()==0) return 0;
        int row = grid.size(), col = grid[0].size(), rowHits, colHits[col], ans =0;
        for(int i = 0; i < row; i++)
        {
            for(int j =0; j < col; j++)
            {
                if(!i || grid[i-1][j]=='W')
                {
                    colHits[j] = 0;
                    for(int k = i; k < row && grid[k][j]!='W'; k++)
                        colHits[j] += grid[k][j]=='E';
                }
                if(!j || grid[i][j-1]=='W')
                {
                    rowHits = 0;
                    for(int k = j; k < col && grid[i][k]!='W'; k++)
                        rowHits += grid[i][k] == 'E';
                }
                if(grid[i][j] == '0')
                    ans = max(ans, colHits[j] + rowHits);
            }
        }
        return ans; 
    }  
};