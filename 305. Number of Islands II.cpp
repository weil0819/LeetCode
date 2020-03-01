/*

305. Number of Islands II -- Hard
http://www.leetfree.com/problems/number-of-islands-ii.html


A 2d grid map of m rows and n columns is initially filled with water. 
We may perform an addLand operation which turns the water at position (row, col) into a land. 
Given a list of positions to operate, count the number of islands after each addLand operation. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

*/

/*
不断将grid中某个位置变为land
求island的个数
*/
class Solution {  
public:  
	/*
	union-find问题：
	为每一个位置初始化一个父结点, 因为是一个二维数组, 比较方便的方式是二维转化为一维. 
	也就是每一个位置的父结点设置(x*n+y), 其中(x, y)为其位置坐标. 
	然后每次插入一个新元素的时候查上下左右地图是不是有相邻的陆地, 
	当然在此之前还需要建立一张二维的地图用来维护地图的状态. 
	这样如果新添加的一个点的时候默认小岛数量增加1, 但是如果这个新添加的陆地有相邻的陆地, 
	就将其合并成一块陆地, 并且小岛数量-1. 因为他有上下左右四个方向, 
	所以有可能当前点连接了之前并不相连的小岛, 在当前结点碰到第一个相邻的陆地的时候, 
	他被并入了那块陆地, 如果之后他碰到了另一个小岛和他属于不同的小岛, 则还要合并两个小岛, 又会让小岛数量-1. 
	*/
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {  
        vector<vector<int>> mp(m, vector<int>(n, 0));		// mp[i][j]=1 is visited
        vector<int> result;
        int num = 0;
        vector<int> par(m*n);								// transform two dimension into one dimension
        for(int i = 0; i < m*n; i++) par[i] = i;			// 
        for(auto val: positions)
        {
            vector<pair<int, int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
            for(auto val2: dir)
            {
                int x =val.first, y =val.second;			// addLand(x, y)
                int px =x+val2.first, py =y+val2.second;	// (px,py) is neighbor of (x,y)
                if(px<0 || px>=m || py<0 || py>=n || !mp[px][py]) continue;

                int par1 = x*n + y, par2 = px*n + py;		// get index of (x,y) and (px,py) in "par"

                while(par[par1] != par1) {					// 
                	par[par1] = par[par[par1]]; 
                	par1 = par[par1];
                }

                while(par[par2] != par2) {
                	par[par2] = par[par[par2]]; 
                	par2 = par[par2];
                }

                if(par1 != par2) {							// par1 and par2 will be merged as one island
                	par[par2] = par1; 						// par2's parent will be same as that of par1
                	num--;
                }
            }
            mp[val.first][val.second] = 1;
            result.push_back(++num);
        }
        return result;
    }  
};  

